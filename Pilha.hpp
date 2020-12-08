#ifndef Pilha_hpp
#define Pilha_hpp

#include <iostream>
using namespace std;

struct NodoPilha
{
    int qtd;
    NodoPilha *proximo;
};

class Pilha
{
public:
    Pilha();
    void Push(NodoPilha *novo);
    void Pop();
    NodoPilha * Top();
    bool Empty();
    int Size();
    
private:
    int tamanho;
    NodoPilha *topo;
};

#endif /* Pilha_hpp */
