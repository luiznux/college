#include "grafo.h"

/*
 * Programinha simples para testar a representacao de grafo
 */
int main(int argc, char *argv[]) {

	Vertice *G;
	int ordemG= 6;

	Vertice *C;
	int ordemC;

	criaGrafo(&G, ordemG);
	/* acrescentaAresta(G,ordemG,0,0); */
	acrescentaAresta(G,ordemG,3,4);
	acrescentaAresta(G,ordemG,4,3);
	acrescentaAresta(G,ordemG,4,2);
	acrescentaAresta(G,ordemG,5,4);
	acrescentaAresta(G,ordemG,2,3);
	acrescentaAresta(G,ordemG,3,0);

	imprimeGrafo(G, ordemG);

	destroiGrafo(&G, ordemG);
    system("PAUSE");
	return 0;
}
