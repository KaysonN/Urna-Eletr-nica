#include "Fila.hpp"

Fila::Fila()
{
    // Ao criar uma fila, o tamanho é zero e ela esta vazia, por isso, primeiro e ultimo nodo não apontam para ninguém
    s = 0;
    primeiro = 0;
    ultimo = 0;
}

bool Fila::empty()
{
    if (s > 0)
        return false;
    else
        return true;
}

void Fila::push(NodoFila *novoItem)
{
    if(empty())
    {
        primeiro = novoItem;
        ultimo = novoItem;
    }
    else
    {
        ultimo->proximo = novoItem;
        ultimo = novoItem;
    }
    s++;
}

void Fila::debug()
{
    cout << "Tamanho da Fila: " << s << endl;
    if(s>0)
    {
        cout << "Primeiro da Fila: " << primeiro->nome << endl;
        cout << "Ultimo da Fila: " << ultimo->nome << endl;
    }
}

void Fila::pop()
{
    if(empty()){
        cout << "Fila vazia, nao ha o que remover.\n";
        
     }else if (s==1)
     {
         //zera a estrutura quando remove o ultimo
         primeiro = 0;
         ultimo = 0;
         s = 0;
     }
     else
     {
         primeiro = primeiro->proximo;
         s--;
     }
}

NodoFila* Fila::front()
{
    return primeiro;
}

int Fila::size()
{
    return s;
}
