#include "Pilha.hpp"

Pilha::Pilha()
{
    tamanho = 0;
}

void Pilha::Push(NodoPilha *novo)
{
    if(tamanho == 0)
    {
        topo = novo;
        tamanho = 1;
    }
    else
    {
        novo->proximo = topo;
        topo = novo;
        tamanho++;
    }
}
void Pilha::Pop()
{
    if(tamanho == 0)
    {
        cout << "Pilha vazia, nada a remover\n";
    }
    else if(tamanho == 1)
    {
        tamanho = 0;
        topo = 0; // não tem mais topo
    }
    else
    {
        topo = topo->proximo;
        tamanho--;
    }
}

NodoPilha * Pilha::Top()
{
    return topo;
}

bool Pilha::Empty()
{
    if(tamanho>0)
        return false;
    else
        return true;
}

int Pilha::Size()
{
    return tamanho;
}
