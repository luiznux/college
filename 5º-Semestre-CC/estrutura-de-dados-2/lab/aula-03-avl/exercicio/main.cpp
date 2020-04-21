#include "avl_tree.cpp"

int main() {
	Arvore arv;
	int reproc = 0;

	do {
		cout << ("\nValor a ser inserido (-1 para sair): ");
		cin >> reproc;
		if(reproc != -1)
			arv.insere(reproc);
	} while(reproc != -1);
	cout << "\n\nArvore:\n";
	arv.emOrdem(arv.getRaiz());

	cout << "\n Vetor:";
	arv.mostraVetorDeInsercao();

	arv.balancea();
	cout << "\n Arvore AVL apos balanceamento: ";
	arv.emOrdem(arv.getRaiz());

	return 0;
}
