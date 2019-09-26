#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

struct Node {
	// data members
	int info;
	Node * proximo;
	// constructors
	Node(int item = 0, Node * novoend = NULL) {
		info = item;
		proximo = novoend;
	}
};

class Pilha {
	private:
	Node * topo;
	public:
	Pilha( ) {
		/*Pre: nenhum
		Pos: a pilha eh inicializada para estar vazia*/
		topo = NULL;
	}
	~Pilha();
	bool isEmpty( );
	bool push(int);
	bool pop( );
	bool top(int & ) ;
	void clear();
	bool maior1(int & );
	bool maior2(int & );
	void copy1(Pilha & );
	void copy2(Pilha & );
	void print ();
};

bool Pilha ::isEmpty( ) {
	if(topo == NULL)
		return true;
	else
		return false;
}


bool Pilha :: push( int item) {
	Node * novo_topo = new Node(item, topo);
	if (novo_topo == NULL) return false;
	topo = novo_topo;
	return true;
}

bool Pilha :: pop( ) {
	Node * velho_topo = topo;
	if (topo == NULL) return false;
	topo = velho_topo->proximo;
	delete velho_topo;
	return true;
}
bool Pilha :: top(int & item) {
	/*Pre: nenhum
	Pos: se a Pilha nao estah vazia, topo da pilha eh retornado. Se a pilha estah vazia
	um codigo de erro de underflow eh retornado*/
	if (topo == NULL) return false;
	item = topo->info;
	return true;
}

Pilha :: ~Pilha( ) // Destructor
/* Post: A Pilha é limpa*/
{
	while (!isEmpty( ))
		pop( );
}

void Pilha:: clear() {
	while(pop());
}

bool Pilha::maior1(int & item) {
	int x;
	Pilha Aux;
	if (isEmpty())
		return false;
	top(item);
	while(!isEmpty()) {
		top(x);
		if(x > item) item = x;
		Aux.push(x);
		pop();
	}
	while(!Aux.isEmpty()) {
		Aux.top(x);
		push(x);
		Aux.pop();
	}
	return true;
}


bool Pilha::maior2(int & item) {
	if (isEmpty())
		return false;
	Node * temp = topo;
	int x;
	item = topo->info;
	while(temp != NULL) {
		x = temp->info;
		if(x > item) item = x;
		temp = temp->proximo;
	}
	return true;

}

void Pilha::copy1(Pilha & P2) {
	Pilha Aux;
	int x;
	while(!isEmpty()) {
		top(x);
		Aux.push(x);
		pop();
	}
	while(!Aux.isEmpty()) {
		Aux.top(x);
		push(x);
		P2.push(x);
		Aux.pop();
	}
}

void Pilha::copy2(Pilha & P2) {
	Pilha Aux;
	int x;
	Node * temp = topo;
	while(temp != NULL) {
		Aux.push(temp->info);
		temp = temp->proximo;
	}
	while(!Aux.isEmpty()) {
		Aux.top(x);
		P2.push(x);
		Aux.pop();
	}
}

void Pilha::print() {
	Node * temp = topo;
	cout << "\nPILHA = ";
	while(temp != NULL) {
		cout << temp->info << " ";
		temp = temp->proximo;
	}
}


int main(int argc, char * argv[]) {
	int opcao;
	int item, maior;
	Pilha P, P2;
	do {
		P.print();
		cout << "\n1 - inserir na pilha\n2 - remover  \n3 - consultar\n4 - maior";
		cout << "\n5 - limpar\n6 - copiar\n0 - sair";
		cout << "\nOPCAO:";
		cin >> opcao;
		switch(opcao) {
		case 1:
			cin >> item;
			P.push(item);
			break;
		case 2:
			P.pop();

			break;
		case 3:
			if(P.top(item))
				cout << item << " ";
			break;
		case 4:
			if(P.maior1(maior))
				cout << "maior = " << maior;
			if(P.maior2(maior))
				cout << "maior = " << maior;
			break;
		case 5:
			P.clear();
			break;
		case 6:
			P.copy2(P2);
			P.print();
			P2.print();
			break;
		}
	} while(opcao != 0);
	system("PAUSE");
	return 0;
}



