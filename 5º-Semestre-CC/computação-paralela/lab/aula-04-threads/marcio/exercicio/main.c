/*  Luiz Fernando Tagliaferro - 31861806
    Feito em conjunto com:
    Bruno Severo Camilo - 41781619
    João Pedro Colafati Pedroso - 31819656
    Natália Gama de Mattos - 31887201
    Wanderson Bezerra de Lima - 31895591
    Matheus Soares Santos -  31895263
*/

#include <stdio.h>
#include <pthread.h>
#include <time.h>
#include <stdlib.h>

#define TAM 50
#define NUM_THREADS 4

typedef struct param {
  int contador;
  int totalizador;
  int gerador;
  int linha;
  int coluna;
} Param;

int** matriz;
int farol;
Param p;

int counter;

pthread_mutex_t bloqueioValores;
pthread_mutex_t bloqueioFarol;

/*
Preenche matriz em dez posições aleatorias (linha e coluna)
Com um numero aleatorio(de 0 a 10)
*/
void imprimir(int** matrix){
  int i,j;
  for (i =0; i<TAM;i++){
    for (j =0; j<TAM;j++){
      printf("%d ", matrix[i][j]);
    }
    printf("\n");
  }
}

void preparacao() {
  /* Inicializa matriz com 0 */
  matriz = (int **) calloc (TAM, sizeof(int *));
  int i;
  for(i = 0; i < TAM; i++){
    matriz[i] = (int*) calloc(TAM, sizeof(int));
  }

  /* Imprime matriz inicializada */
  imprimir(matriz);
  for(i = 0; i < 10; i++){
    int c = rand() % TAM;
    int l = rand() % TAM;
    if (matriz[l][c] == 0){
      matriz[l][c] = (rand() % 10) + 1;
    }
    else {
      i--;
    }
  }

  /* Imprime matriz com números aleatórios */
  printf("\n");
  imprimir(matriz);

  /* Inicializa farol com 10 */
  farol = 10;
}

void * funcao(void *args){
  Param * p  = (Param *) args;
  Param * result = malloc(sizeof(Param));

  result->contador = 0;
  result->coluna = 0;
  result->linha = 0;
  result->totalizador = 0;
  result->gerador = 0;
  while(farol != 0) {
    //random espaço da matri
    int l = rand()%((p->linha)+25);
    int c = rand()%((p->coluna)+25);

    if(l >= p->linha && c >= p->coluna) {
      //verifica se esta ocupada
      if (matriz[l][c] != 0){
        pthread_mutex_lock(&bloqueioValores);
        if (matriz[l][c] != 0){
          (result->contador)++;
          result->totalizador += matriz[l][c];
          matriz[l][c] = 0;
          pthread_mutex_unlock(&bloqueioValores);

          pthread_mutex_lock(&bloqueioFarol);
          farol--;
          pthread_mutex_unlock(&bloqueioFarol);

        } else {
          pthread_mutex_unlock(&bloqueioValores);
        }
      }
    }
  }

  return (void*) result;
}

int main() {
  preparacao();

  //parametros segundo quadrante
  Param p1;
  Param p2;
  Param p3;
  Param p4;
  Param *result1;
  Param *result2;
  Param *result3;
  Param *result4;
  //preenchendo as variaveis

  /*linha 0->24, coluna 0->24;
    linha 25->49,coluna 0->24;
    linha 0->24, coluna 25->49;
    linha 25->49, coluna 25->49.
  */

  p1.contador = 0;
  p1.totalizador = 0;
  p1.gerador = rand() % 30;
  p1.linha = 0;
  p1.coluna= 0;

  p2.contador = 0;
  p2.totalizador = 0;
  p2.gerador = rand() % 30;
  p2.linha = 25;
  p2.coluna = 0;

  p3.contador = 0;
  p3.totalizador = 0;
  p3.gerador = rand() % 30;
  p3.linha = 0;
  p3.coluna = 25;

  p4.contador = 0;
  p4.totalizador = 0;
  p4.gerador = rand() % 30;
  p4.linha = 25;
  p4.coluna = 25;

  /* Cria e dispara as 4 threads */
  pthread_t th1;
  pthread_t th2;
  pthread_t th3;
  pthread_t th4;

  if (pthread_mutex_init(&bloqueioValores, NULL) != 0) {
    printf("\n mutex init failed\n");
    return 1;
  }

  if (pthread_mutex_init(&bloqueioFarol, NULL) != 0) {
    printf("\n mutex init failed\n");
    return 1;
  }


  pthread_create(&th1,NULL,funcao, &p1);
  pthread_create(&th2,NULL,funcao, &p2);
  pthread_create(&th3,NULL,funcao, &p3);
  pthread_create(&th4,NULL,funcao, &p4);

  printf ("\nThreads criadas.\n\n");

  pthread_join(th1, (void **)&result1);
  pthread_join(th2, (void **)&result2);
  pthread_join(th3, (void **)&result3);
  pthread_join(th4, (void **)&result4);

  pthread_mutex_destroy(&bloqueioValores);
  pthread_mutex_destroy(&bloqueioFarol);

  printf("\nTotalizador 1: %d", result1->totalizador);
  printf("\nContador 1: %d", result1->contador);
  printf("\nMédia 1: %.2f\n", (double)(result1->totalizador)/(result1->contador));

  printf("\nTotalizador 2: %d", result2->totalizador);
  printf("\nContador 2: %d", result2->contador);
  printf("\nMédia 2: %.2f\n", (double)(result2->totalizador)/(result2->contador));

  printf("\nTotalizador 3: %d", result3->totalizador);
  printf("\nContador 3: %d", result3->contador);
  printf("\nMédia 3: %.2f\n", (double)(result3->totalizador)/(result3->contador));

  printf("\nTotalizador 4: %d", result4->totalizador);
  printf("\nContador 4: %d", result4->contador);
  printf("\nMédia 4: %.2f\n", (double)(result4->totalizador)/(result4->contador));

  int total = result1->totalizador + result2->totalizador + result3->totalizador + result4->totalizador;
  int contador = result1->contador + result2->contador + result3->contador + result4->contador;

  printf("\nTotalizador Geral: %d", total);
  printf("\nContador Geral: %d", contador);
  printf("\nMédia Geral: %.2f\n", (double)total/contador);
  return 0;
}
