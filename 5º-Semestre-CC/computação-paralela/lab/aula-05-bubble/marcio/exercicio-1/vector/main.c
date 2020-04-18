#include <stdio.h>
#include <time.h>
#include <omp.h>
#include "vector.h"

const int TAM = 200;


/* bubble sort para ordenar os vetores */
//void bubble_sort(int list[], int n){
//  long c, d, t;
//  for (c = 0 ; c < n - 1; c++) {
//    for (d = 0 ; d < n - c - 1; d++) {
//      if (list[d] > list[d+1]) {

//      }
//    }
//  }
//}

void bubble_sort(int *vector, int tam){
    for(int i = 0; i < tam; i++){
        for(int j = i; j < tam; j++ ){
            if( vector[i] > vector[j]){
                 /* Swapping */
                 int  t      = vector[i];
                 vector[i]   = vector[j];
                 vector[j] = t;
            }
        }
    }
}


int main(){

    int ** vector = calloc_matrix(7, TAM);
    fills_rand_vector(vector, 7,TAM, 30);


/*----------------- nao paralelo ------------------*/

     clock_t inicio_ruim = clock();

     for(int i = 0; i < 5; i++){
         for(int j = 0; i < TAM; i++)
             bubble_sort(&vector[i][j],TAM);
     }

     clock_t final_ruim = clock();

/*----------------- paralelo ----------------------*/

//     clock_t inicio_bom = clock();
//
//     #pragma  omp parallel num_threads(3)
//     {
//         #pragma omp for
//         for(int i = 5; i < 8; i++){
//             for(int j = 0; i < TAM; i++){
//                 bubble_sort(&vector[i][j],TAM);
//             }
//         }
//     }
//
//     clock_t final_bom = clock();


/*-----------------Conclusão----------------------*/

        const double tempo_ruim_gasto = (double) (final_ruim - inicio_ruim) / CLOCKS_PER_SEC;
     //    const double tempo_bom_gasto  = (double) (final_bom - inicio_bom) / CLOCKS_PER_SEC;

     printf(" O tempo s/ paralelização é, %lf segundos \n", tempo_ruim_gasto);
     // printf(" O tempo c/ paralelização é, %lf segundos \n", tempo_bom_gasto);

    return 0;
}
