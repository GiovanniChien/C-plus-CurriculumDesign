#pragma once
#include <iostream>
using namespace std;
class Course {
private:
	string no;	//�γ̴���
	string name;//�γ�����
	string type;//�γ�����
	int period;	//��ѧʱ
	int credit;	//ѧ��
	int term;	//����ѧ��
	int num;	//ѡ������
	int maxNum;	//��ѡ����
	string timeCode;//ʱ����
public:
	Course();//�޲ι��캯��
	Course(string Cno, string Cname, string Ctype, int Cperiod, int Ccredit, int Cterm, int Cnum, int CmaxNum, string CtimeCode);//�вι��캯��
	string getNo();
	string getName();
	string getType();
	int getPeriod();
	int getCredit();
	int getTerm();
	int getNum();
	int getMaxNum();
	string getTimeCode();
	void setNo(string Cno);
	void setName(string Cname);
	void setType(string Ctype);
	void setPeriod(int Cperiod);
	void setCredit(int Ccredit);
	void setTerm(int Cterm);
	void setNum(int Cnum);
	void printCouInfo();//��ӡ�γ���Ϣ
	bool operator==(Course& c);
	bool operator<(Course& c);
	void plus();
	void minus();
	bool canSelect();//�ж��Ƿ�ﵽ��ѡ���������ﵽ�򲻿�ѡ
};