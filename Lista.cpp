#include "Lista.hpp"

Lista::Lista(){
	
	tamanho = 0;
	primeiro = 0;
	ultimo = 0;	
}

void Lista::debug()
{
    cout << "Tamanho da Lista: " << tamanho << endl;
    if(tamanho>0)
    {
        cout << "Primeiro da Lista: " << primeiro->dado << endl;
        cout << "Ultimo da Lista: " << ultimo->dado << endl;
    }
}

bool Lista::empty(){
	if(tamanho>0){
		return false;
	}
	
	else{
		return true;
	}
}

void Lista::insereInicio(NodoLista *novo){//ok

	if(empty()){
		
		primeiro = novo;
		ultimo = novo;
	}
	
	else{
		novo->proximo=primeiro;
		primeiro->anterior=novo;
		primeiro=novo;	
	}
	
	tamanho++;
}

void Lista::insereFim(NodoLista *novo){//ok
	
	if(empty()){
		primeiro = novo;
		ultimo = novo;
	}
	
	else{
		novo->anterior=ultimo;
		ultimo->proximo=novo;
		ultimo = novo;
	}
	
	tamanho++;
}

void Lista::imprimeLista(NodoLista *n){
    
    cout << n->dado << "\n";
    
    if(n->proximo){
    	return imprimeLista(n->proximo);
	}
    
}


int Lista::size(){
	return tamanho;
}




