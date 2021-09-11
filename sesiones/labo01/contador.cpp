//Elabore una función que, dado un número entero que se obtiene desde teclado, realice 
//un conteo como el siguiente:
#include <iostream>
#include <cstring>
using namespace std;

void printSequence(int start, int n);

int main(void) {
    int n = 0;
    
    cout<<"Ingrese una numero "<<endl;
    cin>>n;
    printSequence(1, n);

    return 0;   
}

void printSequence(int start, int n) {
    if(start == n) {
        cout << start << endl;
        return;
    }
    
    cout << start << endl;
    printSequence(start + 1, n);
    cout << start << endl;
}