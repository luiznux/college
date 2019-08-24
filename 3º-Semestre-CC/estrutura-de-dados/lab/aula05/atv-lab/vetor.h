#ifndef VETOR_H
#define VETOR_H

template <typename T>

class Vetor
{
	private:
		T* v; //vetor do elemento do tipo T
		int tam; //tamanho do vetor

	public:
		Vetor(int t);
		~Vetor();
		int tamanho();
		T elemento(int i);
		bool procura(T elem);
		void insere(T d, int i);
		void remove(int i);
		T &operator[](int index);
		void agrupamento(Vetor<T> adicionado);
};


#endif

