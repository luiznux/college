#include <iostream>

#define tamanho 10

using namespace std;
class Pilha{
     private:
        int contador;
        int vetorpilha[tamanho];
     public:
        Pilha(){
          /*Pre: nenhum
          Pos: a pilha eh inicializada para estar vazia*/
            contador=0;}
        bool ehvazia();
        bool pop();
        bool top(int &item);
        bool push(int item);
        bool equal(Pilha &S);
        void reverse();
        void inverteoutrapilha(Pilha &S);
        void copia(Pilha &);
        void imprime();
};

/*void Pilha::imprime ()
{
  int i;
  for(i=0;i<contador;i++)
    cout<<vetorpilha[i]<<" ";
}*/

bool Pilha::push(int item)
{
  /*Pre: nenhum
  Pos: se a Stack nao esta cheia, um item eh adicionado ao topo da pilha. Se a pilha esta cheia
  1 eh retornado e a pilha nao eh modificada*/
  if(contador>=tamanho)
   return 0;
  else{
   vetorpilha[contador]=item;
   contador++;
   return 1;
  }
}

bool Pilha::pop()
{
  /*Pre: nenhum
  Pos: se a Stack nao esta vazia, topo da pilha eh removido. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado*/
  if(contador==0)
     return false;
  else{
    --contador;
    return true;
  }
}

bool Pilha::top(int &item)
{
  /*Pre: nenhum
  Pos: se a Stack nao esta vazia, topo da pilha eh retornado. Se a pilha esta vazia
  um codigo de erro de underflow eh retornado*/
  if(contador ==0)
     return false;
  else{
     item = vetorpilha[contador-1];
     return true;
  }
}

bool Pilha::ehvazia()
{
  /*Pre: nenhum
  Pos: se a Stack esta vazia, retorna true, se nao, retorna false*/
  if(contador>0) return false;
  return true;
}

bool Pilha:: equal(Pilha &S)
{
    Pilha auxiliar;
    int v1, v2,vaux;
    bool igual=true;
    if(contador==S.contador){
        while(ehvazia()!= true && S.ehvazia()!=true&&igual==1){
               top(v1);
               S.top(v2);
               if(v1!=v2)igual=0;
               else{
                  pop();
                  S.pop();
                  auxiliar.push(v1);
              }
       }
       while(auxiliar.ehvazia()!=true){
              auxiliar.top(vaux);
              push(vaux);
              S.push(vaux);
              auxiliar.pop();
       }
       return igual;
   }
   else return false;
}


void Pilha::reverse()
{

}
void Pilha::inverteoutrapilha(Pilha &S)
{

}

void Pilha::copia(Pilha &P2)
{
     int x;
     Pilha Paux;
     while(!ehvazia()){
        top(x);
        pop();
        Paux.push(x);
     }
     while(!Paux.ehvazia()){
        Paux.top(x);
        Paux.pop();
        P2.push(x);
        push(x);
     }
}

void Pilha::imprime()
{
     int x;
     Pilha Paux;
     while(!ehvazia()){
        top(x);
	cout<< x << " ";
        pop();
        Paux.push(x);
     }
     while(!Paux.ehvazia()){
        Paux.top(x);
        Paux.pop();
        push(x);
     }
}



int main(int argc, char *argv[])
{

  int n,i;
  int item;
  Pilha P1,P2,Paux;
  cout<<"Entre com o numero de elementos para Pilha 1 "; cin>>n;
  if(n<=tamanho){
    for(i=1;i<=n;i++){
       cout<<"\nelemento:";
       cin>>item;
       P1.push(item);
    }
    cout<<endl;
    getchar();
  }
 cout<<"\nEntre com o numero de elementos para Pilha 2 "; cin>>n;
  if(n<=tamanho){
    for(i=1;i<=n;i++){
       cout<<"\nelemento:";
       cin>>item;
       P2.push(item);
    }
    cout<<endl;
  }

  cout<<"P1<< endl;
  P1.imprime();
  cout<<"P2 = "<< endl;
  P2.imprime();
  getchar();
  return 0;
}

