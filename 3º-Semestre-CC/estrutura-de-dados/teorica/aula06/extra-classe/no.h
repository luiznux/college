#ifndef NO_H
#define NO_H

template <class E>
class ListaLigada;

template <typename E>
class No
{
	private:
		E elem; // infromação do no
		No<E> *prox; //proximo elemento
		friend class ListaLigada<E>;
};

#endif
