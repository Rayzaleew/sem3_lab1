#include "Elgamal.h"

using namespace std;




Elgamal::Elgamal(string _name, int _g, int _p) : User(_name) {
	a.clear();
	b.clear();
	k.clear();
	x = 0;
	y = 0;
	g = _g;
	p = _p;
}

void Elgamal::Generate_x_y() {
	 x = Random(2, p-1);
	 y = mod_exp(g, x, p);
	
}

void Elgamal::Generate_k() {
	int _k = 0;
	_k = Random(2, p - 2);
	k.push_back(_k);
}

void Elgamal::Encrypt() {
	int _a, _b;
	for (unsigned int i = 0; i < Get_data().size(); i++) {
		Generate_k();
		_a = mod_exp(g, k[i], p);
		a.push_back(_a);
		_b = mod_exp(Get_data()[i] * mod_exp(y, k[i], p), 1, p);
		b.push_back(_b);
		encrypted_text.push_back(make_pair(a[i], b[i]));
	}
	
}

void Elgamal::Decrypt() {
	string c = " ";
	string msg = " ";
	for (unsigned int i = 0; i < encrypted_text.size(); i++) {
		a.push_back(encrypted_text[i].first);
		b.push_back(encrypted_text[i].second);
		c = mod_exp(b[i] * mod_exp(a[i], p - 1 - x, p), 1, p);
		msg.append(c);
	}
	Set_message(msg);
}

void Elgamal::Set_Y(int _y) {
	y = _y;
}

int Elgamal::Get_Y() {
	return y;
}

vector<pair<int, int>> Elgamal::Get_enc_text() {
	return encrypted_text;
}

void Elgamal::Set_enc_text(vector<pair<int, int>> _enc_text) {
	encrypted_text = _enc_text;

}
