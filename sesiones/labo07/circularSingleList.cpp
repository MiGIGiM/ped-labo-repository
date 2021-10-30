#include "listaCircular.hpp"

int menu()
{
    int opcion = 0;
    cout << endl
         << "1) Agregar un dato al inicio." << endl;
    cout << "2) Agregar un dato al final." << endl;
    cout << "3) Agregar un dato despues de otro." << endl;
    cout << "4) Agregar datos en forma ascendiente." << endl;
    cout << "5) Agregar datos en forma descendiente." << endl;
    cout << "6) Mostrar datos." << endl;
    cout << "7) salir." << endl;
    cout << "Opcion: ";
    cin >> opcion;
    return opcion;
}

int solicitarDato()
{
    int dato;
    cout << "Digite un dato:" << endl;
    cin >> dato;
    return dato;
}

int main(void)
{
    ListaCircularSimple listaCircular;
    bool continuar = true;

    cout << "ADMINISTRACIÓN DE LISTA CIRCULAR SIMPLEMENTE ENLAZADA" << endl;

    do
    {
        switch (menu())
        {
        case 1:
            listaCircular.insInicio(solicitarDato());
            cout << "Dato almacenado exitosamente!" << endl;
            break;
        case 2:
            listaCircular.insFinal(solicitarDato());
            cout << "Dato almacenado exitosamente!" << endl;
            break;
        case 3:
            int nuevo, after;
            cout << "<Dato a insertar>" << endl;
            nuevo = solicitarDato();
            cout << "<Dato de referencia>" << endl;
            after = solicitarDato();
            listaCircular.insertAfter(nuevo, after);
            break;
        case 4:
        {
            listaCircular.~ListaCircularSimple();
            int dato = 0;
            while (dato != -1)
            {
                cout << "Digite un entero o -1 para terminar: ";
                cin >> dato;
                if (dato != -1)
                {
                    listaCircular.insOrdenAsc(dato);
                }
            }
        }
        break;
        case 5:
        {
            listaCircular.~ListaCircularSimple();
            int dato = 0;
            while (dato != -1)
            {
                cout << "Digite un entero o -1 para terminar: ";
                cin >> dato;
                if (dato != -1)
                {
                    listaCircular.insOrdenDesc(dato);
                }
            }
        }
        break;
        case 6:
            listaCircular.mostrarListaIter();
            break;
        case 7:
            continuar = false;
            break;
        default:
            cout << "La opcion no es valida, favor intente de nuevo." << endl;
            break;
        }
    } while (continuar);
    return 0;
}