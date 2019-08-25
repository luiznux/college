#define TAMANHO 5
#include <iostream>
#include <stdlib.h>

using namespace std;

int numeros[TAMANHO];

//==============================================================================
// Metodo para imprimir o vetor.
void imprimir() {
       cout << "\n[ ";
       for (int i = 0; i < TAMANHO; i++) {
               cout << numeros[i] << " ";
       }
       cout << "]";
}
//------------------------------------------------------------------------------

// Heapsort pra ordenar o vetor
// To heapify a subtree rooted with node i which is
// an index in arr[]. n is size of heap
void heapify(int arr[], int n, int i)
{
    int largest = i; // Initialize largest as root
    int l = 2 * i + 1; // left = 2*i + 1
    int r = 2 * i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i) {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        heapify(arr, n, largest);
    }
}

// main function to do heap sort
void heapSort(int arr[], int n)
{
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i = n - 1; i >= 0; i--) {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        heapify(arr, i, 0);
    }
}

/* A utility function to print array of size n */
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";
    cout << "\n";
}

//===========================================================================

/**
 * Metodo para incluir um elemento no vetor. A posicao tem que estar vaga
 * (valor do elemento igual a zero). O novo elemento tem que ser maior que
 * zero.
 *
 * @param indice - indice do elemento que sera´ incluido.
 * @param valor - valor do elemento a ser incluido.
 * @return
 */
string incluir(int indice, int valor) {

       // verifica se o valor e´ maior que zero
       if (valor < 0) {
              return "ERRO: o valor tem que ser maior que zero.";
       }

       // verifica se o indice e´ valido
       if (indice < 0 || indice > TAMANHO - 1) {
              return "ERRO: o indice esta´ fora dos limites do vetor.";
       }

       // verifica se a posicao ja´ esta´ ocupada.
       if (numeros[indice] > 0) {
              return "ERRO: posicao ocupada.";
       }

       // passou por todas as verificacoes: inserir
       numeros[indice] = valor;
       return "Inclusao bem sucedida.";
}


/**
 * Excluir um elemento do vetor. Atribui zero `a posicao e retorna o
 * elemento (valor).
 *
 * @param indice - indice do elemento que sera´ excluido.
 * @return - valor do elemento excluido. Se retornar zero e´ porque a
 * posicao estava vazia; se retornar -1 e´ porque o indice e´ invalido.
 */
int excluir(int indice) {

       // verifica se o indice e´ valido
       if (indice < 0 || indice > TAMANHO - 1) {
              return -1;
       }

       int numero = numeros[indice];
       numeros[indice] = 0;
       return numero;

}



//==============================================================================
//                                     MAIN
//==============================================================================
int main() {

       //numeros = new int[TAMANHO];
       for (int i = 0; i < TAMANHO; i++) {
              numeros[i] = 0;
       }

       while(true) {

              system("CLS");
              cout << "\n----------------------------------------------";
              cout << "\n               RELEMBRANDO VETORES";
              cout << "\n----------------------------------------------";
              cout << "\n0 - sair.";
              cout << "\n1 - imprimir o vetor.";
              cout << "\n2 - inserir um elemento ( >0 e a posicao no vetor tem que estar livre (=0)";
              cout << "\n3 - excluir um elemento.";
              cout << "\n4 - trocar dois elementos de lugar entre si.";
              cout << "\n5 - localizar o maior e o menor elementos do vetor";
              cout << "\n6 - ordenar os elementos do vetor em ordem crescente";
              cout << "\n7 - ordenar os elementos do vetor em ordem decrescente";
              cout << "\n8 - ordenar os elementos do vetor em um segundo vetor (o metodo cria o novo vetor, copia os dados e retorna o vetor ordenado";
              cout << "\n---------------------";
              cout << "\nQual a sua opcao -> ";

              int opc;
              cin >> opc;

              if (opc == 0) {
                     break;

              } else if (opc == 1) {
                     imprimir();
                     cout << "\n\n";
                     system("PAUSE");

              } else if (opc == 2) {
                     //= precisa pedir os dados: posicao no vetor (indice) e valor do elemento.
                     cout << "Indice do novo elemento: ";
                     int idx;
                     cin >> idx;
                     cout << "Valor do novo elemento: ";
                     int val;
                     cin >> val;
                     cout << incluir(idx, val) << endl;
                     system("PAUSE");

              } else if (opc == 3) {
                     cout << "Indice do elemento a ser removido: ";
                     int idx;
                     cin >> idx;
                     int val = excluir(idx);
                         if (val == 0) {
                                 cout << "Nao ha´ elemento na posicao " << idx;
                         } else if (val == -1) {
                                 cout << "ERRO: o indice esta' fora dos limites do vetor.";
                         } else {
                                 cout << "Valor excluido da posicao " << idx << ": " << val;
                         }
                         cout << "\n\n";
                         system("PAUSE");

              } else if(opc == 4) {
                  // variáveis para a troca dos elementos do vetor
                  int selecionado;
                  int vai_troca;
                  int ajuda;

                 cout << "Digite o indice do primeiro elemento \n";
                  cin >> selecionado;
                  if (selecionado < TAMANHO || selecionado > TAMANHO){
                      cout << "/n ERRO! Indice fora do range";
                  }

                  cout << "Digite o indice do elemente que deseja trocar \n";
                  cin >> vai_troca;
                  if (vai_troca < TAMANHO || vai_troca > TAMANHO){
                      cout << " /n ERRO! Indice fora do range ";
                  }
                  ajuda = numeros[vai_troca];
                  numeros[selecionado]  = numeros[vai_troca];
                  numeros[selecionado] = numeros[ajuda];

              }   else   if (opc == 5) {

              }   else   if (opc == 6) {
              }   else   if (opc == 7) {
              }   else   if (opc == 8) {
              }


       }

       //system("PAUSE");

       cout << "\n-------------------------------------------------";
       cout << "\n\nObrigado e ate' a proxima vez.\n\n\n";


       return 0;
}
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------
//------------------------------------------------------------------------------



