#include "Shamir.h"

using namespace std;

Shamir::Shamir(string _name, unsigned long long _p) : User(_name) {
	p = _p;
	a = 0;
	a_invert = 0;
}

void Shamir::Generate_a() {
	do {
		a = Generate_p();
	} while ((GCD(a, p - 1) != 1) && (a < p-1));
    a_invert = mod_invert(a, p - 1);
}

void Shamir::Encrypt(unsigned long long _pow) {
    vector <int> enc_text;
    for (auto i : Get_data()) {
        enc_text.push_back(mod_exp(i, _pow, p));
    }
    Set_data(enc_text);
    enc_text.clear();
}

void Shamir::Decrypt(unsigned long long _key) {
    string c = " ";
    string msg = " ";
    for (auto i : Get_data()) {
        c = (mod_exp(i, _key, p));
        msg.append(c);
    }
    Set_message(msg);
}

void Shamir::Send(Shamir& _user) {
    vector<int> _data = Get_data();
    _user.Set_data(_data);
}

unsigned long long Shamir::Get_a() {
    return a;
}

unsigned long long Shamir::Get_a_invert() {
    return a_invert;
}