#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	string no;//�˺�
	string password;//����
	int isAdmin;//�Ƿ��ǹ���Ա
public:
	Account();//�޲ι��캯��
	Account(string Ano,int AisAdmin);//�вι��캯��
	Account(string Ano, string Apassword, int AisAdmin);
	string getNo();
	string getPassword();
    int getIsAdmin();
	bool Login(string Apassword);//�ж�����������Ƿ���ȷ
	void resetPassword(string origin, string newp1, string newp2);//��֤ԭ����,������������
};

