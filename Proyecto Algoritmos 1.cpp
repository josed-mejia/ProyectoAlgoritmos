#include "Proyecto Algoritmos 1.h"

using namespace std;

int main()
{
    Cola cola;

    cout<<cola.estaVacia()<<endl;
    cola.addCola(10);
    cola.addCola(11);
    cola.addCola(12);
    cola.addCola(13);
    cola.verCola();
    cola.verPri();
    cout<<cola.tamCola()<<endl;
    cola.delCola();
    cola.verCola();
    cola.verPri();
    cout<<cola.tamCola()<<endl;
    cout<<cola.estaVacia()<<endl;



    return 0;
}