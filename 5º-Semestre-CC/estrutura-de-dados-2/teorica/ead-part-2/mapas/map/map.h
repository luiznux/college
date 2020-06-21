#ifndef MAP_H
#define MAP_H
#include "node.h"

/*
  implementaçao da estrutura Mapa
 */
class Map{

private:

    Node *head;
    //metodo para comparar as strigs
    bool are_strings_equal(char *str1, char *str2);

public:
    Map();
    ~Map();
    bool insertMap(Node *car);
    bool searchValue(char *placa);
};
#endif
