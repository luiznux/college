#include "racional.h"

Racional::Racional(int v, int x){
  a = v;
  b = x;
}

int Racional::getA(){
  return a;
}

int Racional::getB(){
  return b;
}

Racional Racional::operator+(Racional n){
  int v, x;
  if (b == n.getB()){
    v = a + n.getA();
    x = b;
  } else{
    v = a*n.getB() + b*n.getA();
    x = b*n.getB();
  }
  Racional soma(v, x);
  return soma; 
}

Racional Racional::operator-(Racional n){
 int v, x;
  if (b == n.getB()){
    v = a - n.getA();
    x = b;
  } else{
    v = a*n.getB() - b*n.getA();
    x = b*n.getB();
  }
  Racional subt(v, x);
  return subt; 
}

Racional Racional::operator*(Racional n){
  int v = a*n.getA();
  int x = b*n.getB();
  Racional mult(v, x);
  return mult;
}

Racional Racional::operator/(Racional n){
  int v = a*n.getB();
  int x = b*n.getA();
  Racional div(v,x);
  return div;
}
