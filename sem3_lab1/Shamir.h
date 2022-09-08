#pragma once
#include "User.h"

using namespace std;

class Shamir : public User {
private:
	unsigned long long p, a, a_invert, E;
public:
	Shamir(string _name, unsigned long long _p);
	
	void Generate_a();
	//unsigned long long mod_invert(unsigned long long _a, unsigned long long _p);
	void Encrypt(unsigned long long _pow);
	void Decrypt(unsigned long long _key);
	void Send(Shamir& _user);
	unsigned long long Get_a();
	unsigned long long Get_a_invert();

};