/*pequeno exemplo de um programa em C++ - professora Val�ria Farinazzo*/

#include <iostream>
#include <string.h>

using namespace std;

class Mesa{
   private:
       string tipoMaterial;
       float altura;
       float custo;
   public:
       void cadastro(float a,float ct,string tm){
                     altura=a;
                     custo = ct;
                     tipoMaterial = tm;
                     }
       void impressao(){
                     cout<<"altura = "<<altura<<endl;
                     cout<<"custo = "<<custo<<endl;
                     cout<<"Tipo de Material: "<<tipoMaterial<<endl;
                     }
};

int main(int argc, char *argv[])
{
  Mesa M1,M2;
  float a,ct;
  string tm;
  cout<<"\nEste eh um pequeno exemplo de um programa em C++\n";
  cout<<"\nDigite os dados referentes � mesa:\n"<<endl;
  cout<<"Altura:";cin>>a;
  cout<<"Custo:"; cin>>ct;
  cout<<"Tipo de Material:"; cin>>tm;
  M1.cadastro(a,ct,tm);
  cout<<"\nInformacoes da segunda mesa serao dadas pelo sistema:";
  M2.cadastro(1.2,128.50,"Madeira");
  cout<<"\n\nImprimindo dados da Mesa 1:\n"<<endl;
  M1.impressao();
  cout<<"\n\nImprimindo dados da Mesa 2:\n"<<endl;
  M2.impressao();
  system("pause");
  return 0;
}

