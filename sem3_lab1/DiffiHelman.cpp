#include "DiffiHelman.h"

using namespace std;

DiffiHelman::DiffiHelman(string _name, int _g, int _p) : User(_name) {
	K = NULL;
	Y = NULL;
	X = NULL;
	//name = _name;
	g = _g;
	p = _p;
}

void DiffiHelman::Set_X(int _x) {
	X = _x;
}

void DiffiHelman::Calc_Y() {
	Y = mod_exp(g, X, p);
}

void DiffiHelman::Calc_K(int _y) {
	K = mod_exp(_y, X, p);
}

int DiffiHelman::Get_X() {
	return X;
}

int DiffiHelman::Get_Y() {
	return Y;
}

int DiffiHelman::Get_K() {
	return K;
}