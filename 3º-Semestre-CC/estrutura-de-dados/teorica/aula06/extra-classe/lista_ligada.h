#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H
#include "no.h"

template <class E>
class ListaLigada
{
	private:
		No<E> *cabeca; //inicio da lista ligada (head)

	public:
		ListaLigada();
		~ListaLigada();
		No<E>* get_cabeca();
		bool vazia()const;
		const E& inicio() const;
		void insere_Inicio(const E& e);
		void remove_Inicio();
		void insere_Final(elemento);
		void remove_ultimo();
		E consulta_ultimo();
		void inverte_Lista();
};

#endif 
