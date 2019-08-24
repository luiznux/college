// instrução pra o pre-procesador,ou seja ,
// os valores declarados com "#" nao podem ser alterados!!!!//
#define TAMANHO 5
#include <iostream>
#include <stdlib.h>

using namespace std;

int numeros [TAMANHO];


//Metodo para imprimir o vetor//

void imprimir () 
{
	cout << "/n[";
	for (int i=0; i<TAMANHO; i++){	
		cout << numeros [i] << " ";
        }
        cout << "]"; 
}

/**
* Metodo para incluir um elemento no vetor. A posicao tem que estar vaga
* (valor do elemento igual a zero). O novo elemento tem que ser maior que
* zero.
*
* @param indice - indice do elemento que sera´ incluido.
* @param valor - valor do elemento a ser incluido.
* @return	
*/

string incluir (int indice, int valor)
{
//verifica se o valor é maior que zero
	if (valor<0){
		return "ERRO: o valor tem que ser maior que zero.";
	}	

//Verifica se o indice é valido
	if (indice <0 || indice > TAMANHO -1) {
		return "ERRO: o indice está fora dos limites do vetor.";
	}
//Verifica se a posição já está ocupada
	if (numeros[indice] > 0){
		return "ERRO: posição ocupada.";
	}
//passsou por todas as verificações: inserir
	numeros[indice] = valor;
	return "Inclusão bem sucedida.";
}	

/**
* Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
* elemento (valor).
*
* @param indice - indice do elemento que sera´ excluido.
* @return - valor do elemento excluido. Se retornar zero e´ porque a
* posicao estava vazia; se retornar -1 e´ porque o indice e´ invalido.
*/

int excluir (int indice)
{
	//verifica se o indicce é valido
	if (indice < 0 || indice > TAMANHO - 1){
		return -1;
	}
	
	int numero = numeros[indice];
	
	numeros[indice]= 0;
	return numero;
}
/*Troca 2 elementos de lugar de um vetor
 *@indice1 e @indice2- elementros que vao ser trocados
 *return -1-- erro fora do range 
 *return 0 -- sem erros
 *OPC == 4
 */

int troca(int indice1, int indice2)
{
	if (indice1 < 0 || indice2 < 0){
		return -1;}

	if (indice1 < TAMANHO || indice2 < TAMANHO){
		return -1;}
	int aux;
       	aux = numeros[indice2];
	numeros[indice2] = numeros [indice1];
 	numeros[indice1] = aux;
	return 0;
}


/* Função para encontrar o maior elemento do vetor.
 *OPC == 5
*/

int maior_menor()
{
	int i = 0, maior = 0, menor = 0;
		 for (i; i < TAMANHO; i++ ){
 			 if (numeros[i] > maior){
 				 maior = numeros[i];
	        	 }
  			if (numeros[i] < menor){
               			 menor = numeros[i];
			}	  
         	}
	cout << "Maior valor: " << maior;
	cout << "\nMenor valor: " << menor; 
}

/*Funcão para ondenar o vetor em ordem crescente
 *OPC == 6
*/

string ordemCrescente()
{
	 int i = 0, meio;
  	 	for (i; i < TAMANHO - 1; i++){
    			int menor = i, j = i + 1;
    			for (j; j < TAMANHO; j++){
      				if (numeros[menor] > numeros[j])
        				menor = j;
                        }
                meio = numeros[menor];
    		numeros[menor] = numeros[i];
    		numeros[i] = meio;
  	        }

  		return "Vetor ordenado";
}

/*Função para ordenar o vetor Decrecentemente 
 * OPC = 7
 * 
*/
string ordemDecrescente()
{
	int i = 0, meio;
  	for (i; i < TAMANHO - 1; i++){
    		int maior = i, j = i + 1;
    		for (j; j < TAMANHO; j++){
      			if (numeros[maior] < numeros[j])
        			maior = j;
    		}    
    		meio = numeros[maior];
    		numeros[maior] = numeros[i];
    		numeros[i] = meio;
  	}
  
  	return "Vetor ordenado decrescente";  
}
	
/* Função para ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retor    na o vetor ordenado
 * OPC = 8
 *
*/
string novoVetor()
{
	int i = 0, vetor[TAMANHO], meio;
	for (i; i < TAMANHO; i++){
    		vetor[i] = numeros[i];
  	}	
  	i = 0;
  	for (i; i < TAMANHO - 1; i++){
    		int menor = i, j = i + 1;
    		for (j; j < TAMANHO; j++){
      			if (vetor[menor] > vetor[j])
        			menor = j;
    		}
    		meio = vetor[menor];
    		vetor[menor] = vetor[i];
    		vetor[i] = meio;    
  	}
  	cout << "\n[ ";
  	for (int i = 0; i < TAMANHO; i++) {
    		cout << vetor[i] << " ";
  	}	
  	cout << "]";
  
  	return "\nNovo Vetor ordenado";  
}

	

//==============================================================================
// MAIN
//==============================================================================

int main()
{
	//numeros = new int[TAMANHO];
	for (int i = 0; i < TAMANHO; i++){
		numeros[i] = 0;
	}

	while(true){
		system("CLS");
		cout << "\n----------------------------------------------";
		cout << "\n RELEMBRANDO VETORES";
		cout << "\n----------------------------------------------";
		cout << "\n0 - sair.";
		cout << "\n1 - imprimir o vetor.";
		cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0)";
		cout << "\n3 - excluir um elemento.";
		cout << "\n4 - trocar dois elementos de lugar entre si.";
		cout << "\n5 - localizar o maior e o menor elementos do vetor";
		cout << "\n6 - ordenar os elementos do vetor em ordem crescente";
		cout << "\n7 - ordenar os elementos do vetor em ordem decrescente";
		cout << "\n8 - ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retorna o vetor ordenado";
		cout << "\n---------------------";
		cout << "\nQual a sua opcao -> ";

		int opc;
		cin >>opc;

		if  (opc == 0){			
			break;
		} else if (opc == 1){
			imprimir();
			cout << "\n\n";
			system ("PAUSE");

		} else if (opc == 2){
			//=precisa pedir os dados: posição no vetor (indice) e valor do elemento.
			cout << "Indice de novo elemento; ";
			int idx;
			cin >> idx;
			cout << "Valor do elemento: ";
			int val;
			cin >> val;
			cout << incluir(idx,val) << endl ;
			system("PAUSE");

		} else if (opc == 3 ) {
			cout << "Indice do elemento a ser removido: ";
			int idx;
			cin >> idx;
			int val = excluir(idx);
			
			if (val == 0) {
				cout << "Não há elemento na posição" << idx;
			} else if (val == 1){
				cout << "ERRO: o indice está fora dos limites do vetor: ";
			} else {
				cout << "Valor excluido da posição" << idx << ":" << val;
			}
			
			cout << "\n\n";
		    	system("PAUSE");

		} else if (opc == 4 ){
			cout<< "Digite o primeiro  indice do vetor: ";
			int troc1;
			cin >> troc1;
			cout << "Digite o segundo indice do vetor: ; ";
			int troc2;
			cin >> troc2;
			int saida = troca(troc1,troc2);
			if( saida == -1){
				cout << "ERRO! O indice esta fora do range do vetor";
			} else{
				cout << "Os valores foram trocados com sucesso!";
				imprimir();
			}	

		} else if (opc == 5){
			maior_menor();
			imprimir();
			

		} else if (opc == 6){
			cout << ordemCrescente();
                        imprimir();

		} else if (opc == 7){
			cout << ordemDecrescente();
			imprimir();

		} else if (opc == 8){
			cout << novoVetor();
		}	
          }//CHAVE DO WIHLE LA DE CIMA 	
				
	system("PAUSE");
	cout << "\n-------------------------------------------------";
 	cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";
  	return 0;
}	
