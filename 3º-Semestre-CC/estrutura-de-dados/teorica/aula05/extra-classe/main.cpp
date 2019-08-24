#include <iostream>
#include "vetor.cpp"
#include "natural.cpp"

int main()
{
	Natural x(5);
	Vetor <int> ciranda(10); //crio o vetor com 10 elemetos
	ciranda[2] = 5;
	Vetor <Natural> vet_nat(4);
	vet_nat.insere(x,0);
	std::cout<< vet_nat.elemento(0) << std::endl;
	return 0;

}

// cria um construtor novo de natural novo 
