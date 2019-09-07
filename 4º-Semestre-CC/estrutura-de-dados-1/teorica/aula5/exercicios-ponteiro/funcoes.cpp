
/* Enunciado do Exercicio de ponteiro

   Faca um programa, utilizando funçõe e alocação dinamica de memoria.

   a) calcula a media de um vetor de inteiros de tamanho dado pelo usuario

   b) Achar o maior elemento deste vetor

   c) ordenar este vetor
===========================================================================
*/

#include "funcoes.h"

// função para alocar o vetor de acordo coma entrada do usuario
int &aloca_vetor(int tamanho){

    int *ponteiro_vetor = new int[tamanho];

    std::cout<<"Vetor alocado com sucesso! \n";

    return *ponteiro_vetor;

}


/*função para preecher um vetor e tem como parametros um endereço de
  memoria de um vetor e o tamanho do mesmo
*/
void preeche_vetor(int *vetor, int tamanho){

    int elemento;

    for(int i = 0; i < tamanho; i++){

        std::cout<<"\n Digite um elemento -> ";
        std::cin>> elemento;
        vetor[i] = elemento;
    }

}

//função para imprimir um vetor de inteiros
void printa_vetor(int *vetor, int tamanho){

    std::cout<<"[";

    for(int i = 0; i < tamanho; i++){

        if(i+1 == tamanho){
            std::cout<< vetor[i];
        }
        else
        std::cout<< vetor[i] <<", ";
    }
    std::cout<<"]"<<std::endl;
}


/*função que calcula a media e tem parametros o tamanho do vetor e um
endereço de memoria de um vetor
*/
float media_vetor(int tamanho,int *vetor){

    float soma = 0;
    int cont = 0;
    for(int i = 0 ; i < tamanho; i++){
        soma += vetor[i];
        cont ++;
    }

    soma = soma/cont;

    return soma;
}


/* função para encontrar o maior elemento de um vetor e tem com parametros
   um endereço de memoria de um vetor e o tamanho do mesmo
*/
int maior_elemento(int *vetor, int tamanho){

    int maior=0;

    for(int i=0; i < tamanho;i++){



        if(vetor[i] > maior) maior = vetor[i];
    }
    return maior;
}



int minimum(int *a,int n, int k, int loc)
{
    loc=k;
    int min=a[k];
    for(int i=k;i<n;i++)
    {
        if(a[i]<min)
        {
            min=a[i];
            loc=i;
        }
    }
    return loc;
}


void selection(int *a,int n)
{
    int loc=-1,k;
    for(k=0;k<n-1;k++)
    {
        int loc1=minimum(a,n,k,loc);
        int temp=a[k];
        a[k]=a[loc1];
        a[loc1]=temp;
    }
    for(k=0;k<n;k++)
        std::cout<<a[k]<<" ";
}
