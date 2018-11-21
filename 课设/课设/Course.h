#pragma once
#include <iostream>
using namespace std;
class Course {
private:
	string no;	//课程代码
	string name;//课程名称
	string type;//课程性质
	int period;	//总学时
	int credit;	//学分
	int term;	//开课学期
	int num;	//选修人数
	int maxNum;	//限选人数
	string timeCode;//时间码
public:
	Course();//无参构造函数
	Course(string Cno, string Cname, string Ctype, int Cperiod, int Ccredit, int Cterm, int Cnum, int CmaxNum, string CtimeCode);//有参构造函数
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
	void printCouInfo();//打印课程信息
	bool operator==(Course& c);
	bool operator<(Course& c);
	void plus();
	void minus();
	bool canSelect();//判断是否达到限选人数，若达到则不可选
};