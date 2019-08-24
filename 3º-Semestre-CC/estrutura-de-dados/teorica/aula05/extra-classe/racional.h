#ifndef RACIONAL_H
#define RACIONAL_H

class Racional{ 
private: 
  int a,b;
 public:
  Racional(int v, int x);
  Racional operator+(Racional n);
  Racional operator-(Racional n);
  Racional operator*(Racional n);
  Racional operator/(Racional n);
  int getA();
  int getB();
};

#endif
