#include <iostream>
#include <string>
#include <iomanip>
#include "Course.h"
using namespace std;

Course::Course()
{
	no = name = type = "";
	period = credit = term = num = maxNum = 0;
	timeCode = "000000000000000";
}

Course::Course(string Cno, string Cname, string Ctype, int Cperiod, int Ccredit, int Cterm, int Cnum, int CmaxNum, string CtimeCode)
{
	no = Cno;
	name = Cname;
	type = Ctype;
	period = Cperiod;
	credit = Ccredit;
	term = Cterm;
	num = Cnum;
	maxNum = CmaxNum;
	timeCode = CtimeCode;
}

string Course::getNo()
{
	return no;
}

string Course::getName()
{
	return name;
}

string Course::getType()
{
	return type;
}

int Course::getPeriod()
{
	return period;
}

int Course::getCredit()
{
	return credit;
}

int Course::getTerm()
{
	return term;
}

int Course::getNum()
{
	return num;
}

int Course::getMaxNum()
{
	return maxNum;
}

string Course::getTimeCode()
{
	return timeCode;
}

void Course::setNo(string Cno)
{
	no = Cno;
}

void Course::setName(string Cname)
{
	name = Cname;
}

void Course::setType(string Ctype)
{
	type = Ctype;
}

void Course::setPeriod(int Cperiod)
{
	period = Cperiod;
}

void Course::setCredit(int Ccredit)
{
	credit = Ccredit;
}

void Course::setTerm(int Cterm)
{
	term = Cterm;
}

void Course::setNum(int Cnum)
{
	num = Cnum;
}

void Course::printCouInfo()
{
	cout << setw(10) << no;
	cout << setw(20) << name;
	cout << setw(10) << type;
	cout << setw(10) << period;
	cout << setw(10) << credit;
	cout << setw(10) << term;
	cout << setw(10) << num;
	cout << setw(10) << maxNum << endl;
}

bool Course::operator==(Course & c)
{
	return no==c.no;
}

bool Course::operator<(Course & c)
{
	return no < c.no;
}

void Course::plus()
{
	num++;
}

void Course::minus()
{
	num--;
}

bool Course::canSelect()
{
	return num < maxNum;
}
