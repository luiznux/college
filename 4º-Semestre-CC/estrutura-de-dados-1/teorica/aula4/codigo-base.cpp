#include <iostream>
#include <stdlib.h>
#define tam 10

using namespace std;
class Fila{
  private:
     int vetorfila[tam];
     int inicio, fim, contador;
  public:
     Fila();
     bool vazia();
     bool cheia();
     bool insere(int item);
     bool remove();
     bool consulta(int &item);
     int tamanho();
     void copia(Fila &F);
     bool iguais(Fila &F);
};

Fila::Fila(){
  contador = 0;
  inicio = 0;
  fim = tam -1;
}

bool Fila::vazia(){
  if(contador == 0)
    return true;
  else
    return false;
}

bool Fila::cheia(){
  if(contador==tam)
    return true;
  else
    return false;
}
bool Fila::insere(int item){
  if(cheia()==true)
    return false; //overflow
  if(fim==tam-1)
    fim = 0;
  else
    fim++;
  vetorfila[fim]=item;
  contador++;
  return true;
}
bool Fila::remove(){
  if(vazia()==true)
    return false;//unverflow
  if(inicio==tam-1)
    inicio = 0;
  else
    inicio++;
  contador--;
  return true;

}
bool Fila::consulta(int &item){
  if(vazia()==true)
    return false;//unverflow
  item = vetorfila[inicio];
  return true;
}
int Fila::tamanho(){
  return contador;
}

void Fila:: copia(Fila &F)
{
     int item;
     Fila Faux;
     while(!vazia())
     {
        consulta(item);
        F.insere(item);
        Faux.insere(item);
        remove();
     }
     while(!Faux.vazia())
     {
        Faux.consulta(item);
        insere(item);
        Faux.remove();
     }
}

bool Fila::iguais(Fila &F)
{

}

int Fila:: tamanho ()
{

}


int main()
{
      int opcao;
      int x;
      Fila F,F2,Fcopy;
      do{
        cout<<"\n\t\t\tFILA\n";
        cout<<"Digite 1 para inserir\n";
        cout<<"Digite 2 para remover\n";
        cout<<"Digite 3 para consultar\n";
        cout<<"Digite 4 para copiar\n";
        cout<<"Digite 0 para sair\n";
        cin>>opcao;
        switch(opcao){
           case 1:cout<<"Digite o elemento:";cin>>x;
                  if(F.insere(x)==1) cout<<"Insercao realizada com sucesso\n";
                  else cout<<"OVERFLOW\n";
                  break;
           case 2: if(F.remove()==0) cout<<"\nUnderflow\n";
                   else  cout<<"Remocao realizada com sucesso";
                  break;
           case 3: if(F.consulta(x)==1) cout<<"\nPrimeiro elemento = "<<x<<endl;
                   else  cout<<"\nUnderflow\n";
                  break;
           case 4: cout<<"Copia para uma fila auxiliar";
                   F.copia(Fcopy);
                  if(F.iguais(Fcopy)==true) cout<<"\nFilas iguais";
                  else cout<<"\nFilas diferentes";
                   break;
           case 0: cout<<"saindo...\n";
                  break;
           default: cout<<"opcao invalida\n";
        }
        system("PAUSE");
        system("CLS");
      }while(opcao!=0);
       return 0;
}

