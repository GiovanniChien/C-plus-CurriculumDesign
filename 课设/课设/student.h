#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"CourseList.h"

using namespace std;

class Student {
private:
	string no;//ѧ��
	string name;//����
	string sex;//�Ա�
	string age;//����
	string dept;//ϵ��
	string cla;//�༶
	string tel;//��ϵ��ʽ
	vector<string> cnoList;//ѡ�μ�¼
	vector<string> couTime;//��ѡ�γ̵�ʱ����
public:
	Student();//�޲ι��캯��
	Student(string Sno, string Sname, string Ssex, string Sage, string Sdept, string Scla, string Stel);//�вι��캯��
	Student(string Sno, string Sname, string Ssex, string Sage, string Sdept, string Scla, string Stel, vector<string> cList);
	string getNo();//
	string getName();
	string getSex();
	string getAge();
	string getDept();
	string getCla();
	string getTel();
	vector<string> getCnoList();
	void setDept(string Sdept);
	void setCla(string Scla);
	void setTel(string Stel);
	void setCouTime(CourseList& gloCouList);
	void updateCouTime(string cTimeCode);//ѡ��֮�����ѧ����ʱ����
	void MinusCouTime(string cTimeCode);//�˿�֮�����ѧ����ʱ����
	void printStuInfo();//��ӡѧ����Ϣ
	bool operator==(Student& s);
	bool operator<(Student& s);
	bool IsSelect(string cno);//�жϸ�ѧ���Ƿ��Ѿ�ѡ��ĳ�ſγ�
	bool SelectCourse(string cno);//ѡ��
	bool DropCourse(string cno);//�˿�
	bool IsTimeConflict(string cTimeCode);
};