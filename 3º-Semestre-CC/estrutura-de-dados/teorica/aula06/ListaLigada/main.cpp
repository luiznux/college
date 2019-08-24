#include <iostream>
#include "lista_ligada.cpp"

int main() {
  ListaLigada<int> lista;
  lista.insereInicio(2);
  std::cout << lista.inicio();
  lista.removeInicio();
  std::cout << lista.inicio();
}