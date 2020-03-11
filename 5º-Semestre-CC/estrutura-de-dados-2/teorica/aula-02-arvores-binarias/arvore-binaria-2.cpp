#include <iostream>
using namespace std;

class No
{
private:
	No *esq, *dir;
	int chave;

public:
	No(int chave)
	{
		this->chave = chave;
		esq = NULL;
		dir = NULL;
	}

	int getChave()
	{
		return chave;
	}

	// fun��es getters e setters

	No* getEsq()
	{
		return esq;
	}

	No* getDir()
	{
		return dir;
	}

	void setEsq(No *no)
	{
		esq = no;
	}

	void setDir(No *no)
	{
		dir = no;
	}
};

class Arvore
{
private:
	No *raiz;

public:
	Arvore()
	{
		raiz = NULL;
	}

	void inserir(int chave)
	{
		if(raiz == NULL) // verifica se a �rvore est� vazia
			raiz = new No(chave); // cria um novo n�
		else
			inserirAux(raiz, chave);
	}

	void inserirAux(No *no, int chave)
	{
		// se for menor, ent�o insere � esquerda
		if(chave < no->getChave())
		{
			// verifica se a esquerda � nulo
			if(no->getEsq() == NULL)
			{
				No *novo_no = new No(chave);
				no->setEsq(novo_no); // seta o novo_no � esquerda
			}
			else
			{
				// sen�o, continua percorrendo recursivamente
				inserirAux(no->getEsq(), chave);
			}
		}
		// se for maior, ent�o insere � direita
		else if(chave > no->getChave())
		{
			// verifica se a direita � nulo
			if(no->getDir() == NULL)
			{
				No *novo_no = new No(chave);
				no->setDir(novo_no); // seta o novo_no � direita
			}
			else
			{
				// sen�o, continua percorrendo recursivamente
				inserirAux(no->getDir(), chave);
			}
		}
		// se for igual, n�o vai inserir
		// n�o pode existir 2 chaves iguais
	}

	No* getRaiz()
	{
		return raiz;
	}

	void imprimeRaiz()
	{
		cout<< "\n raiz = "<<raiz->getChave();
	}


	void setRaiz(No *no)
	{
		raiz = no;
	}


	void emOrdem(No* no)
	{
		if(no != NULL)
		{
			emOrdem(no->getEsq());
			cout << no->getChave() << " ";
			emOrdem(no->getDir());
		}
	}

	No * removeraiz (No *r) {
  	  No *p, *q;
    	  if (r->getEsq() == NULL) {
       	  	q = r->getDir();
       		free (r);
       		return q;
    	 }
    	 p = r; q = r->getEsq();
    	 while (q->getDir() != NULL) {
     	 	p = q; q = q->getDir();
    	 }
    // q � n� anterior a r na ordem e-r-d
    // p � pai de q
   	if (p != r) {
       		p->setDir(q->getEsq());
       		q->setEsq(r->getEsq());
    	}
    	q->setDir(r->getDir());
    	free (r);
    	return q;
  }
};

int main(int argc, char *argv[])
{
	Arvore arv;

	// insere as chaves
	arv.inserir(8);
	arv.inserir(3);
	arv.inserir(10);
	arv.inserir(14);
	arv.inserir(13);
	arv.inserir(1);
	arv.inserir(6);
	arv.inserir(4);
	arv.inserir(7);

	// percorre em ordem iniciando da raiz
	cout << "\nPercorrendo em ordem...\n";
	arv.emOrdem(arv.getRaiz());

    arv.imprimeRaiz();
    
	arv.setRaiz(arv.removeraiz(arv.getRaiz()));
    arv.imprimeRaiz();

	cout << "\nPercorrendo em ordem...\n";
 
	arv.emOrdem(arv.getRaiz());

	
	return 0;
}

