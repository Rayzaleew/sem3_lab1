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
	cout << "������������� ����� g � p: " << g << " " << p << endl;
	DiffiHelman first_user("�����", g, p), second_user("���", g, p);
	first_user.Set_X(first_user.Generate());
	cout << "������������ " << first_user.Get_name() << " ������������ ����� � - " << first_user.Get_X() << endl;
	second_user.Set_X(second_user.Generate());
	cout << "������������ " << second_user.Get_name() << " ������������ ����� � - " << second_user.Get_X() << endl;
	first_user.Calc_Y();
	cout << "������������ " << first_user.Get_name() << " �������� ����� � - " << first_user.Get_Y() << endl;
	second_user.Calc_Y();
	cout << "������������ " << second_user.Get_name() << " �������� ����� � - " << second_user.Get_Y() << endl;
	first_user.Calc_K(second_user.Get_Y());
	cout << "������������ " << first_user.Get_name() << " �������� ����� K - " << first_user.Get_K() << endl;
	second_user.Calc_K(first_user.Get_Y());
	cout << "������������ " << second_user.Get_name() << " �������� ����� K - " << second_user.Get_K() << endl;



}

void EG() {
	int g, p;
	User Server;
	Server.Generate(g, p);
	cout << "������������� ����� g � p: " << g << " " << p << endl;
	Elgamal first_user("�����", g, p), second_user("���", g, p);
	second_user.Generate_x_y();
	cout << "��������� ���� y: " << second_user.Get_Y() << endl;
	first_user.Set_Y(second_user.Get_Y());
	cout << "���� ������� ������������ " << first_user.Get_name() << endl;
	first_user.Insert_Message();
	first_user.Encrypt();
	second_user.Set_enc_text(first_user.Get_enc_text());
	cout << "������������� ��������� �������� ������������ " << second_user.Get_name() << endl;
	cout << "������������� ���������: ";
	cout << second_user.Get_enc_text() << endl;
	second_user.Decrypt();
	cout << "�������������� ���������: " << second_user.Get_message() << endl;

}

void Sh() {
	User Server;
	unsigned long long p;
	p = Server.Generate_p();
	Shamir first_user("�����", p), second_user("���", p);
	first_user.Generate_a();
	second_user.Generate_a();
	cout << "������������� �������� ����� � � �' " << endl;
	first_user.Insert_Message();
	first_user.Encrypt(first_user.Get_a());
	first_user.Send(second_user);
	cout << "������������� ��������� �������� ������������ " << second_user.Get_name() << endl;
	second_user.Encrypt(second_user.Get_a());
	second_user.Send(first_user);
	cout << "������ ������������� ��������� �������� ������������ " << first_user.Get_name() << endl;
	first_user.Encrypt(first_user.Get_a_invert());
	first_user.Send(second_user);
	cout << "������ ������������� ��������� �������� ������������ " << second_user.Get_name() << endl;
	second_user.Decrypt(second_user.Get_a_invert());
	cout << "�������������� ���������: " << second_user.Get_message() << endl;
	

}

void Rsa() {
	unsigned long long fi, n;
	User Server;
	Server.Generate_p_q(fi, n);
	RSA first_user("�����", fi, n), second_user("���", fi, n);
	cout << "���� ������������� ����� p � q, � ����� ������� ����� n � �������� fi(n)" << endl;
	second_user.Generate_e();
	first_user.Set_e(second_user.Get_e());
	cout << "���� ������������� ��������� ����� e: " << second_user.Get_e() << endl;
	second_user.Generate_d();
	cout << "���� ������������� ��������� ����� d: " << second_user.Get_d() << endl;
	first_user.Insert_Message();
	first_user.Encrypt();
	first_user.Send(second_user);
	cout << "���� ����������� � ���������� ���������: " << second_user.Get_data() << endl;
	second_user.Decrypt();

	cout << "�������������� ���������: " << second_user.Get_message() << endl;


}

int main() {
	srand(time(0));
	setlocale(LC_ALL, "Rus");
	int choice = 0;
	cout << "�������� ����������������� ��������: " << endl;
	cout << "1. �����-������ " << endl;
	cout << "2. ��� ������ " << endl;
	cout << "3. ����� " << endl;
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
		default: cout << "������������ ����! " << endl;

			
		}
	}

	return 0;
}