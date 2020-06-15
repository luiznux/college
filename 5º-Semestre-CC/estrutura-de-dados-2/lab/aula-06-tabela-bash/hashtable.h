#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <iostream>
#include <cstdlib>
#define TABLE  10

class hashtable
{

private:

    int table[TABLE] = calloc(10, sizeof(int));

public:
    hashtable();
    bool insert(int value);
    bool select(int value);
};

#endif
