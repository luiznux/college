#ifndef REAL_H
#define REAL_H

class Real{
  private:
    double value;
  public:
    Real(double c); 
    ~Real();
    Real operator+(Real n);
    Real operator-(Real n);
    Real operator*(Real n);
    Real operator/(Real n);
    Real pote(Real n);
    Real raiz();
    double getValue();
};

#endif
