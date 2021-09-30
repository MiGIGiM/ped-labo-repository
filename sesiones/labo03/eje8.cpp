/*Elabore una función que reciba como parámetro una lista simple y un número entero.
Luego elimine de la lista todas las ocurrencias de ese número.*/
#include <iostream>

using namespace std;

/* Estructura del nodo */
struct node {
  int num;
  node *siguiente;
};

void eliminar_busqueda(node *inicio, int b_num);

class List {
    public:
    List();
    void capturar();
    void mostrar();
    node *inicio;
    private:
    node *head;
};

List::List(){
    inicio = NULL;
}
void List::capturar(){
node *aux;
if(inicio == NULL){
    inicio = new node;
    cout<<"Inserte un numero: ";
    cin>> inicio->num ;
    inicio->siguiente = NULL;
    head = inicio;
}else{
    aux = new node;
    cout<<"Inserte un numero: ";
    cin>> aux->num ;

    aux->siguiente = NULL;
    head ->siguiente =  aux;
    head= aux; 
}
}

void List::mostrar(){
    if(inicio==NULL){
        cout<<"LISTA VACIA!"<<endl;
    }else{
        node *aux1 = inicio; 
        while(aux1 != NULL){
            cout<< aux1->num <<endl;
            aux1= aux1->siguiente;
        }
    }
}

enum MENU_PRINCIPAL{ CAPTURAR=1, MOSTRAR, ELIMINAR, SALIR};

int main() {
    int opcion, b_num;
    List n;
    do{
        cout<< "1) CAPTURAR" <<endl;
        cout<< "2) MOSTRAR"<<endl;
        cout<< "3) ELIMINAR"<<endl;
        cout<<" 4) SALIR"<<endl;
        cout<< "\nOpcion:";
        cin>>opcion;

        switch(opcion){
            case CAPTURAR: 
             cout<<"\n";
             n.capturar();
             cout<<"\n";
            break;

            case MOSTRAR:
             cout<<"\n";
             n.mostrar();
             cout<<"\n";
            break;

            case ELIMINAR:
            cout<<"numero a eliminar: ";
            cin>> b_num;
            eliminar_busqueda(n.inicio,b_num);
            cout<<"\n";
            break;

            default:
            opcion = SALIR;
        }
    }while(opcion != SALIR);
  return 0;
}

void eliminar_busqueda(node *inicio, int b_num){
    node *saltarin;
    node *anterior;
    int contador = 0; 

    if(inicio == NULL){
        cout<<  "LISTA VACIA!!"<<endl;
    }else{
        saltarin = inicio;
        anterior = inicio; 

        while(saltarin!= NULL){
            if(saltarin->num == b_num){
                contador++;
                anterior->siguiente = saltarin->siguiente;
                saltarin = anterior->siguiente;
            }else{
                anterior = saltarin;
                saltarin = saltarin->siguiente;
            }
        }
    }
    if(contador == 0){
        cout<<"numero no encontrado en la lista"<<endl;
    }
}