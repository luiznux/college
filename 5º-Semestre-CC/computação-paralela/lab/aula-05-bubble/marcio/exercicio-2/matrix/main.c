#include <time.h>
#include <omp.h>
#include "matrix.h"

const int TAM = 1000;

int main(){

   //crio e populo a matriz com numeros aleatorios
   int  **matrix = calloc_matrix(TAM, TAM);
   fills_rand_matrix(matrix, TAM, TAM, 20);


/*----------------------- sem paralelização -----------------*/

   clock_t inicio_ruim = clock();
   int value = 7;
   int count = 0;
   for(int i = 0; i < TAM; i++){
       for(int j = 0; j < TAM; j++){
           if(matrix[i][j] > value) count++;
       }
   }
   clock_t final_ruim  = clock();


/*----------------------- com paralelização ----------------*/

   //crio as 8 variaveis de tempo
   clock_t inicio_bom_1 ;
   clock_t inicio_bom_2 ;
   clock_t inicio_bom_3 ;
   clock_t inicio_bom_4 ;
   clock_t fim_bom_1 ;
   clock_t fim_bom_2 ;
   clock_t fim_bom_3 ;
   clock_t fim_bom_4 ;

   int count2 = 0;
   int count3 = 0;
   int count4 = 0;
   int count5 = 0;

#pragma omp parallel sections{
//quadrante superior esquerdo
#pragma omp section{

   inicio_bom_1 = clock();
   for(int i = 0; i < TAM/2; i++){
       for(int j = 0; j < TAM/2; j++){
           if(matrix[i][j] > value) count2++;
       }
   }
   fim_bom_1 = clock();
}

//quadrante superior direito
#pragma omp section{
   inicio_bom_2 = clock();
   for(int i = 0; i < TAM/2; i++){
       for(int j = TAM/2; j < TAM; j++){
           if(matrix[i][j] > value) count2++;
       }
   }
}
//quadrante inferiro esuqrdo
#pragma omp section

   inicio_bom_2 = clock();
for(int i = TAM/2; i < TAM; i++){
       for(int j = 0; j < TAM/2; j++){
           if(matrix[i][j] > value) count2++;
       }
   }
}
#pragma omp section

for(int i = TAM/2; i < TAM; i++){
       for(int j = TAM/2; j < TAM; j++){
           if(matrix[i][j] > value) count2++;
       }
   }


   clock_t final_bom  = clock();
}

/*--------------------- Conclusão ---------------------------*/

   //calculo o tempo de execução dos codigos
    const double tempo_ruim = (double) (final_ruim - inicio_ruim) / CLOCKS_PER_SEC;
diferenca de cada um e soma todos pega a soma / CLOCKS_PER_SEC;

    printf("O tempo s/ paralelização é %lf segundos \n",tempo_ruim);
    printf("O tempo c/ paralelizaçãoé %lf segundos \n",tempo_bom);

    return 0;
}
