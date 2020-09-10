#include "grafo.h"

/*
 * Implementacao das funcoes para manipulacao de grafos
 */

/*
 * Criacao de um grafo com ordem predefinida (passada como argumento),
 * e, inicilamente, sem nenhuma aresta
 */
void criaGrafo(Vertice **G, int ordem){
	int i;
	*G= (Vertice*) malloc(sizeof(Vertice)*ordem); /* Alca�ao dinamica de um vetor de vertices */

	for(i=0; i<ordem; i++){
		(*G)[i].nome= i;
		(*G)[i].dist= -1;      /* representa INFINITO */
		(*G)[i].cor= _BRANCO_; /* representa nao manipulado*/
		(*G)[i].prim= NULL;    /* Cada vertice sem nenua aresta incidente */
	}
}

/*
 * Deasaloca a memoria dinamica usada para armazenar um grafo.
 */
void destroiGrafo(Vertice **G, int ordem){
	int i;
    Aresta *a, *n;

	for(i=0; i<ordem; i++){ /* Remove lista de adjacencia de cada v�rtice */
	    a= (*G)[i].prim;
        while (a!= NULL){
              n= a->prox;
              free(a);
              a= n;
        }
	}
    free(*G);
}

/*
 * Acrescenta uma nova aresta em um grafo previamente criado.  Devem
 * ser passados os extremos v1 e v2 da aresta a ser acrescentada Como
 * o grafo nao � orientado, para uma aresta com extremos i e j ser�o
 * criadas, na estrutura de dados, arestas (i,j) e (j,i)
 */
int acrescentaAresta(Vertice G[], int ordem, int v1, int v2){
    Aresta * A1, *A2;

	if (v1<0 || v1 >= ordem) /* Testo se v�rtices sao validos */
	   return 0;
	if (v2<0 || v2 >= ordem)
	   return 0;

	/* Acrescento aresta na lista do vertice v1 */
	A1= (Aresta *) malloc(sizeof(Aresta));
	A1->nome= v2;
	A1->prox= G[v1].prim;
	G[v1].prim= A1;

	/* Acrescento aresta na lista do vertice v2 se v2 != v1 */
	if (v1 == v2) return 1;

	A2= (Aresta *) malloc(sizeof(Aresta));
	A2->nome= v1;
	A2->prox= G[v2].prim;
	G[v2].prim= A2;

	return 1;
}

/*
 * Funcao que retorna o tamanho de um grafo
 */
int  calculaTamanho(Vertice G[], int ordem){
	int i;
	int totalArestas=0;

	for (i=0; i<ordem; i++){
		int j;
		Aresta *aux= G[i].prim;
		for(j=0; aux != NULL; aux= aux->prox, j++)
            if (aux->nome == i) j++; /* laco "conta em dobro" */
		totalArestas += j;
	}
	return totalArestas/2 + ordem;
}

/*
 * Imprime um grafo com uma nota��o similar a uma lista de adjacência.
 */
void imprimeGrafo(Vertice G[], int ordem){
	int i;
	Aresta *aux;
	char * cores[]= { "BRANCO", "CINZA " , "PRETO " };

	printf("\nOrdem:   %d",ordem);
	printf("\nTamanho: %d",calculaTamanho(G, ordem));
	printf("\nLista de Adjacencia:\n");

	for (i=0; i<ordem; i++){
		printf("\n    V%d (Distancia:%2d  Cor:%s): ", i, G[i].dist, cores[G[i].cor]);
		aux= G[i].prim;
		for( ; aux != NULL; aux= aux->prox)
			printf("%3d", aux->nome);
	}
	printf("\n\n");
}

/*
 * Funçao auxiliar que recebe um grafo como argumento e um dado
 * vertice e retorna o grau do vertice.
 */
int calculaGrauVertice(Vertice G[], int ordem, int v){
    int j;

    if(v <0 || v >= ordem) return (-1);

    Aresta *aux = G[v].prim;
    for (j = 0 ; aux != NULL; aux = aux->prox, j++ ) {
        if(aux->nome == v) j++;
    }
    return j;
}

/*
 * Funçao que recebe um grafo como argumento e retorna o menor grau
 * dentre os graus dos v�rtices do grafo.
 */
int grauMinimo(Vertice G[], int ordem){
     /* Exercicio */
}

/*
 * Funçao que recebe um grafo como argumento e retorna o menor grau
 * dentre os graus dos v�rtices do grafo.
 */
int grauMaximo(Vertice G[], int ordem){
     /* Exercicio */
}

/*
 * Funçao que recebe um grafo como argumento e retorna:
 * 1, se o grafo for regular
 * 0, caso contr�rio
 */
int eRegular(Vertice G[], int ordem){
     /* Exercicio */
}
