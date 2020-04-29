#include <iostream>

class Node {

	private:

		Node *esq, *dir;
		int valor, profEsq, profDir;


        public:

		Node(int valor) {
			this->valor = valor;
			this->esq = this->dir = NULL;
			this->profEsq = this->profDir = 0;
		}

		int getValor() {
			return valor;
		}

		Node *getEsq() {
			return esq;
		}

		Node *getDir() {
			return dir;
		}

		int getProfEsq() {
			return profEsq;
		}

		int getProfDir() {
			return profDir;
		}


		void setEsq(Node *no) {
			this->esq = no;
		}


		void setDir(Node *no) {
			this->dir = no;
		}


		void incrementaProfEsq() {
			this->profEsq++;
		}


		void incrementaProfDir() {
			this->profDir++;
		}


		int desequilibrio() {
			return this->profDir - this->profEsq;
		}
};
