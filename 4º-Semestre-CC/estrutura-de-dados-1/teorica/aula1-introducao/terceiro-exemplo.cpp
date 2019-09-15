/*pequeno exemplo de um programa em C++ - professora Val�ria Farinazzo*/

#include <iostream>
#include <string.h>

using namespace std;

#define TAM 6

class Aluno{
   private:
       char Nome[30];
	   char TIA[15];
       float nota[TAM];
       float media;
   public:
       void cadastro(char *n, char *t, float v[]){
		   strcpy(Nome, n);
		   strcpy(TIA, t);
		   for(int i = 0; i< TAM; i++)
			   nota[i] = v[i];
	   }
	   void calculoMedia(float v[]){
		   for(int i = 0; i< TAM; i++){
			   media = media + v[i];
		   }
		   media = media/TAM;
	   }
					 
       void impressao(){
                     cout<<"Nome = "<<Nome<<endl;
                     cout<<"TIA = "<<TIA<<endl;
					 cout<<"Notas parciais = ";
					 for(int i = 0; i< TAM; i++)
						 cout<< nota[i]<< " ";
                     cout<<"\nMedia: "<<media<<endl;
                     }
};

int main(int argc, char *argv[])
{
  Aluno A1,A2;
  float vetor[TAM];
  //string n, t;
  char n[30], t[15];
  cout<<"\nEste eh um pequeno exemplo de um programa em C++\n";
  cout<<"\nDigite os dados referentes ao aluno:\n"<<endl;
  cout<< "\nDigite o nome: ";
  cin>>n;
  cout<<"\nDigite o TIA: ";
  cin>>t;
  cout<<"\n Digite as notas parciais: ";
  for(int i = 0; i< TAM; i++){
      cout<<"\n Nota "<<(i+1)<<" ";
	  cin>>vetor[i];
  }
  A1.cadastro(n, t, vetor);
  A1.calculoMedia(vetor);
  A1.impressao();
  
  system("pause");
  return 0;
}

