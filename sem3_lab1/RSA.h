#pragma once
#include "User.h"

using namespace std;

class RSA : public User {
private:
	unsigned long long e, d, n, fi;
public:
	RSA(string _name, unsigned long long _fi, unsigned long long _n);
	void Generate_e();
	void Set_e(unsigned long long _e);
	unsigned long long Get_e();
	unsigned long long Get_d();
	void Generate_d();
	void Decrypt();
	void Encrypt();
	void Send(RSA& _user);

};