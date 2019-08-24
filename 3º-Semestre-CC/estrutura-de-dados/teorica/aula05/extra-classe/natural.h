#ifndef NATURAL_H
#define NATURAL_H
#include <iostream>

class Natural{
private:
  unsigned int value;
public:
  Natural(int v);
  Natural suc();
  Natural soma(Natural n);
  Natural mult(Natural n);
  unsigned int getValue();
  Natural* operator[](int tamanho);
  Natural();
  friend std::ostream& operator<<(std::ostream& os, const Natural& dt){
    os << dt.value;
    	return os;     
  }
};

#endif
