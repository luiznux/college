#include "real.h"

Real::Real(double c){
  value = c;
}

Real::~Real(){}

double Real::getValue(){
  return value;
}

Real Real::operator+(Real n){
  Real soma(value+n.getValue());
  return soma;
}

Real Real::operator-(Real n){
  Real subt(value-n.getValue());
  return subt;
}

Real Real::operator*(Real n){
  if (value == 0 || n.getValue() == 0){
    Real mult(0);
    return mult; 
  }else if (n.getValue() == 1){
    Real mult(value);
    return mult;
  }else{
    Real mult(value*n.getValue());
    return mult;
  }
}

Real Real::operator/(Real n){
  if (value == 0 || n.getValue() == 0){
    Real divi(0);
    return divi;
  }else if (n.getValue() == 1){
    Real divi(value);
    return divi;
  }else{
    Real divi(value/n.getValue());
    return divi;
  }
}
