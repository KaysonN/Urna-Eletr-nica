#ifndef Fila_hpp
#define Fila_hpp

#include <iostream>
#include <string>
using namespace std;

struct NodoFila{

    string nome;
    NodoFila *proximo;
};

class Fila
{
public:
    Fila();
    void push(NodoFila *novoItem);
    void pop();
    bool empty();
    int  size();
    void debug();
    void print();
    NodoFila* front();
    
private:
    NodoFila *primeiro;
    NodoFila *ultimo;
    int s; // size
};

#endif /* Fila_hpp */
