#include <iostream>
#include "vetor.h"

template <class T>
Vetor<T>::Vetor(int t)
{
	v=new T[t]; //aloca dinamicamente o vetor
	if(v==NULL){
		throw new std::string("memoria insuficiente");
	}
	tam=t;
}


template <class T>
Vetor<T>::~Vetor()
{
	delete v; //remove a alocação dinamica da memória
}


template <class T>
int Vetor<T>::tamanho()
{
	return tam;
}


template <class  T>
T Vetor<T>::elemento(int i)
{
	if(i<0 || i>= tam){
		throw new std::string("Indice fora do range");
	}return v[i];
}


template <class T>
bool Vetor<T>::procura(T elem)
{
	for(int i=0; tam -1; i++){
		if(v[i]==elem)
			return true;
	}
	return false;
}


template <class T>
void Vetor<T>::insere(T elemento, int i)
{
	if(i < 0 || i>=tam){
		throw new std::string("invalido");
	
	}v[i]=elemento;
}


template <class T>
void Vetor<T>::remove(int i)
{
	if (i < 0 || i >= tam)
		throw new std::string("erro!");
	for (int j=i; j < tam-1; j++)
		v[j] = v[j+1];
	v[tam-1]= NULL;
}	

template<class T>
T &Vetor<T>::operator[](int index)
{
	if (index >= tam || index<0)
		throw new std::string("Erro, fora do range");

	return v[index];

}







