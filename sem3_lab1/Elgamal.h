#pragma once
#include "User.h"

class Elgamal : public User {
private:
	int g, p, x,  y;
	vector<pair<int, int>> encrypted_text;
	vector<int> a;
	vector<int> b;
	vector<int> k;
public:
	Elgamal(string _name, int _g, int _p);
	void Generate_x_y();
	void Generate_k();
	void Encrypt();
	void Decrypt();
	void Set_Y(int _y);
	int Get_Y();
	vector<pair<int, int>> Get_enc_text();
	void Set_enc_text(vector<pair<int, int>> _enc_text);
};