#ifndef STACK_H
#define STACK_H

//tamanho fixo
#define tamanho 10

class Stack{

     private:

        //variavel que gerencia os indices
        int contador;

        int vetorpilha[tamanho];

     public:

        Stack(){
          /* a pilha eh inicializada para estar vazia*/
            contador=0;}

        bool vazia();
        bool cheia();
        bool pop();
        bool top(int &item);
        bool push(int item);
        bool equal(Stack &S);
        void reverse();
        void inverte_outra_pilha(Stack &S);
        void copia(Stack &);
        void imprime();
};

#endif
