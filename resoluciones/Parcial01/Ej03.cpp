#include <iostream>
using namespace std;

struct nodo {
    int data;
    nodo* sig;
};

class ListaSimple{
    private:
        nodo* pInicio;

    public:
        ListaSimple(){
            pInicio = NULL;
        }

        void insertDato(){
            int aux = 0;

            cout << "Ingrese una edad (Ctrl + D para finalizar): "; cin >> aux;
            while (cin >> aux)
            {
                insertList(aux);
                cout << "Ingrese una edad (Ctrl + D para finalizar): "; cin >> aux;
            }
        }

        void insertList(int data){
            nodo *nuevo;
            nuevo = new nodo;
            nuevo->data = data;
            nuevo->sig = pInicio;
            pInicio = nuevo;
        }

        void showHighestAge(){
            int numAux = 0;
            nodo *nodeAux;

            nodeAux = pInicio;
            while(nodeAux != NULL){

                if(nodeAux->data > numAux)
                    numAux = nodeAux->data;
            
                nodeAux = nodeAux->sig;
            }

            cout << "Edad mayor: " << numAux << endl;
        }
};

int main(){
    ListaSimple ageList;

    cout << "Llenado lista..." << endl;

    ageList.insertDato();
    ageList.showHighestAge();
}
