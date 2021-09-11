/**
 * Elabore un programa que permita llenar una lista simple 
 * con n números aleatorios entre 1 y 100 por medio de una función 
 * invocada desde main.
 * Asimismo 
 * elabore funciones de impresión que trabajen de la siguiente manera:
 * a) Mostrar todos los elementos de la lista.
 * b) Mostrar solo los números pares de la lista.
 * c) Mostrar solo los números impares de la lista.
 * d) Mostrar todo su contenido en sentido inverso (esta función debe ser recursiva).
 **/

#include <iostream>
#include <cstdlib>
#include <time.h>
using namespace std;

struct node{
    int data;
    node* next;
};

class list{
    private:
        node* head;

        void insertData(int data) {
            node* temp = new node;
            temp->data = data;
            temp->next = head;
            head = temp;
        }

        void insertRandom(){
            for (int i = 0; i < 10; i++){
                insertData(rand() % 100);
            }
        }

        void print(node* head){
            if (head){
                cout << head->data << " ";
                print(head->next);
            }
            else
                cout << endl;
        }

        void printOddEven(node* head, bool even){
            if(head){
                if(even && head->data % 2 == 0)
                    cout << head->data << " ";
                else if(!even && head->data % 2 != 0)
                    cout << head->data << " ";

                printOddEven(head->next, even);
            }
            else
            {
                cout << endl;
            }
            
        }

        void printReverse(node* head){
            if(head){
                printReverse(head->next);
                cout << head->data << " ";
            }
        }

    public:
        list(){
            head = NULL;
            srand(time(NULL));
            insertRandom();
        }

        ~list(){
            delete head;
        }

        void show(){
            print(head);
        }

        void showReverse(){
            printReverse(head);
        }

        void showOddEven(bool even){
            printOddEven(head, even);
        }
};

int main(void){
    list l;

    cout << "Lista generada: ";
    l.show();

    cout << "Lista Par: ";
    l.showOddEven(true);

    cout << "Lista imPar: ";
    l.showOddEven(false);

    cout << "Lista alreves: ";
    l.showReverse();
}
