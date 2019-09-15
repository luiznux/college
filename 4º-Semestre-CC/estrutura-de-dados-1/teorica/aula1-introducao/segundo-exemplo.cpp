/*pequeno exemplo de um programa em C++ - professora Val�ria Farinazzo*/

#include <iostream>
#include <string.h>

using namespace std;

class Ponto2D{
   private:
       float coordX;
       float coordY;
   public:
       void configuraPonto(float x,float y){
                     coordX=x;
                     coordY=y;
                     }
       void imprimePonto(){
                     cout<<"coordenada X = "<<coordX<<endl;
                     cout<<"coordenada Y = "<<coordY<<endl;
                    }
};

int main()
{
  Ponto2D P1,P2,P3;
  float x,y;
  cout<<"\nEste eh um pequeno exemplo de um programa em C++\n";
  cout<<"Digite as coordenadas do Ponto"<<endl;
  cout<<"Coordenada X:";cin>>x;
  cout<<"Coordenada Y:";cin>>y;
  P1.configuraPonto(x,y);
  P2.configuraPonto(1.2,3.5);
  cout<<"Digite as coordenadas do Ponto"<<endl;
  cout<<"Coordenada X:";cin>>x;
  cout<<"Coordenada Y:";cin>>y;
  P3.configuraPonto(x,y);
  cout<<"Imprimindo dados do primeiro ponto:"<<endl;
  P1.imprimePonto();
  cout<<"Imprimindo dados do segundo ponto:"<<endl;
  P2.imprimePonto();
  cout<<"Imprimindo dados do terceiro ponto:"<<endl;
  P3.imprimePonto();
  system("pause");
  return 0;
}

