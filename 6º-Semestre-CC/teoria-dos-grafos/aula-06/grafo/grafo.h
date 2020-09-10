/*
 * REPRESENTACAO DE GRAFOS - Versao 2020/2
 */
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <memory.h>

#define _BRANCO_  0
#define _CINZA_   1
#define _PRETO_   2


/*
 * Estrutura de dados para representar grafos
 */
typedef struct a{ /* Celula de uma lista de arestas */
	int    nome;
	struct a *prox;
}Aresta;

typedef struct vert{  /* Cada vertice tem um ponteiro para uma lista de arestas incidentes nele */
	int nome;
	int dist;
	int cor;
	Aresta *prim;
}Vertice;

/*
 * Declaracoes das funcoes para manipulacao de grafos
 */
void criaGrafo(Vertice **G, int ordem);
void destroiGrafo(Vertice **G, int ordem);
int  acrescentaAresta(Vertice G[], int ordem, int v1, int v2);
int  calculaTamanho(Vertice G[], int ordem);
void imprimeGrafo(Vertice G[], int ordem);

/* Novas funçoes: */
Vertice *calculaComplemento(Vertice G[], int ordem);
int      grauMinimo(Vertice G[], int ordem);  /* EXERCICIO */
int      grauMaximo(Vertice G[], int ordem);  /* EXERCICIO */
int      eRegular(Vertice G[], int ordem);    /* EXERCICIO */
int      eSimples(Vertice G[], int ordem);    /* EXERCICIO */
