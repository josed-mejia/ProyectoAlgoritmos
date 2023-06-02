#ifndef UNTITLED_LIBRARY_H
#define UNTITLED_LIBRARY_H

#include <iostream>

using namespace std;

//Se crea la clase Nodo, los elemetnos de esta clase serán los elementos de las listas y las pilas
class Nodo{
private:
    int num; //Este será el contenido de cada elemento, en este caso será un entenro, pero puede ser cualquier tipo de variable
public:
    Nodo *nxt;//El apuntador al siguiente elemento
    Nodo *prev;//El apuntador al anterior, este sólo se usará en las listas doblemente enlazadas
    Nodo(int pNum);//La declaración del constructor de la clase
    int getNum(){return num;};//Una función que retorna el contenido del nodo, ya que la variable num está privada
};

//El constructor de la clase, aquí se asigna el valor pedido a la variable num y se le asigna un valor nulo al nodo siguiente y anterior
Nodo::Nodo(int pNum){
    num = pNum;
    nxt = NULL;
    prev = NULL;
}

//La clase Listaenlazada será una lista de nodos que se podrá recorrer por medio del nodo siguiente
class Listaenlazada{
private:
    Nodo *cabeza;//Este nodo será la cabeza de la lista, por medio de esta se podrá acceder a todos los elementos de la lista
public:
    Listaenlazada() : cabeza(NULL){} //Se hace el constructor, donde la cabeza tendrá un valor nulo
    void insert(int num){ //La funcion insert pide un número que luego para añadir un nuevo nodo a la lista con este valor
        Nodo *nuevo = new Nodo(num); //Se crea el nodo
        nuevo->nxt = cabeza;//El nodo que está de cabeza será el siguiente
        cabeza = nuevo;//L nueva cabeza será el nodo que creamos
    };
    void recorrer(){//Esta función imprimirá  todo el contenido de la lista
        Nodo* actual = cabeza; //Se crea un nodo temporal con el cual se accederá a toda la lista para no alterar esta
        while(actual != NULL){ //Se recorre hasta que el nodo sea nulo
            cout<<actual->getNum()<<","; //Se imprime el contenido del nodo usando la función getNum()
            actual = actual->nxt;//El actual se convierte en el siguiente para continuar con el recorrido
        }
        cout<<endl;
    }
    void remover(int e){//Esta funcion quitará de la lista el valor que se ingrese
        if(cabeza == NULL){return;}
        if(cabeza->getNum() == e){
            Nodo* tmp = cabeza;//Si el valor está en la cabeza, se crea un nodo temporal que sea esta
            cabeza = cabeza->nxt;//La nueva cabeza será el siguiente
            delete tmp;//Se borra el nodo temporal
        }
        Nodo* actual = cabeza;//Si el valor no es igual a la cabeza, se crea un nodo para recorrer la lista hasta encontrar el valor esperado o que se acabe la lista
        while(actual->nxt != NULL && actual->nxt->getNum() != e){//Se hace el recorrido
            actual = actual->nxt;
        }
        if(actual->nxt != NULL){
            Nodo* tmp = actual->nxt;//Si el nodo siguiente no es nulo, es decir, se encontró el valor antes de que se acabara la lista entonces se crea un nodo y se iguala a este
            actual->nxt = actual->nxt->nxt;//El nuevo siguiente sera el siguiente al siguiente
            delete tmp;//Se borra el nodo con el valor que se pedía
        }
    }
};

//La clase Listadoble tendrá los mismos métodos, lo que cambiará es que tendremos acceso al nodo anterior
class Listadoble{
private:
    Nodo *cabeza;
public:
    Listadoble() : cabeza(NULL){};
    void insert(int num){
        Nodo *anterior;
        Nodo *nuevo = new Nodo(num);
        if(cabeza==NULL){
            cabeza=nuevo;
        }else{
            if(anterior==NULL){
                cabeza->nxt=nuevo;
                nuevo->prev=cabeza;
            }else{
                Nodo *t;
                t = cabeza;
                while(t->nxt != NULL){
                    t = t->nxt;
                    anterior = t->prev;
                }
                t->nxt=nuevo;
                nuevo->prev=t;
            }

        }
    }
    void recorrer(){
        Nodo *t;
        t=cabeza;
        while(t!=NULL){
            cout<<t->getNum()<<",";
            t=t->nxt;
        }
        cout<<endl;
    }
    void remover(int e){
        if(cabeza == NULL){return;}
        if(cabeza->getNum() == e){
            Nodo* tmp = cabeza;
            cabeza = cabeza->nxt;
            cabeza->prev = NULL;
            delete tmp;
        }
        Nodo* actual = cabeza;
        while(actual->nxt != NULL && actual->nxt->getNum() != e){
            actual = actual->nxt;
        }
        if(actual->nxt != NULL){
            Nodo* tmp = actual->nxt;
            actual->nxt = actual->nxt->nxt;
            actual->nxt->prev = actual;
            delete tmp;
        }
    }
};

//La clase pila creará una lista enlazada para hacer el contenido de la pila, por la forma en la que se programó, la cabeza siempre será el último elemento que se agregue para poder eliminaerlo fácilmente
class Pila{
public:
    int numnodos = 0; //Este será el tamaño de la pila
    Nodo *cabeza;
    Pila() : cabeza(NULL){}
    void addPila(int infoo){ //Se añaden elementos de la misma forma que en una lista enlazada
        Nodo *nuevo = new Nodo(infoo);
        nuevo->nxt = cabeza;
        cabeza = nuevo;
        numnodos ++;
    };
    void verPila(){//Se recorre la pila de la misma forma que en las listas enlazadas, enn este caso se recorrerá al revés, mostrando de primero el último elemento añadido
        Nodo* actual = cabeza;
        while(actual != NULL){
            cout<<actual->getNum()<<",";
            actual = actual->nxt;
        }
        cout<<endl;
    }
    void delPila(){//Se borra la cabeza de la misma forma que se hacía en una lista enlazada
        if(cabeza == NULL){return;}
        Nodo* tmp = cabeza;
        cabeza = cabeza->nxt;
        delete tmp;
        numnodos --;
    }

    bool estaVacia(){//Se comprueba si la lista está vacía y retorna un valor booleano
        if(cabeza == NULL){return true;}
        return false;
    }

    int tamPila(){//Retorna el tamaño de la pila
        return numnodos;
    }
};

//La clase cola también crea una lista enlazada, pero en este caso se programa de tal forma de que la cabeza siempre sea el primer elemento que se añade para poder borrarlo fácilmente
class Cola{
public:
    int cant = 0;//Este es el tamaño de la cola
    Nodo *cab = NULL;
    Nodo *cola = NULL;
    void addCola(int pl){//Se añaden los elementos de tal forma que la cabeza sea siempre el primer valor, la cola será el último
        Nodo *nuevo = new Nodo(pl);
        if(cab == NULL && cola == NULL){
            cab = nuevo;
            cola = nuevo;
        }else if(cab == cola){
            cola = nuevo;
            cab->nxt = cola;

        }else{
            cola->nxt = nuevo;
            cola = cola->nxt;
        }
        cant ++;
    }
    void delCola(){//Se borra la cabeza de la misma forma que en una lista enlazada
        Nodo* tmp = cab;
        cab = cab->nxt;
        delete tmp;
        cant --;
        if(cab == NULL){
            cola = NULL;
        }
    }

    void verPri(){//Imprime el primer valor de la cola, es decir el siguiente a eliminar
        cout<<"el primer elemento en la cola es: "<<cab->getNum()<<endl;
    }

    bool estaVacia(){//Se comprueba si la lista está vacía y retorna un valor booleano
        if (cab == NULL && cola == NULL){
            return true;
        }else{
            return false;
        }
    }

    int tamCola(){//Retorna el tamaño de la cola
        return cant;
    }

    void verCola(){//Recorre la cola imprimiendo sus valores en orden
        while(cab != NULL){
            cout<<cab->getNum()<<",";
            cab=cab->nxt;
        }
        cout<<endl;
    }
};

#endif //UNTITLED_LIBRARY_H
