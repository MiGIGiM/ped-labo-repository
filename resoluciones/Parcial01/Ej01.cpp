#include <iostream>
using namespace std;

void ordenar(int *mayor, int *med, int *menor);

int main(void){
    int n1 = 0, n2 = 0, n3 = 0;

    cout << "n1: "; cin >> n1;
    cout << "n2: "; cin >> n2;
    cout << "n3: "; cin >> n3;

    ordenar(&n1, &n2, &n3);

    cout << "Ordenados: " << n1 << " " << n2 << " " << n3 << endl;

    return 0;
}

void ordenar(int *mayor, int *med, int *menor){
    int n1 = *mayor;
    int n2 = *med;
    int n3 = *menor;

    if (n1 < *med){
        n1 = *med;
    }


    if(n1 < *menor){
        n1 = *menor;
    }
    

    if(n2 > *mayor && n2 < *menor){
        n2 = *med;
    }
    else if(n2> *mayor){
        n2 = *mayor;
    }
    else if(n2 < *menor){
        n2 = *menor;
    }

    if(n3 > *mayor){
        n3 = *mayor;
    }

    if(n3 > *med){
        n3 =*med;
    }

    *mayor = n1;
    *med = n2;
    *menor = n3;
}