#include "inteiro.h"

Inteiro::Inteiro(int v){
  value = v;
}

int Inteiro::getValue(){
  return value;
}

Inteiro Inteiro::suc(){
  Inteiro n(value+1);
  return n;
}

Inteiro Inteiro::ant(){
  Inteiro n(value-1);
  return n;
}

Inteiro Inteiro::soma(Inteiro n){
  Inteiro s(value+n.getValue());
  return s;
}

Inteiro Inteiro::subt(Inteiro n){
  Inteiro s(value-n.getValue());
  return s;
}

Inteiro Inteiro::mult(Inteiro n){
  if (n.getValue() == 0 || value == 0)
    return 0;
  else if (n.getValue() == 1)
    return value;
  else
    return value + mult(n.getValue()-1).getValue();
}
