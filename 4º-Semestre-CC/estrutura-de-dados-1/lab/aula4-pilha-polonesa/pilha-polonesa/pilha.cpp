#include "pilha.h"
#include <iostream>


Pilha::Pilha(){
  /* a pilha eh inicializada para estar vazia*/
  contador=0;
}


// Verifica se a pilha é vazia
bool Pilha::vazia()
{
  /*Se a Stack esta vazia, retorna true, se nao, retorna false*/
  if(contador>0) return false;
  return true;
}


// Verifica se a pilha esta cheia
bool Pilha::cheia(){
    if(tamanho == contador) return true;
    return false;
}


//remove primeiro elemento(tira)
float Pilha::pop(){

    float aux;

  /*Se a Stack nao esta vazia, topo da pilha eh removido.
   Se a pilha esta vazia um codigo de erro de underflow eh retornado*/
  if(contador==0)
      return -1;

  else{
      aux = vetorpilha[contador];
      contador --;
      return aux;
    }
}


// insere no topo da pilha
bool Pilha::push(float item){
    if(cheia() == false)
        return false;
    else{
        vetorpilha[contador] = item;
        contador ++;
        std::cout << "Inseriu com sucesso" << std::endl;
        return true;
    }
}


// consulta o primeiro elemento da pilha
bool Pilha::top(int &item){
/*Se a Stack nao esta vazia, topo da pilha eh retornado. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado */

  if(contador ==0)
     return false;
  else{
     item = vetorpilha[contador-1];
     return true;
  }

  if( vazia())
        return false;
    else{
        item = vetorpilha[contador -1];
        return true;
    }
}


bool Pilha::equal(Pilha &S){

    Pilha auxiliar;

    int v1, v2,vaux;

    bool igual=true;

    if(contador==S.contador){
        while(vazia()!= true && S.vazia()!=true&&igual==1){
               top(v1);
               S.top(v2);
               if(v1!=v2)igual=0;
               else{
                  pop();
                  S.pop();
                  auxiliar.push(v1);
              }
       }

       while(auxiliar.vazia()!=true){
              auxiliar.top(vaux);
              push(vaux);
              S.push(vaux);
              auxiliar.pop();
       }
       return igual;
   }
    else return false;
}


void Pilha::reverse(){
    int x;
    Pilha aux;
    Pilha aux2;

    while(!vazia()){
        top(x);
        pop();
        aux.push(x);
    }

    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        aux2.push(x);
    }

    while(!aux2.vazia()){
        aux2.top(x);
        aux2.pop();
        push(x);
    }

}

void Pilha::inverte_outra_pilha(Pilha &S){
    int x;
    Pilha aux;

    while(!vazia()){
        top(x);
        pop();
        S.push(x);
        aux.push(x);
    }

    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        push(x);
    }
}



void Pilha::imprime(){
     int x;
     Pilha Paux;
     while(!vazia()){
        top(x);
        std::cout<< x << " ";
        pop();
        Paux.push(x);
     }
     while(!Paux.vazia()){
        Paux.top(x);
        Paux.pop();
        push(x);
     }
}
