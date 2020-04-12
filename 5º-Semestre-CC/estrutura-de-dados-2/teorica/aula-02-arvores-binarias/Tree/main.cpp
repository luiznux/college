#include "tree.h"

int main(){

    Tree teste;
    teste.insert(100);  //raiz
    teste.insert(200);
    teste.insert(20);  //direta
    teste.insert(50); //esquerda
    teste.insert(10);
    teste.insert(5);
    teste.print_in_pre_order(teste.get_root());
    std::cout << teste.locate_value(5);


    return 0;
}
