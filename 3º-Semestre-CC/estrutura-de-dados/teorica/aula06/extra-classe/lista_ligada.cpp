#include "lista_ligada.h"

template <class E>
ListaLigada<E>::ListaLigada(){
	cabeca == NULL;
}


template <class E>
ListaLigada<E>::~ListaLigada(){
	delete cabeca;
}

template <class E>
No<E>* ListaLigada<E>::get_cabeca(){
	return cabeca;
}
	


template <class E>
bool ListaLigada<E>::vazia()const{
	return cabeca == NULL;
}


template <class E>
const E& ListaLigada<E>::inicio()const{
	return cabeca -> elem;
}


template <class E>
void ListaLigada<E>::insere_Inicio(const E& e){
	No<E> *aux = new No<E>(); //(1)
	aux -> elem = e; //(2)
	aux -> prox = cabeca; //(3)
	cabeca = aux;
}


template <class E>
void ListaLigada<E>::remove_Inicio(){
	if(!vazia()){
		No<E> *aux = cabeca;
		cabeca = cabeca -> prox;
		delete aux;
	}
}



template <class E>
void ListaLigada<E>::insere_Final(elemento){
	No<E> *aux = cabeca; // crio um aux que vai em ajuda a varrer a lista ligada para nao alterar o valor da cabeça 
	while( aux -> prox != NULL){    // começando a varrer a partir da cabeça, vai parar quando o prox apontar para nulo
		aux = aux -> prox; // aux recebe o proximo nó, para poder continuar varrendo 
	}
	No<E> *novo = new No<E>() // apos sair do while, crio um novo nó para inserir no final 
	novo -> elem = elemento; // adiciono o novo elemento no novo nó
	novo -> prox = NULL; // o prox no novo vai apontar para o null ja que ele é ultimo elemento
 	aux -> prox = novo; // o prox do aux vai apontar para o novo
	
}


template <class E>
void ListaLigada<E>::remove_ultimo(){
	No<E> *aux = cabeca;
	while(aux -> prox -> != NULL){ //se o proximo do proximo for nulo (ou seja) o penultimo
		aux = aux -> prox; // vou parar no penultimo elemento da lista assim apenas deleto o ultimo e atualizo o ponteiro do penultimo
	}
	delete aux -> prox; //como parei no penultimo, mando deletar o ultimo
	aux -> prox = NULL; //agora sim  removo o ultimo elemento;	
}


template <class E>
E ListaLigada<E>::consulta_ultimo(){
    No<E>*aux = cabeça;
    while(aux != NULL){
        aux = aux ->prox;
    }
    return aux ->elem 
}


template <class E>
void ListaLigada<E>::inverte_Lista(){
	ListaLigada<E> aux; // crio uma lista ligada aux 
	No<E>* indice = cabeca; // um indice recebe cabeça 
	while(indice != NULL){
		aux.insere_Inicio(indice -> elem);
		indice = indice -> prox;
	}cabeca = aux.get_cabeca();
	aux.~ListaLigada();
}





