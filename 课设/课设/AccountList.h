#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "Account.h"
#include "student.h"
using namespace std;

class AccountList {
private:
	vector<Account> acntList;
	int isOpen;
public:
	AccountList() {
		acntList.resize(0);
	}//无参构造函数
	AccountList(vector<Account> mAcntList);//有参构造函数
	AccountList(string filePos);//从账户信息表中读取数据
	int GetListLength();//获取链表长度
	int Search(string Ano);//按账号查找
	bool Login(string Ano, string Apassword);//判断账号和密码是否匹配
	int isAdmin(string Ano);
	void Insert(string Ano,int isAdmin);//注册账号
	void Delete(string Ano);//注销账号
	void Delete(vector<Student> mStuList);//批量注销账号
	void ResetPassword(string Ano, string origin, string newp1, string newp2);////验证账户原密码,并输入新密码
	void Save(string filePos);//保存账户信息
	bool IsOpen();//判断学生选课是否开放
	void OpenSys();//开放学生选课
	void CloseSys();//关闭学生选课
};