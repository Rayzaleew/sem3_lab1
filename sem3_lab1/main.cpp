#include <iostream>
#include <ctime>
#include "User.h"
#include "DiffiHelman.h"
#include "Elgamal.h"
#include "Shamir.h"
#include "RSA.h"
using namespace std;

void DH() {
	int g, p;
	User Server;
	Server.Generate(g, p); 
	cout << "Сгенерированы числа g и p: " << g << " " << p << endl;
	DiffiHelman first_user("Алиса", g, p), second_user("Боб", g, p);
	first_user.Set_X(first_user.Generate());
	cout << "Пользователь " << first_user.Get_name() << " сгенерировал число а - " << first_user.Get_X() << endl;
	second_user.Set_X(second_user.Generate());
	cout << "Пользователь " << second_user.Get_name() << " сгенерировал число б - " << second_user.Get_X() << endl;
	first_user.Calc_Y();
	cout << "Пользователь " << first_user.Get_name() << " вычислил число А - " << first_user.Get_Y() << endl;
	second_user.Calc_Y();
	cout << "Пользователь " << second_user.Get_name() << " вычислил число Б - " << second_user.Get_Y() << endl;
	first_user.Calc_K(second_user.Get_Y());
	cout << "Пользователь " << first_user.Get_name() << " вычислил число K - " << first_user.Get_K() << endl;
	second_user.Calc_K(first_user.Get_Y());
	cout << "Пользователь " << second_user.Get_name() << " вычислил число K - " << second_user.Get_K() << endl;



}

void EG() {
	int g, p;
	User Server;
	Server.Generate(g, p);
	cout << "Сгенерированы числа g и p: " << g << " " << p << endl;
	Elgamal first_user("Алиса", g, p), second_user("Боб", g, p);
	second_user.Generate_x_y();
	cout << "Публичный ключ y: " << second_user.Get_Y() << endl;
	first_user.Set_Y(second_user.Get_Y());
	cout << "Ключ передан пользователю " << first_user.Get_name() << endl;
	first_user.Insert_Message();
	first_user.Encrypt();
	second_user.Set_enc_text(first_user.Get_enc_text());
	cout << "Зашифрованное сообщение передано пользователю " << second_user.Get_name() << endl;
	cout << "Зашифрованное сообщение: ";
	cout << second_user.Get_enc_text() << endl;
	second_user.Decrypt();
	cout << "Расшифрованное сообщение: " << second_user.Get_message() << endl;

}

void Sh() {
	User Server;
	unsigned long long p;
	p = Server.Generate_p();
	Shamir first_user("Алиса", p), second_user("Боб", p);
	first_user.Generate_a();
	second_user.Generate_a();
	cout << "Сгенерированы закрытые ключи а и а' " << endl;
	first_user.Insert_Message();
	first_user.Encrypt(first_user.Get_a());
	first_user.Send(second_user);
	cout << "Зашифрованное сообщение передано пользователю " << second_user.Get_name() << endl;
	second_user.Encrypt(second_user.Get_a());
	second_user.Send(first_user);
	cout << "Дважды зашифрованное сообщение передано пользователю " << first_user.Get_name() << endl;
	first_user.Encrypt(first_user.Get_a_invert());
	first_user.Send(second_user);
	cout << "Трижды зашифрованное сообщение передано пользователю " << second_user.Get_name() << endl;
	second_user.Decrypt(second_user.Get_a_invert());
	cout << "Расшифрованное сообщение: " << second_user.Get_message() << endl;
	

}

void Rsa() {
	unsigned long long fi, n;
	User Server;
	Server.Generate_p_q(fi, n);
	RSA first_user("Алиса", fi, n), second_user("Боб", fi, n);
	cout << "Были сгенерированы числа p и q, а также найдено число n и значение fi(n)" << endl;
	second_user.Generate_e();
	first_user.Set_e(second_user.Get_e());
	cout << "Было сгенерировано публичное число e: " << second_user.Get_e() << endl;
	second_user.Generate_d();
	cout << "Было сгенерировано приватное число d: " << second_user.Get_d() << endl;
	first_user.Insert_Message();
	first_user.Encrypt();
	first_user.Send(second_user);
	cout << "Было зашифровано и отправлено сообщение: " << second_user.Get_data() << endl;
	second_user.Decrypt();

	cout << "Расшифрованное сообщение: " << second_user.Get_message() << endl;


}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	cout << "Выберите криптографический протокол: " << endl;
	cout << "1. Диффи-Хелман " << endl;
	cout << "2. Эль Гамаль " << endl;
	cout << "3. Шамир " << endl;
	cout << "4. RSA " << endl;
	
	while (true) {
		cin >> choice;
		switch (choice) {
		case 1: 
			DH();
			break;
		case 2: 
			EG();
			break;
		case 3: 
			Sh();
			break;
		case 4: 
			Rsa();
			break;
		default: cout << "Некорректный ввод! " << endl;

			
		}
	}

	return 0;
}