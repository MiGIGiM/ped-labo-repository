#include <iostream>

using namespace std;

struct Materia{
    string nombre;
    int nota;
};

Materia solicitarMateria(void){
    Materia m;
    cout << "nombre: ";
    getline(cin, m.nombre);
    cout << "Nota obtenida: ";
    cin >> m.nota; cin.ignore();
    return m;
}

void mostrarMateria(Materia m){
    cout << "Nombre: " << m.nombre <<" ";
    cout << "Nota obtenida: " << m.nota << endl;
}

//Uso de typedef para generalizar la lista doble con una plantilla

typedef Materia M;
const M noValido = {"",0};

struct nodo{
    M dato;
    nodo *sig;
    nodo *ant;
};

class ListaDoble{
    public:
        nodo *pInicio;
        ListaDoble();
        ~ListaDoble();
        void insertFront(M);
        void traversalForwardDirection(void);
        void traversalForwardDirectionPromedio(void);
};

ListaDoble::ListaDoble(void){
    pInicio = NULL;
}

ListaDoble::~ListaDoble(void){
    nodo *p;
    while(pInicio){
        p = pInicio;
        pInicio = pInicio->sig;
        delete p;
    }
}

void ListaDoble::insertFront(M dato){
    nodo *nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = pInicio;
    if(pInicio != NULL)
        pInicio->ant = nuevo;
    pInicio = nuevo;
}


void ListaDoble::traversalForwardDirection(void){
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        mostrarMateria(saltarin->dato);
        saltarin = saltarin->sig;
    }

 }

void ListaDoble::traversalForwardDirectionPromedio(void){
    int acum = 0, cont = 0 ; 
    nodo *saltarin = pInicio;
    while(saltarin != NULL){
        acum += saltarin->dato.nota;
        saltarin = saltarin->sig;
        cont++;
    }

    float res = float(acum)/float(cont);
   cout<< "El promedio es: " << res <<endl;
 }

int menu(){
    int opcion = 0;
    cout << endl << "1) Agregar una Materia." << endl;
    cout << "2) Mostrar materias de inicio a fin." << endl;
    cout << "3) Mostrar promedio de materias." << endl;
    cout << "4) salir." << endl;
    cout << "Opcion: ";
    cin >> opcion; cin.ignore();
    return opcion;
}

int main(void){
    ListaDoble materias;
    
    bool continuar = true;
    Materia m;
    do{
        switch(menu()){
            case 1: 
                m = solicitarMateria();
                materias.insertFront(m);
                cout << "Materia almacenada exitosamente!" << endl;
                break;
            case 2:
                materias.traversalForwardDirection();
                break;
            case 3:
                materias.traversalForwardDirectionPromedio();
                break;    
            case 4:
                continuar = false;
                break;
            default: 
                cout << "La opcion no es valida, favor intente denuevo." << endl;
                break;
        }
    }while(continuar);
    
    return 0;
}

