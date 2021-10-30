#include <iostream>

using namespace std;

struct Materia
{
    string nombre;
    int nota;
};

Materia solicitarMateria(void)
{
    Materia m;
    cout << "nombre: ";
    getline(cin, m.nombre);
    cout << "Nota obtenida: ";
    cin >> m.nota;
    cin.ignore();
    return m;
}

void mostrarMateria(Materia m)
{
    cout << "Nombre: " << m.nombre << " ";
    cout << "Nota obtenida: " << m.nota << endl;
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef Materia M;
const M noValido = {"", 0};

struct nodo
{
    M dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble
{
public:
    nodo *pInicio;
    ListaDoble();
    ~ListaDoble();
    void insertFront(M);
    void insertBack(M);
    void traversalForwardDirection(void);
    void traversalForwardDirectionPromedio(void);
    bool searchItem(M);
    void insertAfter(M dato, M datoRef);
};

ListaDoble::ListaDoble(void)
{
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void)
{
    nodo *p;
    while (pInicio)
    {
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(M dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if (pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}
void ListaDoble::insertBack(M dato)
{
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else
    {
        nodo *saltarin = pInicio;
        while (saltarin->sig != NULL)
            saltarin = saltarin->sig;
        saltarin->sig = nuevo;
        nuevo->ant = saltarin;
        nuevo->sig = NULL;
    }
}
void ListaDoble::insertAfter(M dato, M datoRef)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if(!pInicio){
        pInicio = nuevo;
        pInicio->sig = pInicio->ant = NULL;
    }
    else{
        nodo *saltarin;
        saltarin = pInicio;
        while(saltarin->sig != NULL && (saltarin->dato).nombre.compare(datoRef.nombre) != 0){
            saltarin = saltarin->sig;
        }
        nuevo->sig = saltarin->sig;
        nuevo->ant = saltarin;
        if(saltarin->sig != NULL)
            saltarin->sig->ant = nuevo;
        saltarin->sig = nuevo;

    }
}
bool ListaDoble::searchItem(M datoB)
{
    if (!pInicio)
    { // Lista vacía.
        cout << "Actualmente no hay películas." << endl;
        return false;
    }
    else
    { // Si la lista no está vacía, entonces:
        nodo *saltarin = pInicio;
        while (saltarin && (saltarin->dato).nombre.compare(datoB.nombre) != 0) // Saltar.
            saltarin = saltarin->sig;                                          // Luego de saltar hay varias posibilidades:
        if (!saltarin)                                                         // a) saltarín se salió (el dato no está en la lista).
            return false;
        else
            return true;
    }
}

void ListaDoble::traversalForwardDirection(void)
{
    nodo *saltarin = pInicio;
    while (saltarin != NULL)
    {
        mostrarMateria(saltarin->dato);
        saltarin = saltarin->sig;
    }
}

void ListaDoble::traversalForwardDirectionPromedio(void)
{
    int acum = 0, cont = 0;
    nodo *saltarin = pInicio;
    while (saltarin != NULL)
    {
        acum += saltarin->dato.nota;
        saltarin = saltarin->sig;
        cont++;
    }

    float res = float(acum) / float(cont);
    cout << "El promedio es: " << res << endl;
}

int menu()
{
    int opcion = 0;
    cout << endl<< "1) Agregar una Materia al inicio." << endl;
    cout << "2) Agregar una Materia al final." << endl;
    cout << "3) Agregar una Materia despues de otra." << endl;
    cout << "4) Mostrar materias de inicio a fin." << endl;
    cout << "5) Mostrar promedio de materias." << endl;
    cout << "6) Buscar materia." << endl;
    cout << "7) salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    cin.ignore();
    return opcion;
}

int main(void)
{
    ListaDoble materias;

    bool continuar = true;
    Materia m;
    Materia ref;
    do
    {
        switch (menu())
        {
        case 1:
            m = solicitarMateria();
            materias.insertFront(m);
            cout << "Materia almacenada exitosamente!" << endl;
            break;
        case 2:
            m = solicitarMateria();
            materias.insertBack(m);
            cout << "Materia almacenada exitosamente!" << endl;
            break;
        case 3:
            cout << "<Materia a insertar>" << endl;
            m = solicitarMateria();
            cout << "<Materia de referencia>" << endl;
            ref = solicitarMateria();
            materias.insertAfter(m, ref);
            cout << "Materia almacenada exitosamente!" << endl;
            break;
        case 4:
            materias.traversalForwardDirection();
            break;
        case 5:
            materias.traversalForwardDirectionPromedio();
            break;

        case 6:
            cout << "<Materia a buscar>" << endl;
            m = solicitarMateria();
            cout << "Dicha materia " <<m.nombre<< " "<< (materias.searchItem(m) ? "SI" : "NO");
            cout << " se encuentra en la lista." << endl;
            break;
        case 7:
            continuar = false;
            break;
        default:
            cout << "La opcion no es valida, favor intente denuevo." << endl;
            break;
        }
    } while (continuar);

    return 0;
}
