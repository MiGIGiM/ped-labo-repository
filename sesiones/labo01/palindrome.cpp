//Determine si una palabra que se introduce desde teclado es palíndrome. Recuerde: una 
//palabra es palíndrome si se lee igual tanto de izquierda a derecha como de derecha a 
//izquierda, ejemplo: anona. Nota: no ingrese vocales tildadas.
#include <iostream>
#include <cstring>
using namespace std;

string removeEmpty(string s);
string reverse(string s);

int main(void) {
    string s = "";

    cout<<"Ingrese una frase para evaluar: "<<endl;
    getline(cin, s);

    s= removeEmpty(s);
    cout<<(s.compare(reverse(s)) == 0 ? "palindrome" : "no es palindrome")<<endl;

    return 0;   
}

string removeEmpty(string s){

    string result = "";
     
    for(int i= 0; i<s.length(); i++){
        if(s[i] != ' ' ){
            result += s[i];
        }
    }

    return result;
}

string reverse(string s){
    if(s.length() ==1){
        return s;
    }

    cout<<s<<endl;
    return reverse(s.substr(1)) + s[0];
}
    