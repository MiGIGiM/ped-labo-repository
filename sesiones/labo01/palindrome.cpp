#include <iostream>
#include <cstring>
using namespace std;

string reverse(string s);

int main(void) {
    string s = "";

    cout<<"Ingrese una frase para evaluar: "<<endl;
    cin>>s;
    cout<<reverse(s)<<endl;

    return 0;   
}


string reverse(string s){
    if(s.length() ==1){
        return s;
    }
    
    return reverse(s.substr(1)) + s[0];
}
    