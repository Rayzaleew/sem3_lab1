#include "User.h"

using namespace std;


ostream& operator<< (ostream& out, const vector<int> &_enc_text) {
	out << "{ ";
	for (auto i : _enc_text) {
		out << i << " ";
	}
	out << " }";
	out << endl;
	return out;
}

ostream& operator<< (ostream& out, const vector<pair<int, int>> &_enc_text) {
	out << "{ ";
	for (auto i : _enc_text) {
		out << i.first << " " << i.second << " ";
	}
	out << "}";
	out << endl;
	return out;
}

User::User() {
	name = "";
}

User::User(string _name) {
	name = _name;
}

string User::Get_name() {
	return name;
}

bool User::is_Prime(int number) {
	auto sqrt_number = sqrt(number) + 1;

	for (unsigned int i = 2; i < sqrt_number; i++) {
		if (number % i == 0) return false;
	}

	return true;
}

int User::Random(int begin, int end) {
	return begin + rand() % (end - begin);
}

int User::Prime_random(int begin, int end) {
	int number = 0;

	do {
		number = Random(begin, end);
	} while (!(is_Prime(number)));

	return number;
}

int User::GCD(int first_num, int second_num) {
	if (second_num) return GCD(second_num, first_num % second_num);
	else return first_num;
}

int User::mod_exp(int num, int pow, int mod) {
	pow = pow % (mod - 1);
	num %= mod;

	int result = 1;
	for (int i = 1; i <= pow; i++) {
		result *= num;
		result %= mod;
		
	}
	//cout << result << endl;
	return(result);
}

void User::Generate(int &g, int &p) {
	do {
	p = Prime_random(1000, 10000);

	auto q = (p - 1) / 2;

	g = Random(2, p - 1);

	if ((g < p - 1) && (mod_exp(g, q, p) != 1) && (GCD(g, p) == 1)) break;
} while (true);
}

int User::Generate() {
	int num = Random(2, 2000);
	return num;
}

unsigned long long User::Generate_p() {
	unsigned long long num = Prime_random(10000, 100000);
	return num;
}

void User::Generate_p_q(unsigned long long &_fi, unsigned long long&_n) {
	p = Prime_random(10, 100);
	q = Prime_random(10, 100);
	_n = p * q;
	_fi = (p-1) * (q-1);
	//cout << p << " " << q << endl;
}

unsigned long long User::mod_invert(unsigned long long _a, unsigned long long _p) {

	unsigned long long u1 = _p;
	unsigned long long u2 = 0;
	unsigned long long v1 = _a;
	unsigned long long v2 = 1;

	while (v1 != 0)
	{
		unsigned long long q = u1 / v1;
		unsigned long long t1 = u1 - q * v1;
		unsigned long long t2 = u2 - q * v2;
		u1 = v1;
		u2 = v2;
		v1 = t1;
		v2 = t2;
	}

	return u1 == 1 ? (u2 + _p) % _p : -1;
}

void User::Insert_Message() {
	cout << "¬ведите сообщение: ";
	cin >> message;
	for (auto c : message) {
		data.push_back(c);
	}
	
}

void User::Set_message(string _message) {
	message = _message;
}

string User::Get_message() {
	return message;
}

void User::Set_data(vector<int> _data) {
	data.clear();
	data = _data;
}

vector <int> User::Get_data() {
	return data;
}



