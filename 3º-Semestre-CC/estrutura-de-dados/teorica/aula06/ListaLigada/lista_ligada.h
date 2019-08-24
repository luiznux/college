#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H
#include "no.h"

template <typename E>
class ListaLigada{

    private:
       No<E> * cabeca; // inicio da lista ligada (head)
       
    public:
       ListaLigada();
       ~ListaLigada();
       bool vazia() const;
       const E& inicio() const;
       void insereInicio(const E& e);
       void removeInicio();
       
};

#endif
