#include <iostream>
#include <string>
#include <Windows.h>
#include <iomanip>
#include "Account.h"
#include "base64.h"
using namespace std;

Account::Account()
{
	no = password = "";
	isAdmin = 0;
}

Account::Account(string Ano, int AisAdmin)
{
	no = Ano;
	password = base64_encryption("123456");
	isAdmin = AisAdmin;
}

Account::Account(string Ano, string Apassword, int AisAdmin)
{
	no = Ano;
	password = Apassword;
	isAdmin = AisAdmin;
}

string Account::getNo()
{
	return no;
}

string Account::getPassword()
{
	return password;
}

int Account::getIsAdmin()
{
	return isAdmin;
}

bool Account::Login(string Apassword)
{
	return base64_decryption(password)==Apassword;
}

void Account::resetPassword(string origin, string newp1, string newp2)
{
	if (origin != base64_decryption(password))
	{
		cout << "\n\n";
		cout << setw(62)<< "Ô­ÃÜÂë´íÎó!ÐÞ¸ÄÃÜÂëÊ§°Ü!" << endl;
		Sleep(2000);
		return;
	}
	if (newp1 != newp2)
	{
		cout << "\n\n";
		cout << setw(67) << "Á½´ÎÊäÈëµÄÃÜÂë²»Ò»ÖÂ!ÐÞ¸ÄÃÜÂëÊ§°Ü!" << endl;
		Sleep(2000);
		return;
	}
	for (int i = 0; i < newp1.size(); i++)
		if (!((newp1[i] >= '0'&&newp1[i] <= '9') || (newp1[i] >= 'a'&&newp1[i] <= 'z') || (newp1[i] >= 'A'&&newp1[i] <= 'Z')))
		{
			cout << "\n\n";
			cout << setw(66) << "ÐÂÃÜÂëº¬ÓÐ·Ç·¨×Ö·û!ÐÞ¸ÄÃÜÂëÊ§°Ü!" << endl;
			Sleep(2000);
			return;
		}
	password = base64_encryption(newp1);
	cout << "\n\n";
	cout << setw(56) << "ÐÞ¸ÄÃÜÂë³É¹¦!" << endl;
	Sleep(2000);
}
