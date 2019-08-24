#include "complexo.h"

Complexo::Complexo(char sinal_real, double real, char sinal_img, double imag)
{
	
	if (sinal_real == '+')
		real = real;
	else
		real = -real;

	if (sinal_img == '+')
		img = imag;
	else
		img = -imag;
}

Complexo::~Complexo() {}

double Complexo::getReal()
{
	return real;
}

double Complexo::getImg()
{
	return img;
	
}

Complexo Complexo::operator+(Complexo n)
{
	double parte_real = real + n.getReal();
	double parte_imaginaria = img + n.getImg();
	return Complexo(std::abs(parte_real),
					parte_real<0?'-':'+',
					std::abs(parte_imaginaria),
					parte_imaginaria<0?'-':'+');
}

Complexo Complexo::operator-(Complexo n)
{
	double parte_real = real - n.getReal();
	double parte_imaginaria = img - n.getImg();
	return Complexo(std::abs(parte_real),
					parte_real<0?'-':'+',
					std::abs(parte_imaginaria),
					parte_imaginaria<0?'-':'+');
}

Complexo Complexo::operator*(Complexo n)
{
	double r = (real * n.getReal() - img * n.getImg());
	double i = (real * n.getImg() + img * n.getReal());
	return Complexo(std::abs(r), r<0?'-':'+',
					std::abs(i), i<0?'-':'+');
}


