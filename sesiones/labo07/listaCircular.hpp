#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    struct nodo *sig;
};

class ListaCircularSimple
{

private:
    nodo *pInicio;

public:
    ListaCircularSimple();
    ~ListaCircularSimple();
    void insInicio(int);
    void insFinal(int);
    void insOrdenAsc(int);
    void insOrdenDesc(int);
    void insertAfter(int, int);
    void mostrarListaIter(void);
    void eliminarListaCircularRec(nodo *);
};

ListaCircularSimple::ListaCircularSimple(void)
{
    pInicio = NULL;
}

ListaCircularSimple::~ListaCircularSimple(void)
{
    if (pInicio)
    {
        eliminarListaCircularRec(pInicio);
        pInicio = NULL;
    }
}

void ListaCircularSimple::eliminarListaCircularRec(nodo *p)
{
    if (p->sig != pInicio)
        eliminarListaCircularRec(p->sig);

    delete p;
}

void ListaCircularSimple::insInicio(int dato)
{
    nodo *nuevo;
    nuevo = new nodo;
    nuevo->dato = dato;

    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else
    {
        nuevo->sig = pInicio;
        nodo *saltarin = pInicio;

        while (saltarin->sig != pInicio)
        {
            saltarin = saltarin->sig;
        }

        saltarin->sig = nuevo;
        pInicio = nuevo;
    }
}

void ListaCircularSimple::insFinal(int dato)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->dato = dato;

    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else
    {
        nuevo->sig = pInicio;
        saltarin = pInicio;

        while (saltarin->sig != pInicio)
        {
            saltarin = saltarin->sig;
        }

        saltarin->sig = nuevo;
    }
}

void ListaCircularSimple::insOrdenAsc(int dato)
{
    nodo *nuevo, *saltarin;

    nuevo = new nodo;
    nuevo->dato = dato;

    if (!pInicio)
    {
        pInicio = nuevo;
        pInicio->sig = pInicio;
    }
    else
    {
        if (dato < pInicio->dato)
        {
            nuevo->sig = pInicio;
            saltarin = pInicio;

            while (saltarin->sig != pInicio)
            {
                saltarin = saltarin->sig;
            }

            saltarin->sig = nuevo;
            pInicio = nuevo;
        }
        else
        {
            saltarin = pInicio;

            while (saltarin->sig->dato < dato && saltarin->sig != pInicio)
            {
                saltarin = saltarin->sig;
            }

            nuevo->sig = saltarin->sig;
            saltarin->sig = nuevo;
        }
    }
}

void ListaCircularSimple::insOrdenDesc(int dato)
{

}

void ListaCircularSimple::insertAfter(int dato, int after_item)
{
    nodo *nuevo, *saltarin;
    bool found = false;

    nuevo = new nodo;
    nuevo->dato = dato;

    if (!pInicio)
    {
        cout << "No hay datos en la lista" << endl;
    }
    else
    {
        saltarin = pInicio;

        do
        {
            if (saltarin->dato == after_item)
            {
                found = true;
                nuevo->sig = saltarin->sig;
                saltarin->sig = nuevo;
                cout << "Dato almacenado exitosamente" << endl;
                break;
            }
            saltarin = saltarin->sig;
        } while (saltarin->sig != pInicio);

        if (saltarin->sig == pInicio && saltarin->dato == after_item)
        {
            found = true;
            nuevo->sig = pInicio;
            saltarin->sig = nuevo;
            cout << "Dato almacenado exitosamente" << endl;
        }
        if (!found)
        {
            cout << "el nodo " << after_item << "no esta en la lista" << endl;
        }
    }
}

void ListaCircularSimple::mostrarListaIter(void)
{
    nodo *saltarin;

    cout << endl;
    if (pInicio)
    {
        saltarin = pInicio;
        do
        {
            cout << saltarin->dato << endl;
            saltarin = saltarin->sig;
        } while (saltarin != pInicio);
    }
    else
    {
        cout << "Lista vacia" << endl;
    }
}