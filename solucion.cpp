#include <iostream>
using namespace std;

struct nodo
{
    int dato;
    nodo *next;
};

class listaSimpleEn
{
private:
    nodo *head;
public:
    nodo *inicio;
    listaSimpleEn(){
        inicio = NULL;
    };
    void LlenarLista(int);
    void MostrarLista();
};

void listaSimpleEn::LlenarLista(int n)
{
    nodo *saltar; 

    if (inicio == NULL)
    {
        inicio = new nodo;
        inicio->dato = n;
        inicio->next = NULL;
        head = inicio;
    }
    else{
        saltar = new nodo;
        saltar->dato=n; 
        saltar->next = NULL;
        head->next= saltar;
        head = saltar;
    }
}

void listaSimpleEn::MostrarLista()
{
    if (inicio == NULL)
    {
        cout << "La lista esta vacia" << endl;
       
    }
    else{
         
        nodo *saltar;
        saltar = inicio;
        while (saltar!= NULL)
        {
            cout << saltar->dato << " ";
            saltar = saltar->next;
        }
        cout << endl;
    }
}

nodo* reverse(nodo *head)
{
        if (head == NULL || head->next == NULL)
            return head;

        nodo* rest = reverse(head->next);
        head->next->next = head;
 
        head->next = NULL;
 
        return rest;
}

void inverseList(nodo* inicio)
{
    if (inicio == NULL)
    {
        cout << "La lista esta vacia" << endl;
       
    }
    else{
         
        nodo *saltar;
        saltar = inicio;
        while (saltar!= NULL)
        {
            cout << saltar->dato << " ";
            saltar = saltar->next;
        }
        cout << endl;
    }
}


int main(){
    listaSimpleEn objlistaSimpleEn;
    int datos = 0;
    do
    {
        cout << "Ingresar un numero o -1 para terminar" <<endl;
        cin >> datos;
        if (datos != -1)
        {
            objlistaSimpleEn.LlenarLista(datos);
        }
        
    } while (datos != -1);
    cout << endl;
    cout << "Datos ingresados" << endl;
    objlistaSimpleEn.MostrarLista();
    cout <<endl;
    cout << "Datos mostrados invertidos" << endl;
    inverseList(reverse(objlistaSimpleEn.inicio));
    cout<<endl;
}