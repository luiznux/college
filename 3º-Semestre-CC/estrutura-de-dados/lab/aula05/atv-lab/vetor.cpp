#include "vetor.h"
#include <iostream>
#include <stdlib.h>

template <typename T>
Vetor<T>::Vetor(int t)
{
	v=new T[t]; //aloca dinamicamente o vetor
	if(v==NULL){
		throw new std::string("memoria insuficiente");
	}
	tam=t;

}

template <typename T>
Vetor<T>::~Vetor()
{
	delete v; //remove a alocação dinamica da memória
}


template <typename T>
int Vetor<T>::tamanho()
{
	return tam;
}


template <typename T>
T Vetor<T>::elemento(int i)
{
	if(i<0 || i>= tam){
		throw new std::string("Indice fora do range");
	}return v[i];
}


template <typename T>
bool Vetor<T>::procura(T elem)
{
	for(int i=0; tam -1; i++){
		if(v[i]==elem)
			return true;
	}
	return false;
}


template <typename T>
void Vetor<T>::insere(T elemento, int i)
{
	if(i < 0 || i>=tam){
		throw new std::string("invalido");
	
	}v[i]=elemento;
}


template <typename T>
void Vetor<T>::remove(int i)
{
	if (i < 0 || i >= tam)
		throw new std::string("erro!");
	for (int j=i; j < tam-1; j++)
		v[j] = v[j+1];
	v[tam-1]= NULL;
}	


template<typename T>
T &Vetor<T>::operator[](int index)
{
	if (index >= tam || index<0)
		throw new std::string("Erro, fora do range");

	return v[index];

}


template <typename T>
void Vetor<T>::agrupamento(Vetor<T> adicionado)
{
        int i; //para controlar o indice do vetor agrupado p/ o segundo for

        Vetor<T> agrupado(tam + adicionado.tamanho());

        for(i = 0; i < tam; i++) {

            std::cout << "estou inserindo o elemento i: " << elemento(i) << std::endl;
            agrupado.insere(elemento(i), i); //estou add no vetor novo agrupado, o elemnto
                                            //do vetor que ja esta dentro da classe 

        }

        for(int j = 0; j < adicionado.tamanho(); j++){ // para o j començar de onde o i parou!

            agrupado.insere(adicionado.elemento(j), i + j); // add o elemento de adicionado no agrupado

        }
        
        delete v; //remover da memoria o vetor alocado dentro da classe 
                  //para poder criar um novo do tamanho dos dois agrupados

        v = new T[tam + adicionado.tamanho()];

        tam += adicionado.tamanho(); //atualizando o tamanho para o novo tamanho 
                                     //do vetor da junção dos dois       

        for(int k = 0; k < tam; k++){
            insere(agrupado.elemento(k), k); //o novo v recebe cada elemento do vetor agrupado
        }
}


