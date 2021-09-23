#include <iostream>
using namespace std;

int sumaRec();

int main(void){
    int sum = sumaRec();

    cout << "La sumatoria es: " << sum << endl;

    return 0;
}

int sumaRec(){
    int n = 0;

    cout << "Ingrese un numero (-1 para salir) "; cin >> n;

    if(n != -1)
        return sumaRec() + n;
    
    else
        return n + 1;
}