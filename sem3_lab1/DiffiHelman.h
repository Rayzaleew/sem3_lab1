#pragma once
#include "User.h"

using namespace std;

class DiffiHelman : public User {
private:
	int g, p, X, Y, K;
public:
	DiffiHelman(string _name, int _g, int _p);
	void Set_X(int _x);
	void Calc_Y();
	void Calc_K(int _y);
	int Get_X();
	int Get_Y();
	int Get_K();
};