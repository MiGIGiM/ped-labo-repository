#include <stdlib.h>
#include <iostream>

using namespace std;

struct nodo
{
    int nFil, nCol;
    nodo *sigCol, *sigFil;
    int dato; // PERO NUESTRA HOJA LA VAMOS A MANEJAR SOLO CON DATOS ENTEROS.
};

class HojaCalc
{
private:
    int totFil; // Total de filas de la hoja electrónica.
    int totCol; // Total de columnas de la hoja electrónica.
    nodo *pHE;  // Puntero base de la hoja electrónica.

public:
    HojaCalc(int, int); // Constructor que arma la estructura básica (la escuadra).
    //void insNodo(int, int);
    void insNodo(void);
    void borraNodo(int, int);
    void imprimirHojaElec(void);
    void sumarFila(int);
    void sumarCol(int);
};

// Este constructor inicializa la estructura base de una hoja de cálculo.
HojaCalc::HojaCalc(int totFil, int totCol)
{
    nodo *nuevo, *s;
    int i;

    // Creación e inicialización del nodo base:
    pHE = new nodo;

    this->totFil = totFil;
    this->totCol = totCol;
    pHE->nFil = 0;
    pHE->nCol = 0;
    pHE->sigCol = pHE;
    pHE->sigFil = pHE;
    pHE->dato = 0;

    // Creacion de la fila base (nodos base de columnas):
    s = pHE;
    for (i = 1; i <= totCol; i++)
    {
        nuevo = new nodo;
        s->sigCol = nuevo;
        nuevo->dato = 0;
        nuevo->nCol = i;
        nuevo->nFil = 0;
        nuevo->sigFil = nuevo;
        s = s->sigCol;
    };
    nuevo->sigCol = pHE;

    // Creacion de la columna base (nodos base de filas):
    s = pHE;
    for (i = 1; i <= totFil; i++)
    {
        nuevo = new nodo;
        s->sigFil = nuevo;
        nuevo->dato = 0;
        nuevo->nFil = i;
        nuevo->nCol = 0;
        nuevo->sigCol = nuevo;
        s = s->sigFil;
    }
    nuevo->sigFil = pHE;
}

// Insertar un nodo en la hoja de cálculo:
//void HojaCalc::insNodo(int fil, int col)
void HojaCalc::insNodo(void)
{
    int fila, columna;

    cout << "Inserción de nodos en la hoja electrónica." << endl;
    cout << "Finalice introduciendo ceros:" << endl
         << endl;
    do
    {
        cout << "Fila: ";
        cin >> fila;
        cout << "Columna: ";
        cin >> columna;
        //if(fil >= 1 && fil <= totFil && col >= 1 && col <= totCol){
        if (fila >= 1 && fila <= totFil && columna >= 1 && columna <= totCol)
        {
            // Creación de un nuevo nodo:
            nodo *nuevo = new nodo;

            cout << "Entero a almacenar: ";
            cin >> nuevo->dato;
            nuevo->nFil = fila;
            nuevo->nCol = columna;

            nodo *pFil = pHE;
            nodo *pCol = pHE;
            int i;

            // Localización de la posición sobre la fila. El putero que salta sobre la fila
            // queda apuntando al nodo anterior.
            for (i = 1; i <= fila; i++) // Bajando sobe la columna base.
                pFil = pFil->sigFil;
            while ((pFil->sigCol->nCol < columna) && (pFil->sigCol->nCol != 0)) // Avanzando sobre la fila.
                pFil = pFil->sigCol;

            // Localización de la posición sobre la column. El putero que salta sobre la columna
            // queda apuntando al nodo anterior.
            for (i = 1; i <= columna; i++) // Avanzando sobre la fila base.
                pCol = pCol->sigCol;
            while ((pCol->sigFil->nFil < fila) && (pCol->sigFil->nFil != 0)) // Bajando sobre la columna.
                pCol = pCol->sigFil;

            // Enlazar el nuevo nodo a la estructura.
            // FALTA VERIFICAR SI EL NODO YA EXISTE.
            // SI ESTE FUERA EL CASO, SOLO HABRÍA QUE SUSTITUIR EL VALOR.
            nuevo->sigCol = pFil->sigCol;
            pFil->sigCol = nuevo;

            nuevo->sigFil = pCol->sigFil;
            pCol->sigFil = nuevo;
            cout << "El nodo se ha insertado" << endl
                 << endl;
        }
        else
            cout << "Hubicación no válida para nuevo dato" << endl
                 << endl;
    } while (fila != 0 || columna != 0);
}

// Eliminar un nodo de la hoja de cálculo. Se asume que el
// nodo sí existe, la función solo hace el trabajo de borrarlo.
void HojaCalc::borraNodo(int fil, int col)
{
    nodo *pFil = pHE;
    nodo *pCol = pHE;
    nodo *pBorrar = NULL; // Puntero que apuntara al nodo a a eliminar.
    int i;

    // Localización de la posición sobre la fila. El putero que salta sobre la fila
    // queda apuntando al nodo anterior.
    for (i = 1; i <= fil; i++) // Bajando sobre columna base.
        pFil = pFil->sigFil;
    while ((pFil->sigCol->nCol < col) && (pFil->sigCol->nCol != 0)) // Avanzando sobre fila.
        pFil = pFil->sigCol;

    // Localización de la posición sobre la columna. El putero que salta sobre la columna
    // queda apuntando al nodo anterior.
    for (i = 1; i <= col; i++) // Avanzando sobre fila base.
        pCol = pCol->sigCol;
    while ((pCol->sigFil->nFil < fil) && (pCol->sigFil->nFil != 0)) // Bajando sobre columna.
        pCol = pCol->sigFil;

    // Desenlazar el nodo de la estructura y borrarlo.
    pBorrar = pFil->sigCol; // FALTA VERIFICAR SI EL NODO EN REALIDAD EXISTE.
    pFil->sigCol = pFil->sigCol->sigCol;
    pCol->sigFil = pCol->sigFil->sigFil;

    // Eliminar el nodo desenlazado.
    delete pBorrar;
    cout << "El nodo ha sido borrado" << endl
         << endl;
}

// Impresión para verificar ewl estado de
// la mariz. Se imprime por filas:
void HojaCalc::imprimirHojaElec(void)
{
    cout << "Para cada nodo se muestra: fila, columna, dato." << endl;
    cout << "La hoja electrónica es:" << endl;
    nodo *s = pHE;
    //int i;

    do
    {
        do
        {
            cout << s->nFil << ',' << s->nCol << ',' << s->dato << '\t';
            s = s->sigCol;
        } while (s->nCol != 0);
        cout << endl;
        s = s->sigFil;
    } while (s->nFil != 0);
}

void HojaCalc::sumarFila(int fila)
{

    nodo *s = pHE;
    int acum = 0;

    while (s->nFil < fila)
    {
        s = s->sigFil;
    }
    do
    {
        acum += s->dato;
        s = s->sigCol;
    } while (s->nCol != 0);

    cout << "la suma de la fila es: " << acum << endl;
}



int main(void)
{
    nodo *s;
    int totFilas, totColumnas, fil, col, i;

    cout << endl;
    cout << "FUNCIONES IMPLEMENTADAS PARA ADMINISTRAR UNA HOJA DE CÁLCULO" << endl
         << endl;

    // Inicialización de la estructura base de una hoja de cálculo.
    cout << "Para inicializar la hoja de cálculo proporcione la" << endl;
    cout << "cantidad de filas y columnas que contendrá:" << endl
         << endl;
    cout << "Total de filas: ";
    cin >> totFilas;
    cout << "Total de columnas: ";
    cin >> totColumnas;

    HojaCalc hojaCalculo(totFilas, totColumnas);

    // Impresión para verificar la estructura base
    // de la hoja electrónica:
    //hojaCalculo.imprimirHojaElec();

    // Inserción de un nodo en la hoja de cálculo:
    hojaCalculo.insNodo();

    // Impresión para verificar la inserción de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();

    // Eliminación de un nodo de la hoja de cálculo.
    /* cout << "Eliminación de un nodo de la hoja de cálculo:" << endl << endl;
    cout << "Digite el número de fila y el número de columna" << endl;
    cout << "del nodo que será eliminado:" << endl;
    cout << "Fila: ";
    cin >> fil;
    cout << "Colmna: ";
    cin >> col;

    hojaCalculo.borraNodo(fil, col);

    // Impresión para verificar la eliminación de un nodo,
    // la mariz se imprime por filas:
    hojaCalculo.imprimirHojaElec();*/

    /*7*/
    int filsum = 0;
    cout << "numero de fil que desea sumar: ";
    cin >> filsum;
    hojaCalculo.sumarFila(filsum);
    cout << "numero de fil que desea sumar: ";
    cin >> filsum;
    hojaCalculo.sumarFila(filsum);  

    /*8*/
    /*int colsum = 0;
    cout << "numero de col que desea sumar: ";
    cin >> colsum;
    hojaCalculo.sumarCol(colsum);
    cout << "numero de col que desea sumar: ";
    cin >> colsum;
    hojaCalculo.sumarCol(colsum);*/

    cout << endl
         << endl;
    return 0;
}
