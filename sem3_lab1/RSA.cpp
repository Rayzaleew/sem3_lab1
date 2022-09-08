#include "RSA.h"

using namespace std;

RSA::RSA(string _name, unsigned long long _fi, unsigned long long _n) : User(_name) {
	fi = _fi;
	n = _n;
}

void RSA::Generate_e() {
    do {
        e = Prime_random(2, fi);
    } while (GCD(e, fi) != 1);
}

void RSA::Generate_d() {
	d = mod_invert(e, fi);
}

void RSA::Set_e(unsigned long long _e) {
	e = _e;
}

unsigned long long RSA::Get_e() {
	return e;
}

void RSA::Encrypt() {
    vector <int> enc_text;
    for (auto i : Get_data()) {
        enc_text.push_back(mod_exp(i, e, n));
    }
    Set_data(enc_text);
    enc_text.clear();
}

void RSA::Decrypt() {
    string c = " ";
    int l = 0;
    string msg = " ";
    for (auto i : Get_data()) {
        //cout << i << " ";
        c = (mod_exp(i, d, n));
        //cout << l << " ";
        msg.append(c);
    }
    cout << endl;
    Set_message(msg);
}

void RSA::Send(RSA& _user) {
    vector<int> _data = Get_data();
    _user.Set_data(_data);
}

unsigned long long RSA::Get_d() {
    return d;
}