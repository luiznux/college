#include "func-ponteiros.h"

//função para ordenar o vetor
int minimum(int *a,int n, int k, int loc){
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

void selection(int *a,int n){

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


void preeche_vetor_float(float *vetor, int tamanho){

    int elemento;

    for(int i = 0; i < tamanho; i++){

        std::cout<<"\n Digite um elemento -> ";
        std::cin>> elemento;
        vetor[i] = elemento;
    }
}
void preeche_vetor_int(int *vetor, int tamanho){

    int elemento;

    for(int i = 0; i < tamanho; i++){

        std::cout<<"\n Digite um elemento -> ";
        std::cin>> elemento;
        vetor[i] = elemento;
    }
}


void maximoMinimo(int *v, int N, int *maximo, int *minimo){

    //ordeno o vetor
    selection(v, N);

    *maximo = v[0];
    *minimo = v[N-1];
   //armazeno o maior e o menor elemento
}


void troca(float *a, float *b){

    float *aux;

    aux = a;

    a = b;

    b = aux;
}


float cria_vetores(int T1,int T2){

    float *vetor1 =  new float[T1];

    float *vetor2 =  new float[T2];

    int T3 = T1 + T2;

    float *vetor1_2 = new float[T3];


    preeche_vetor_float(vetor1, T1);

    preeche_vetor_float(vetor2, T2);


    //2 laços para concatenar os vetores
    for(int i = 0; i < T1; i++){

        vetor1_2[i] = vetor1[i];
    }

    for(int j = T1 - 1 ; j < T2; j++){

        vetor1_2[j] = vetor2[j];
    }

    return 0;
}


void printa_vetor_float(float *vetor, int tamanho){

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

void printa_vetor_int(int *vetor, int tamanho){

    std::cout<<"[";

    for(int i = 0; i < tamanho; i++){

        if (i+1 == tamanho)
            std::cout<< vetor[i];
        else
            std::cout<< vetor[i] <<", ";
    }
    std::cout<<"]"<<std::endl;
}





