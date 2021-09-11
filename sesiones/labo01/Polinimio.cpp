/**
 * Dada una lista lineal simplemente enlazada, en la que en cada nodo se almacenan el 
 * coeficiente y el exponente de x de los términos de un polinomio de la forma 
 * p(x) = a0x0 + a1x^1 + a2x^2 + … + an xn, elabore una función que evalúe el 
 * polinomio para un valor de x dado. La función miembro recibirá como argumento el valor de x y deberá retornará 
 * el valor de p(x) calculado. El tipo del valor retornado por la función debe ser float. Si 
 * elabora la versión recursiva de la solución, la función miembro deberá recibir también el 
 * puntero cabeza de la lista.
 **/

#include <iostream>
#include <cmath>
using namespace std;

struct term{
    double a, x;
    term* next;
};

class poly{
    private:
        term* head;

        double evaluate(term* head){
            return pow(head->a,head->x);
        }

        double evaluateExpression(term* head){
            if(head) {
                return evaluate(head) + evaluateExpression(head->next);
            }
            else
                return 0;
        }

    public:
        poly(){
            head = NULL;
        }    

        ~poly(){
            delete head;
        }

        void insertTerm(double a, double x) {
            term* t = new term;
            t->a = a;
            t->x = x;
            t->next = NULL;

            if(head == NULL){
                head = t;
            }
            else{
                term* curr = head;
                while(curr->next != NULL){
                    curr = curr->next;
                }
                curr->next = t;
            }
        }

        double evaluate(){
            return evaluateExpression(head);
        }
};

int main(void) {
    poly p;

    p.insertTerm(2,2);
    p.insertTerm(2,3);
    p.insertTerm(2,4);

    cout << p.evaluate() << endl;
}