#include "node.cpp"

#define MAX_LENGTH 100

using namespace std;

class Arvore
{

	private:

    /*atributos */
		Node *raiz;
		Node *vetorDeInsercao[MAX_LENGTH];
		int ponteiroDeInsercao;


		void insereNodeVetor(Node *no) {
			vetorDeInsercao[ponteiroDeInsercao] = no;
			ponteiroDeInsercao++;
		}

		Node *rotacaoAEsquerda(Node *no) {
			Node *subarvoreDireita = no->getDir();
			no->setDir(subarvoreDireita->getEsq());
			subarvoreDireita->setEsq(no);
			return subarvoreDireita;
		}

		Node *rotacaoADireita(Node *no) {
			Node *subarvoreEsquerda = no->getEsq();
			no->setEsq(subarvoreEsquerda->getDir());
			subarvoreEsquerda->setDir(no);
			return subarvoreEsquerda;
		}

		void insereAux(Node *no, int valor) {
			if(valor <= no->getValor()) {
				if(no->getEsq() == NULL) {
					Node *novo_no = new Node(valor);
					no->setEsq(novo_no);
					insereNodeVetor(novo_no);
					no->incrementaProfEsq();
				} else {
					no->incrementaProfEsq();
					insereAux(no->getEsq(), valor);
				}
			} else {
				if(no->getDir() == NULL) {
					Node *novo_no = new Node(valor);
					no->setDir(novo_no);
					insereNodeVetor(novo_no);
					no->incrementaProfDir();
				} else {
					no->incrementaProfDir();
					insereAux(no->getDir(), valor);
				}
			}
		}

	public:
		Arvore() {
			raiz = NULL;
			ponteiroDeInsercao = 0;
		}

		Node *getRaiz() {
			return this->raiz;
		}

		void insere(int valor) {
			if(raiz == NULL) {
				raiz = new Node(valor);
				insereNodeVetor(raiz);
			} else {
				insereAux(raiz, valor);
			}
		}

		void emOrdem(Node *no) {
			if(no != NULL) {
				emOrdem(no->getEsq());
				cout << no->getValor() << endl;
				emOrdem(no->getDir());
			}
		}

		void mostraVetorDeInsercao() {
			int i;
			for(i = 0; i < ponteiroDeInsercao; i++) {
				cout << ("\n\n");
				cout << "[" << i << "]: Node " << vetorDeInsercao[i]->getValor();
				cout << "\nProfundidade esq: " << vetorDeInsercao[i]->getProfEsq();
				cout << "\nProfundidade dir: " << vetorDeInsercao[i]->getProfDir();
				cout << "\nDesequilibro: " << vetorDeInsercao[i]->desequilibrio();
			}
		}

		void balancea() {
			int i;
			for(i = 0; i < this->ponteiroDeInsercao; i++) {
				if(this->vetorDeInsercao[i]->desequilibrio() >= 2) {
					this->vetorDeInsercao[i] = this->rotacaoAEsquerda(this->vetorDeInsercao[i]);
				}
				else if(this->vetorDeInsercao[i]->desequilibrio() <= -2) {
					this->vetorDeInsercao[i] = this->rotacaoADireita(this->vetorDeInsercao[i]);
				}
			}
		}

};
