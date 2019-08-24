
#include <iostream>
#include "lista_ligada.h"

template <typename E>
ListaLigada<E>::ListaLigada(){
  cabeca=NULL;
}

template <typename E>
ListaLigada<E>::~ListaLigada(){

}

template <typename E>
bool ListaLigada<E>::vazia() const{
    return (cabeca==NULL);
}

template <typename E>
const E& ListaLigada<E>::inicio() const{
   return cabeca->elem;
}
 

template <typename E>
void ListaLigada<E>::insereInicio(const E& e){
   No<E> *novo = new No<E>();
   novo->elem=e;
   novo->prox=cabeca;
   cabeca=novo;
}



template <typename E>
void ListaLigada<E>::removeInicio(){
    if (cabeca!=NULL){
      No<E>* aux=cabeca;
      if (cabeca->prox==NULL)
         cabeca=NULL;
      else{
        cabeca=cabeca->prox;
  
      }
      delete aux;
    }
}
