#include <iostream>
#include <locale>
#include "Lista.hpp"
#include "Fila.hpp"
#include "Pilha.hpp"

int main(int argc, char** argv) {
	setlocale(LC_ALL, "Portuguese");
	
	int v_p[5]={0}, v_v[50]={0};//vetores feitos para fazer referencia �s chapas dos candidatos
	string vP[5], vV[50]; //vetores feitos para guardar o nome dos candidatos
	int numP, numV, maior = 0, maiorV = 0, confirma, novo = 1;
	/*
	numP = numero da chapa de Prefeito, essa vari�vel foi feita para referenciar a posi��o onde ir� somar no vetor v_p[5] 
	numV = numero da chapa de Vereador, essa vari�vel foi feita para referenciar a posi��o onde ir� somar no vetor v_v[5]
	maior/maiorV = vari�vel feita para comparar os numeros dentro de um vetor, onde o maior numero ser� referente ao vencedor das elei��s(Prefeito/Vereador) 
	confirma = vari�vel que verifica se o eleitor realmente vai votar em um determinado candidato 
	novo = 
	*/
	float porcentagem = 0;//============================================APLICAR ESSA VARI�VEL===============================================================
	
	Fila f;//fila generica(f)
	Pilha pP, pV;//(p)ilha(P)refeito(pP), (p)ilha(V)ereador(pV);
	Lista lPrefeito, lVereador;//candidatos (l)istaPrefeito, (l)istaVereador
	
	NodoFila *auxF; //Nodo auxiliar para Fila
	NodoPilha *auxPP, *auxPV; //Nodo auxiliar para Pilha de Prefeiro/Vereador
	NodoLista *auxL_P, *auxL_V; //Nodo auxiliar para Lista de Prefeiro/Vereador
	
	int sw = 0;//Switch
	
		while(sw!=4){
			
			system("cls");
			cout << "==========MENU===========\n";
			cout << "(1)Adicionar Candidados\n";
			cout << "(2)Vota��o\n";
			cout << "(3)Apura��o dos Votos\n";
			cout << "(4)Sair\n::>";
			cin >> sw;
			
			system("cls");
			
			switch(sw){
				
				case 1:{//Cadastro de candidatos
					
					while(sw != 2){
						if(lPrefeito.size() == 5 && lVereador.size() == 50){//quando ambas partes (prefeitura/vereadores) chegarem ao limite (5 e 50), a vari�vel sw ir� valer 2, for�ando a come�ar 
																			//as elei��es
							sw=2;
						}
						
						else{//enquanto o if acima n�o for uma premissa verdadeira, temos um la�o for, onde criaremos sempre ao inicialo um novo nodo auxiliar, tanto de prefeito quanto de vereador.
						///////Sendo assim, criando uma lista de candidatos(Prefeitos/Vereadores).
								for(int i=0; i<50;i++){
									
									auxL_P = new NodoLista;
									auxL_V = new NodoLista;
									
									if(i<5){//enquanto o la�o estiver em 5, a urna pegar� prefeitos e vereadores para cadastro
										cout << "Candidato � prefeito: ";
										cin >> auxL_P->dado;
										lPrefeito.insereInicio(auxL_P);
										vP[i]=auxL_P->dado;
										cout << "Candidato � vereador: ";
										cin >> auxL_V->dado;
										lVereador.insereInicio(auxL_V);
										vV[i]=auxL_V->dado;
										system("cls");
									}
									
									else{//quando maior que 5, a urna passa a cadastrar apenas vereadores
										cout << "Candidato � vereador: ";
										cin >> auxL_V->dado;
										lVereador.insereInicio(auxL_V);
										vV[i]=auxL_V->dado;
										system("cls");
									}
									
									cout << "Cadastrar mais algum candidato?(1.Sim/2.N�o)";
									cin >> sw;
									
									if(sw != 1){//caso o usu�rio diga que n�o quer mais cadastrar candidatos, soma-se 50 + 1, fazendo com que o la�o seja quebrado
										i = 50+1;
									}
									
									system("cls");
								}
						}
					
					cout << "\n\nCANDIDATOS REGISTRADOS(PRESSIONE QUALQUER TECLA PARA\nCOME�AR A VOTA��O.)";
					cout << "\nVOTE CONSCI�NTE!\nOBS: O VOTO � SECRETO!\n\n\n\n\n";
					system("pause");
					system("cls");	
				}
				
				case 2://PROCESSO DE VOTA��O
					
					auxF = new NodoFila;//fila baseada nas reais filas enfrentadas nas elei��es, ou seja, de pessoas.
					while(novo==1){
						
						auxPP = new NodoPilha;
						auxPV = new NodoPilha;
						
						//nos proximos dois la�os FOR, a urna informa ao Eleitor os numeros dos candidados, caso ele esque�a os numeros de seus politicos
						//OBS: S� aparecer�o os candidatos registrados
						cout << "Candidatos a Prefeito:";
						for(int i=0; i<lPrefeito.size();i++){
							cout << "\n================================================";
							cout << "\nCandidato Prefeito(" << i << "): " << vP[i];
							cout << "\n================================================\n";
						}
										
						cout << "\n\n\nCandidatos a Vereador: ";
						for(int i=0; i<lVereador.size();i++){
							cout << "\n================================================";
							cout << "\nCandidato Vereador(" << i << "): "<< vV[i];
							cout << "\n================================================\n";
						}
						////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
						system("pause");
						system("cls");
					
						cout << "Nome Eleitor: ";
						cin >> auxF->nome;
						f.push(auxF);
						cout << "URNA ELETR�NICA (DIGITE 100 PARA VOTAR EM BRANCO): \n";
						cout << "Chapa do Prefeito(de 0 a 4): ";
						cin >> numP;
						cout << "Chapa do Vereador(0 a 49): ";
						cin >> numV;
						
						cout << "Confirmar?\n(1).Confirma\n(2).Cancela\n>";
						cin >> confirma;
						
						if(confirma==1){
							
							system("pause");
							
							v_p[numP]++;
							v_v[numV]++;
							
							auxPP->qtd = v_p[numP] ;
							pP.Push(auxPP);
							auxPV->qtd = v_v[numV];
							pV.Push(auxPV);
						}
						
						else{
							cout << "Voto cancelado.";
						}
						//verifica se tem outro eleitor na fila, caso n�o tenha, o programa encerra o case 2
						system("cls");
						cout << "Novo Eleitor?\n(1).Confirma\n(2).Encerra\n>";
						cin >> novo;
					}
					
					cout << "JUSTI�A ELEITORAL!";
					system("pause");
					system("cls");
					break;
				
				case 3://APURA��O DOS VOTOS
				
					system("cls");
					//os proximos 2 la�os for mostram quem participou das elei��es e quantos votos receberam
					cout << "Candidatos a Prefeito:";
					for(int i=0; i<pP.Size();i++){
						cout << "\n================================================";
						cout << "\nCandidato Prefeito(" << i << "): " << vP[i] << "\nNumero de votos:" << v_p[i];
						cout << "\n================================================\n";
					}
					
					cout << "\n\n\nCandidatos a Vereador: ";
					for(int i=0; i<pV.Size();i++){
						cout << "\n================================================";
						cout << "\nCandidato Vereador(" << i << "): "<< vV[i] << "\nNumero de votos:" << v_v[i];
						cout << "\n================================================\n";
					}
					system("pause");
					system("cls");
				
					//esse for percorre os vetores que alocam os politicos, usando o tamanho de uma pilha de votos
					//e, assim, verificam quem foi o vencedor.
					for(int i=0; i<pV.Size(); i++){
						
						if(v_p[i]>maior){
							maior = v_p[i];
							cout << "Vencedor das Elei��es(Prefeito): "<< vP[i] << "\nNumero de votos: "<< v_p[i] << "\n\n";
						}
						
						if(v_v[i]>maiorV){
							maior = v_v[i];
							cout << "Vencedor das Elei��es(Vereador): "<< vV[i] << "\nNumero de votos: "<< v_v[i] << "\n\n";
						}
					}
					system("pause");
					break;
				
				case 4:
					cout << "======================\n";
					cout << "||JUSTI�A ELEITORAL!||\n";
					cout << "======================\n";
					system("pause");
					system("cls");
					break;
				
				default:
					cout<<"Digito inv�lido!\n\n";
					system("pause");
					break;
			}	
		}
	}
}










