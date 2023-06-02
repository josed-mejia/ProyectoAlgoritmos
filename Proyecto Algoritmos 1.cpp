#include "Proyecto Algoritmos 1.h"

using namespace std;

int main()
{
    Listaenlazada lista;
    lista.insert(1);
    lista.insert(32);
    lista.insert(5);
    lista.insert(8);
    lista.insert(13);
    lista.recorrer();
    lista.remover(1);
    lista.recorrer();

    Listadoble lista2;
    lista2.insert(23);
    lista2.insert(65);
    lista2.insert(78);
    lista2.insert(2);
    lista2.recorrer();
    lista2.remover(78);
    lista2.recorrer();

    Pila pila;
    pila.addPila(72);
    return 0;
}