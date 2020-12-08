#ifndef Lista_hpp
#define Lista_hpp

#include <iostream>
using namespace std;

struct NodoLista{
	
	string dado;
	NodoLista *anterior;
	NodoLista *proximo;
};

class Lista{
	public:
		Lista();
		void insereInicio(NodoLista *novo);	
		void insereFim(NodoLista *novo);
		void imprimeLista(NodoLista *novo);
		void debug();
		bool empty();
		int size();
		
	private:
		NodoLista *primeiro;
		NodoLista *ultimo;
		int tamanho;
};


#endif
