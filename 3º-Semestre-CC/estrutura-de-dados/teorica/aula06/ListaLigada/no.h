#ifndef NO_H
#define NO_H

template <typename E>
class ListaLigada;

template <typename E>
class No{
    private:
       E elem; // informação do no
       No<E>* prox; // próximo elemento
       friend class ListaLigada<E>;
};

#endif
