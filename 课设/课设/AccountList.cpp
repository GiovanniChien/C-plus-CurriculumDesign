#include <iostream>
#include <vector>
#include <string>
#include<sstream>
#include<fstream>
#include <Windows.h>
#include <iomanip>
#include "AccountList.h"
#include"Account.h"
#include "base64.h"
using namespace std;

AccountList::AccountList(vector<Account> mAcntList)
{
	acntList = mAcntList;
	isOpen = 0;
}

AccountList::AccountList(string filePos)
{
	Account tempAcnt;
	string str;
	string no, password;
	int isAdmin;
	vector<string> temp;
	temp.resize(4);
	ifstream in(filePos);
	if (!in) {
		cout << "无法读取数据" << endl;
		exit(0);
	}
	getline(in, str);
	isOpen = atoi(str.c_str());
	while (getline(in, str)) {
		istringstream sin(str);
		int i = 0;
		while (sin >> temp[i]) {
			i++;
		}
		no = temp[0], password = temp[1], isAdmin = atoi(temp[2].c_str());
		tempAcnt = *(new Account(no, password, isAdmin));
		acntList.push_back(tempAcnt);
	}
}

int AccountList::GetListLength()
{
	return acntList.size();
}

int AccountList::Search(string Ano)
{
	for (int i = 0; i < acntList.size(); i++)
		if (acntList[i].getNo() == Ano)
			return i;
	return -1;
}

bool AccountList::Login(string Ano, string Apassword)
{
	int pos = Search(Ano);
	if (pos == -1)
	{
		cout << "\n\n\n";
		cout << setw(25) << "账户不存在!" << endl;
		Sleep(2000);
		return false;
	}
	if (acntList[pos].Login(Apassword))
		return true;
	else
	{
		cout << "\n\n\n";
		cout << setw(28) << "账号和密码不匹配!" << endl;
		Sleep(2000);
		return false;
	}
}

int AccountList::isAdmin(string Ano)
{
	int pos = Search(Ano);
	return acntList[pos].getIsAdmin();
}

void AccountList::Insert(string Ano, int isAdmin)
{
	Account temp(Ano, isAdmin);
	int i = 0;
	while (i < acntList.size())
		if (Ano > acntList[i].getNo())
			i++;
		else
			break;
	acntList.insert(acntList.begin() + i, temp);
}

void AccountList::Delete(string Ano)
{
	int pos = Search(Ano);
	acntList.erase(acntList.begin() + pos);
}

void AccountList::Delete(vector<Student> mStuList)
{
	for (int i = 0; i < mStuList.size(); i++)
		Delete(mStuList[i].getNo());
}

void AccountList::ResetPassword(string Ano, string origin, string newp1, string newp2)
{
	int pos = Search(Ano);
	acntList[pos].resetPassword(origin, newp1, newp2);
}

void AccountList::Save(string filePos)
{
	ofstream out;
	out.open(filePos);
	if (!out) {
		cout << endl;
		cout << setw(56) << "无法存储数据" << endl;
	}
	else {
		out << isOpen << endl;
		for (int i = 0; i < acntList.size(); i++) {
			out << acntList[i].getNo() << ' ' << acntList[i].getPassword() << ' ' << acntList[i].getIsAdmin() << endl;
		}
	}
}


bool AccountList::IsOpen()
{
	if (isOpen == 1)
		return true;
	else
		return false;
}

void AccountList::OpenSys()
{
	if (isOpen == 1) {
		cout << endl;
		cout << setw(64) << "学生选课已开放,请勿重复操作!" << endl;
	}
	else {
		isOpen = 1;
		cout << endl;
		cout << setw(58) << "成功开放学生选课!" << endl;
	}
}

void AccountList::CloseSys()
{
	if (isOpen == 0) {
		cout << endl;
		cout << setw(64) << "学生选课已关闭,请勿重复操作!" << endl;
	}
	else {
		isOpen = 0;
		cout << endl;
		cout << setw(58) << "成功关闭学生选课!" << endl;
	}
}
