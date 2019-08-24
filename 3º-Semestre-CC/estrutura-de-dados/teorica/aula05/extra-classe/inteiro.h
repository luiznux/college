#ifndef INTEIRO_H
#define INTEIRO_H

class Inteiro{
private:
  int value;
public:
  Inteiro(int v);
  Inteiro suc();
  Inteiro ant();
  Inteiro soma(Inteiro n);
  Inteiro subt(Inteiro n);
  Inteiro mult(Inteiro n);
  int getValue();
};

#endif
