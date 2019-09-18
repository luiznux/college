#include "pilha.h"

#include <iostream>

using namespace std;


int main(){

    while(true){

    Pilha polones = Pilha();

    float numero;

    float valor;

        int opc ;

        cout <<"\n\n Digite uma das opções";
              cout << "\n----------------------------------------------";
              cout << "\n0 - sair.";
              cout << "\n1 - Inserir  numeros.";
              cout << "\n2 - Inserir operações. ";
              cout << "\n3 - imprime o resultado. \n -> ";

              cin >> opc;


              if(opc == 0){
                  break;
              }

              else if(opc == 1){
                  int controlador = 0;
                  while(controlador < 2){

                      float numero;
                      cout << "\n Digite o numero \n->";
                      cin >> numero;

                      polones.push(numero);

                      cout << "\n" << endl;
                      controlador++;
                  }

              }else if(opc == 2){

                  string operacao;

                  cout << "Digite uma operacao \n ->";
                  cin >> operacao;

                  if(operacao == "+"){

                      valor = polones.pop() + polones.pop();
                      polones.push(valor);

                  }else if(operacao == "-"){

                      valor = polones.pop() - polones.pop();
                      polones.push(valor);

                  }else if(operacao == "*"){

                      valor = polones.pop() * polones.pop();
                      polones.push(valor);

                  }else if(operacao == "/"){

                      valor = polones.pop() / polones.pop();
                      polones.push(valor);
                  }

                  cout << "\n " << endl;

              }else if(opc == 3){

                  polones.imprime();

                  cout << "\n" << endl;
              }
    }

    return 0;
}
