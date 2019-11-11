#include "stack.h"
#include <iostream>

/*este metodo imprime o vetor, n�o a pilha!*/
void Stack::imprime () {
  int i;
  for(i=0;i<contador;i++)
    std::cout<<vetorpilha[i]<<" ";
}


// Verifica se a pilha é vazia
bool Stack::vazia()
{
  /*Se a Stack esta vazia, retorna true, se nao, retorna false*/
  if(contador>0) return false;
  return true;
}


// Verifica se a pilha esta cheia
bool Stack::cheia(){
    if(tamanho == contador) return true;
    return false;
}


//remove primeiro elemento(tira)
bool Stack::pop(){

    /* ou usando um metodo da classe
   if(ehvazia() == true){
   return false;
    }
    */

  /*Se a Stack nao esta vazia, topo da pilha eh removido.
   Se a pilha esta vazia um codigo de erro de underflow eh retornado*/
  if(contador==0)
     return false;
  else{
    --contador;
    return true;
  }
}


// insere no topo da pilha
bool Stack::push(int item){
    if(cheia() == false)
        return false;
    else{
        vetorpilha[contador] = item;
        contador ++;
        return true;
    }
}


// consulta o primeiro elemento da pilha
bool Stack::top(int &item)
{
  /*Se a Stack nao esta vazia, topo da pilha eh retornado. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado

  if(contador ==0)
     return false;
  else{
     item = vetorpilha[contador-1];
     return true;
  }
  }*/

    if( vazia())
        return false;
    else{
        item = vetorpilha[contador -1];
        return true;
    }
}


bool Stack::equal(Stack &S){

    Stack auxiliar;

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


void Stack::reverse(){
    int x;
    Stack aux;
    Stack aux2;

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

void Stack::inverte_outra_pilha(Stack &S){
    int x;
    Stack aux;

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

/* uso uma pliha aux para para passar da A para aux, e deps da aux para a
   A e A'
*/
void Stack::copia(Stack &S){
    int x;
    Stack aux;
    //laço para colocar na aux a pilha principal
    while(!vazia()){
        top(x);
        pop();
        aux.push(x);
    }

    //laço para tirar da aux e passar para A e A'
    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        S.push(x);
    }


}

void Stack::imprime(){

    int x;
    Stack aux;

    /*laço para desempilhar a pilha original e imprimir, ao mesmo tempo
      que eu salvo os itens desempilhados na pilha aux */
    while(!vazia()){
        top(x);
        std::cout << x;
        pop();
        aux.push(x);
    }

    /*laço para devolver os intens da pilha aux para a original, lembrando
      que a pliha aux estara ao contrario da pilha original,
      exemplo orig 1234, aux 4321 */
    while(!aux.vazia()){
        aux.top(x);
        aux.pop();
        push(x);
    }
}



