#ifndef COMPLEXO_H
#define COMPLEXO_H

#include <iostream>
#include <stdlib.h>

class Complexo {
private:
	double real;
	double img;
public:
	Complexo(char sinal_real, double real, char sinal_img, double img);
	~Complexo();
	double getReal();
	double getImg();
	Complexo operator+(Complexo n);
	Complexo operator-(Complexo n);
	Complexo operator*(Complexo n);
};

#endif
