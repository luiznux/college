#include "natural.h"
#include <iostream>
Natural::Natural(int v){
  value = v;
}

unsigned int Natural::getValue(){
  return value;
}

Natural Natural::suc(){
  Natural n(value+1);
  return n;
}

Natural Natural::soma(Natural n){
  Natural s(value+n.getValue());
  return s;
}

Natural Natural::mult(Natural n){
	if (n.getValue() == 0 || value == 0)
	    return 0;
	else if (n.getValue() == 1)
	    return value;
	else
	    return value + mult(n.getValue()-1).getValue();
}

Natural::Natural(){}

