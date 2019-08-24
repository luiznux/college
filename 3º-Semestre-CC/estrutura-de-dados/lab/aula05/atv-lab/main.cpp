#include "vetor.cpp"
//include "vetor.h"
#include <iostream>
#include <stdlib.h>
int main()
{
	Vetor<int> v(10);
	Vetor<int> n(10);

	for(int i= 0; i < v.tamanho(); i++)
		v.insere(i,i);

	for(int j = 0; j < n.tamanho(); j++)
		n.insere(j,j);

	v.agrupamento(n);

	for(int k = 0; k < v.tamanho(); k++)
		std::cout<< v.elemento(k);
return 0;
}
