#ifndef PILHA_H
#define PILHA_H


#define tamanho 10

class Pilha{

     private:

        //variavel que gerencia os indices
        int contador;

        int vetorpilha[tamanho];

     public:

        Pilha(){
          /* a pilha eh inicializada para estar vazia*/
            contador=0;}

        bool vazia();
        bool cheia();
        bool pop();
        bool top(int &item);
        bool push(int item);
        bool equal(Pilha &S);
        void reverse();
        void inverte_outra_pilha(Pilha &S);
        void copia(Pilha &);
        void imprime();
};

#endif
