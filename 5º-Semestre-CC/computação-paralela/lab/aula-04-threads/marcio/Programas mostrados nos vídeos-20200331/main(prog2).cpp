
/********************************************************
 * PROGRAMA PARA APRENDIZADO DE PTHREADS
 * carrega dados de um arquivo para uma matriz,
 * solicita alguns parametros e a quantidade de threads 
 * que irão executar.
 * Mede o tempo de execução.
 */
        



#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <sstream>
#include <string.h>
#include <pthread.h>
#include <math.h>
#include <time.h>
//#include <conio.h>
#include <windows.h>
#include <unistd.h>

using namespace std;

string splitN(string s, int pos);
int * * alocarMatriz(int Linhas, int Colunas);
//void busca(double * * mat, int idIni, int idFim, double x2, int x3, double x4, int x5, double x6, int & soma);
void * busca(void * arg);
void dorme(int n);

double * * matriz;

struct dados {

	double x2;
	double x3;
	double x4;
	double x5;
	double x6;

	int ini;
	int fim;

	int qtd;
	int soma;

	bool terminei;

};

int main() {

	cout << "Quantidade de registros a processar: ";
	long qtd;
	cin >> qtd;

	if (qtd > 10000000) {
		cout << "Excede a quantidade de registros do arquivo (max = 10.000.000)";
		exit(0);
	}

	if (qtd < 1000) {
		cout << "A quantidade deve ser maior ou igual que 1000.";
		exit(0);
	}

	//==========================================================================
	//          ALOCACAO DA MEMORIA PARA A MATRIZ DE DADOS
	//==========================================================================
	//double * * matriz;

	//= alocar memoria relativa ao numero de linhas
	matriz = (double * * )malloc(sizeof(double * ) * qtd);

	//= alocar memoria relativa ao numero de colunas para cada linha
	for(int i = 0; i < qtd; i++) {
		matriz[i] = (double ( * ))malloc(sizeof(double) * 7);
	}
	//--------------------------------------------------------------------------

	ifstream df ("dados.txt"); //= arquivo de leitura de dados
	string linha; //= p/ acondicionar uma linha lida

	//==========================================================================
	//                   PREENCHER A MATRIZ DE DADOS
	//==========================================================================
	int cont = 1;
	while (cont <= qtd) {

		getline (df, linha); //= le uma linha do arquivo

		matriz[cont - 1][0] = atof(splitN(linha, 1).c_str());
		matriz[cont - 1][1] = atof(splitN(linha, 2).c_str());
		matriz[cont - 1][2] = atof(splitN(linha, 3).c_str());
		matriz[cont - 1][3] = atof(splitN(linha, 4).c_str());
		matriz[cont - 1][4] = atof(splitN(linha, 5).c_str());
		matriz[cont - 1][5] = atof(splitN(linha, 6).c_str());
		matriz[cont - 1][6] = atof(splitN(linha, 7).c_str());

		cont++;
	}
	//--------------------------------------------------------------------------

	while (true) {

		system("cls");
		cout << "A tabela de dados carregada em memoria contem " << qtd << " registros." << endl;
		cout << "E' composta por 7 colunas:" << endl;
		cout << "1 - ID do registro (inteiro sequencial)." << endl;
		cout << "2 - Real entre 0 e 1." << endl;
		cout << "3 - Real entre 10 e 19." << endl;
		cout << "4 - Inteiro 0 ou 1 (binario)." << endl;
		cout << "5 - Inteiro entre 300 e 320." << endl;
		cout << "6 - Real entre -1 e 1." << endl;
		cout << "7 - Inteiro entre 1000 e 10000." << endl;

		cout << "-------------------------------------------------------------------" << endl;

		cout << "O algoritmo faz a somatoria da coluna 7 dos registros que atendam " << endl;
		cout << "seguinte criterio:" << endl;
		cout << "* coluna 2 - tenha valor maior que x (real), onde 0 <= x <= 1 (-1 sai do programa)." << endl;
		cout << "* coluna 3 - tenha valor maior que x (real), onde 10 <= x <= 19." << endl;
		cout << "* coluna 4 - tenha valor igual x (inteiro), onde x = 0 ou x = 1." << endl;
		cout << "* coluna 5 - tenha valor maior que x (inteiro), onde 300 <= x <= 320." << endl;
		cout << "* coluna 6 - tenha valor de x +/- 0.1 (especificar o sinal em caso negativo)" << endl;

		cout << "-------------------------------------------------------------------" << endl;

		cout << "\nColuna 2: ";
		double x2;
		cin >> x2;
		if (x2 == -1) break;

		cout << "Coluna 3: ";
		double x3;
		cin >> x3;

		cout << "Coluna 4: ";
		double x4;
		cin >> x4;

		cout << "Coluna 5: ";
		double x5;
		cin >> x5;

		cout << "Coluna 6: ";
		double x6;
		cin >> x6;

		while (true) {

			cout << "\n-------------------------------------------------------------------" << endl;
			cout << "\n\nQuantidade de threads (1, 2, 3, 4): ";
			int nrTh;
			cin >> nrTh;

			//==========================================================================
			// IMPRIME AS 100 primeiras linhas da matriz
			if (nrTh == 0) {
				for (int i = 0; i < 100; i++) {
					for (int j = 0; j <= 6; j++) {
						cout << matriz[i][j] << " / ";
					}
					cout << endl;
				}
				return 0;
			}
			//------------------------------------------------------------------

			//==========================================================================
			//                    IDENTIFICADOR DAS THREADS
			//==========================================================================
			pthread_t th1;
			pthread_t th2;
			pthread_t th3;
			pthread_t th4;
			pthread_t th5;
			pthread_t th6;
			pthread_t th7;
			pthread_t th8;
			//--------------------------------------------------------------------------

			int thStatus;

			dados dd1;
			dados dd2;
			dados dd3;
			dados dd4;
			dados dd5;
			dados dd6;
			dados dd7;
			dados dd8;

			dd1.x2 = x2;
			dd1.x3 = x3;
			dd1.x4 = x4;
			dd1.x5 = x5;
			dd1.x6 = x6;

			dd2.x2 = x2;
			dd2.x3 = x3;
			dd2.x4 = x4;
			dd2.x5 = x5;
			dd2.x6 = x6;

			dd3.x2 = x2;
			dd3.x3 = x3;
			dd3.x4 = x4;
			dd3.x5 = x5;
			dd3.x6 = x6;

			dd4.x2 = x2;
			dd4.x3 = x3;
			dd4.x4 = x4;
			dd4.x5 = x5;
			dd4.x6 = x6;

			dd5.x2 = x2;
			dd5.x3 = x3;
			dd5.x4 = x4;
			dd5.x5 = x5;
			dd5.x6 = x6;

			dd6.x2 = x2;
			dd6.x3 = x3;
			dd6.x4 = x4;
			dd6.x5 = x5;
			dd6.x6 = x6;

			dd7.x2 = x2;
			dd7.x3 = x3;
			dd7.x4 = x4;
			dd7.x5 = x5;
			dd7.x6 = x6;

			dd8.x2 = x2;
			dd8.x3 = x3;
			dd8.x4 = x4;
			dd8.x5 = x5;
			dd8.x6 = x6;

			clock_t Ticks[2];
			Ticks[0] = clock();
			void * retval;

			int parte;
			switch(nrTh) {
			case 8:
				parte = (int)(qtd / 8);
				dd1.ini = 0;
				dd1.fim = parte;
				dd2.ini = dd1.fim + 1;
				dd2.fim = dd2.ini + parte;
				dd3.ini = dd2.fim + 1;
				dd3.fim = dd3.ini + parte;
				dd4.ini = dd3.fim + 1;
				dd4.fim = dd4.ini + parte;
				dd5.ini = dd4.fim + 1;
				dd5.fim = dd5.ini + parte;
				dd6.ini = dd5.fim + 1;
				dd6.fim = dd6.ini + parte;
				dd7.ini = dd6.fim + 1;
				dd7.fim = dd7.ini + parte;
				dd8.ini = dd7.fim + 1;
				dd8.fim = qtd - 1;
				pthread_create ( & th1, NULL, busca, (void * ) & dd1);
				pthread_create ( & th2, NULL, busca, (void * ) & dd2);
				pthread_create ( & th3, NULL, busca, (void * ) & dd3);
				pthread_create ( & th4, NULL, busca, (void * ) & dd4);
				pthread_create ( & th5, NULL, busca, (void * ) & dd5);
				pthread_create ( & th6, NULL, busca, (void * ) & dd6);
				pthread_create ( & th7, NULL, busca, (void * ) & dd7);
				pthread_create ( & th8, NULL, busca, (void * ) & dd8);
				pthread_join(th1, & retval);
				pthread_join(th2, & retval);
				pthread_join(th3, & retval);
				pthread_join(th4, & retval);
				pthread_join(th5, & retval);
				pthread_join(th6, & retval);
				pthread_join(th7, & retval);
				pthread_join(th8, & retval);
				break;
			case 4:
				parte = (int)(qtd / 4);
				dd1.ini = 0;
				dd1.fim = parte;
				dd2.ini = dd1.fim + 1;
				dd2.fim = dd2.ini + parte;
				dd3.ini = dd2.fim + 1;
				dd3.fim = dd3.ini + parte;
				dd4.ini = dd3.fim + 1;
				dd4.fim = qtd - 1;
				pthread_create ( & th1, NULL, busca, (void * ) & dd1);
				pthread_create ( & th2, NULL, busca, (void * ) & dd2);
				pthread_create ( & th3, NULL, busca, (void * ) & dd3);
				pthread_create ( & th4, NULL, busca, (void * ) & dd4);
				pthread_join(th1, & retval);
				pthread_join(th2, & retval);
				pthread_join(th3, & retval);
				pthread_join(th4, & retval);
				break;
			case 3:
				parte = (int)(qtd / 3);
				dd1.ini = 0;
				dd1.fim = parte;
				dd2.ini = dd1.fim + 1;
				dd2.fim = dd2.ini + parte;
				dd3.ini = dd2.fim + 1;
				dd3.fim = qtd - 1;
				pthread_create ( & th1, NULL, busca, (void * ) & dd1);
				pthread_create ( & th2, NULL, busca, (void * ) & dd2);
				pthread_create ( & th3, NULL, busca, (void * ) & dd3);
				pthread_join(th1, & retval);
				pthread_join(th2, & retval);
				pthread_join(th3, & retval);
				break;
			case 2:
				parte = (int)(qtd / 2);
				dd1.ini = 0;
				dd1.fim = parte;
				dd2.ini = dd1.fim + 1;
				dd2.fim = qtd - 1;
				pthread_create ( & th1, NULL, busca, (void * ) & dd1);
				pthread_create ( & th2, NULL, busca, (void * ) & dd2);
				pthread_join(th1, & retval);
				pthread_join(th2, & retval);
				break;
			case 1:
				dd1.ini = 0;
				dd1.fim = qtd - 1;
				thStatus = pthread_create ( & th1, NULL, busca, (void * ) & dd1);
				pthread_join(th1, & retval);
				break;
			default:
				break;
			}




			// Sleep(4000);

			Ticks[1] = clock();
			double Tempo = (float(Ticks[1] - Ticks[0]) * 1000.0) / CLOCKS_PER_SEC;
			printf("Tempo gasto: %g ms.", Tempo);

			cout << "\n\n\n";
			//system("pause");

			cout << "\n\nThread 1 - " << dd1.qtd << " elementos que somam " << dd1.soma;
			if (nrTh > 1 ) {
				cout << "\nThread 2 - " << dd2.qtd << " elementos que somam " << dd2.soma;
				if (nrTh > 2) {
					cout << "\nThread 3 - " << dd3.qtd << " elementos que somam " << dd3.soma;
					if (nrTh > 3) {
						cout << "\nThread 4 - " << dd4.qtd << " elementos que somam " << dd4.soma;
						if (nrTh == 8) {
							cout << "\nThread 5 - " << dd5.qtd << " elementos que somam " << dd5.soma;
							cout << "\nThread 6 - " << dd6.qtd << " elementos que somam " << dd6.soma;
							cout << "\nThread 7 - " << dd7.qtd << " elementos que somam " << dd7.soma;
							cout << "\nThread 8 - " << dd8.qtd << " elementos que somam " << dd8.soma;
						}
					}
				}
			}

			cout << "\n\n\nRepetir com os mesmos dados? (s/n)";
			char chr;
			cin >> chr;
			
			if (chr=='n' || chr=='N') break;

		} //= while para manter os mesmos dados de entrada

	} //= while global


	return 0;
}


void * busca(void * arg) {

	dados * d = (dados * ) arg;

	d->soma = 0;
	d->qtd = 0;
	d->terminei = false;

	for (int i = d->ini; i <= d->fim; i++) {

		if (matriz[i][1] > d->x2
				&& (int)matriz[i][2] > (int)d->x3
				&& matriz[i][3] == d->x4
				&& (int)matriz[i][4] > (int)d->x5
				&& fabs(matriz[i][5]) >= fabs(d->x6) - 0.1
				&& fabs(matriz[i][5]) <= fabs(d->x6) + 0.1
		   ) {
			d->qtd++;
			d->soma += matriz[i][6];


		}

		//Sleep(100000000);

	}

	d->terminei = true;

}

void dorme(int n) {
	Sleep(n);

}






/*
Este metodo nao faz propriamente um split. Ele retorna o elemento na posicao N
em relacao aos separadores (virgula).
P. ex: splitN("aaa,bbb,cccc,dd,eeeeeee", 4) retorna "dd".
Nao e' eficiente para o split de toda a string, uma vez que e' necessario solicitar
os elementos posicao a posicao, o que o faz sempre percorrer a strig a partir
do inicio (nao salva o ultimo caracter retornado).
*/
string splitN(string s, int pos) {

	stringstream ss;

	if (pos == 1) {
		for (unsigned int i = 0; i < s.length(); i++) {
			char c = s.at(i);
			if (c == ',') break;
			ss << c;
		}
	} else {
		int posVirgula = 0;
		for (unsigned int i = 0; i < s.length(); i++) {
			char c = s.at(i);
			if (c == ',') posVirgula++;
			if (posVirgula == pos - 1) {
				int newI = i + 1;
				for (unsigned int j = newI; j < s.length(); j++) {
					char c2 = s.at(j);
					if (c2 == ',') {
						break;
					}
					ss << c2;
				}
				break;
			}
		}
	}

	return ss.str();
}