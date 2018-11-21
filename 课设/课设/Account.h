#pragma once
#include <iostream>
#include <string>
using namespace std;

class Account {
private:
	string no;//账号
	string password;//密码
	int isAdmin;//是否是管理员
public:
	Account();//无参构造函数
	Account(string Ano,int AisAdmin);//有参构造函数
	Account(string Ano, string Apassword, int AisAdmin);
	string getNo();
	string getPassword();
    int getIsAdmin();
	bool Login(string Apassword);//判断输入的密码是否正确
	void resetPassword(string origin, string newp1, string newp2);//验证原密码,并输入新密码
};

