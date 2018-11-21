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
	}//�޲ι��캯��
	AccountList(vector<Account> mAcntList);//�вι��캯��
	AccountList(string filePos);//���˻���Ϣ���ж�ȡ����
	int GetListLength();//��ȡ������
	int Search(string Ano);//���˺Ų���
	bool Login(string Ano, string Apassword);//�ж��˺ź������Ƿ�ƥ��
	int isAdmin(string Ano);
	void Insert(string Ano,int isAdmin);//ע���˺�
	void Delete(string Ano);//ע���˺�
	void Delete(vector<Student> mStuList);//����ע���˺�
	void ResetPassword(string Ano, string origin, string newp1, string newp2);////��֤�˻�ԭ����,������������
	void Save(string filePos);//�����˻���Ϣ
	bool IsOpen();//�ж�ѧ��ѡ���Ƿ񿪷�
	void OpenSys();//����ѧ��ѡ��
	void CloseSys();//�ر�ѧ��ѡ��
};