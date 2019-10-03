#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;
struct Node {
// data members
     int info;
     Node *proximo;
    // constructors
     Node(int item=0, Node *novoend = NULL){
       info = item;
       proximo = novoend;
     }
};

class Pilha {
     private:
        Node *topo;
     public:
        Pilha( ){
                  /*Pre: nenhum
                  Pos: a pilha eh inicializada para estar vazia*/
                  topo=NULL;
          }
        ~Pilha();
        bool empty( );
        bool push(int item);
        bool pop( );
        bool top(int &item) ;
};

bool Pilha ::empty( )
{
   if(topo==NULL)
     return true;
   else
     return false;
}


bool Pilha :: push( int item)
{
   Node *novo_topo = new Node(item, topo);
   if (novo_topo == NULL) return false;
   topo = novo_topo;
   return true;
}

bool Pilha :: pop( )
{
   Node *velho_topo = topo;
   if (topo == NULL) return false;
   topo = velho_topo->proximo;
   delete velho_topo;
   return true;
}
bool Pilha :: top(int &item)
{
  /*Pre: nenhum
  Pos: se a Pilha nao estah vazia, topo da pilha eh retornado. Se a pilha estah vazia
  um codigo de erro de underflow eh retornado*/
   if (topo == NULL) return false;
   item = topo->info;
   return true;
}

Pilha :: ~Pilha( ) // Destructor
/* Post: A Pilha é limpa*/
{
while (!empty( ))
pop( );
}

int main(int argc, char *argv[])
{
  int opcao;
  int item;
  Pilha P;
  do{
    cout<<"\n1 - inserir na pilha\n2 - remover  \n3 - consultar\n0 - sair";
    cin>>opcao;
    switch(opcao){
       case 1:
               cin>>item;
               P.push(item);
               break;
       case 2:
                  P.pop();

                 break;
       case 3:
                   if(P.top(item))
                   cout<<item<<" ";
                   break;

     }
  }while(opcao!=0);
  system("PAUSE");
  return 0;
}
