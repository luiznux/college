#include "fila.h"
#include <iostream>
#include <stdlib.h>

using namespace std;


Fila::Fila(){

  contador = 0;

  inicio = 0;

  fim = tam -1;
}


//verifica se é vazia
bool Fila::vazia(){

  if(contador == 0)
    return true;

  else
    return false;
}


//verifica se é cheia
bool Fila::cheia(){

  if(contador == tam)
    return true;

  else
    return false;
}


// insere um item na fila do tipo inteiro
bool Fila::insere(int item){

  if(cheia() == true)

    return false; //overflow

  if(fim == tam -1)

    fim = 0;

  else

    fim++;

  vetorfila[fim]=item;
  contador++;

  return true;
}


// remove um elemento da fila
bool Fila::remove(){

  if(vazia() == true)

    return false;//unverflow

  if(inicio == tam-1)
    inicio = 0;

  else

    inicio++;
  contador--;
  return true;

}


//
bool Fila::consulta(int &item){

  if(vazia() == true)

    return false;//unverflow

  item = vetorfila[inicio];

  return true;
}


int Fila::tamanho(){

  return contador;
}


void Fila::copia(Fila &F){

     int item;

     Fila Faux;

     while(!vazia()){

        consulta(item);
        F.insere(item);
        Faux.insere(item);
        remove();
     }

     while(!Faux.vazia()){

        Faux.consulta(item);
        insere(item);
        Faux.remove();
     }
}


bool Fila::iguais(Fila &F){
}


int Fila:: tamanho (){
}



