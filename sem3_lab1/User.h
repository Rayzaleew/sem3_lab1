#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

ostream& operator<< (ostream& out, const vector<int>& _enc_text);
ostream& operator<< (ostream& out, const vector<pair<int, int>>& _enc_text);

class User {
private:
	unsigned long long p, q;
	string name, message;
	vector<int> data;
public:
	User();
	User(string _name);
	void Generate(int& _g, int& _p);
	int Generate();
	void Generate_p_q(unsigned long long& _fi, unsigned long long& _n);
	unsigned long long mod_invert(unsigned long long _a, unsigned long long _p);
	unsigned long long Generate_p();
	string Get_name();
	int Random(int begin, int end);
	bool is_Prime(int number);
	int Prime_random(int begin, int end);
	int GCD(int first_num, int second_num);
	int mod_exp(int _g, int _x, int _p);
	void Insert_Message();
	void Set_data(vector<int> _data);
	vector<int> Get_data();
	void Set_message(string _message);
	string Get_message();
	
	



};