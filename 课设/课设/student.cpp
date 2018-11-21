#include "student.h"
#include<iostream>
#include<string>
#include<vector>
#include <iomanip>

using namespace std;

Student::Student(){
	no = name = sex = age = dept = cla = tel = "";
	cnoList.resize(0);
	couTime.resize(5);
	couTime[0] = "000000000000000";
	couTime[1] = "001000000000000";
	couTime[2] = "010000000000000";
	couTime[3] = "011000000000000";
	couTime[4] = "100000000000000";
}

Student::Student(string Sno, string Sname, string Ssex, string Sage, string Sdept, string Scla, string Stel){
	no = Sno;
	name = Sname;
	sex = Ssex;
	age = Sage;
	dept = Sdept;
	cla = Scla;
	tel = Stel;
	cnoList.resize(0);
	couTime.resize(5);
	couTime[0] = "000000000000000";
	couTime[1] = "001000000000000";
	couTime[2] = "010000000000000";
	couTime[3] = "011000000000000";
	couTime[4] = "100000000000000";
}

Student::Student(string Sno, string Sname, string Ssex, string Sage, string Sdept, string Scla, string Stel, vector<string> cList)
{
	no = Sno;
	name = Sname;
	sex = Ssex;
	age = Sage;
	dept = Sdept;
	cla = Scla;
	tel = Stel;
	cnoList = cList;
	couTime.resize(5);
	couTime[0] = "000000000000000";
	couTime[1] = "001000000000000";
	couTime[2] = "010000000000000";
	couTime[3] = "011000000000000";
	couTime[4] = "100000000000000";
}

string Student::getNo(){
	return no;
}

string Student::getName(){
	return name;
}

string Student::getSex()
{
	return sex;
}

string Student::getAge() {
	return age;
}

string Student::getDept() {
	return dept;
}

string Student::getCla() {
	return cla;
}

string Student::getTel() {
	return tel;
}

vector<string> Student::getCnoList()
{
	return cnoList;
}

void Student::setDept(string Sdept){
	dept = Sdept;
}

void Student::setCla(string Scla){
	cla = Scla;
}

void Student::setTel(string Stel) {
	tel = Stel;
}

void Student::setCouTime(CourseList & gloCouList)
{
	Course* c;
	int pos;
	string cTimeCode;
	for (int i = 0; i < cnoList.size(); i++) {
		pos = gloCouList.SearchWithNo(cnoList[i]);
		c = gloCouList.SearchWithPos(pos);
		cTimeCode = c->getTimeCode();
		string cTimeCodeHigh = cTimeCode.substr(0, 3);
		string cTimeCodeLow = cTimeCode.substr(3, 12);
		if (cTimeCodeHigh == "000") {
			string sTimeCodeLow = couTime[0].substr(3, 12);
			string res = "000000000000";
			for (int i = 0; i < 12; i++) {
				if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
					res[i] = '1';
			}
			couTime[0] = cTimeCodeHigh + res;
		}
		else if (cTimeCodeHigh == "001") {
			string sTimeCodeLow = couTime[1].substr(3, 12);
			string res = "000000000000";
			for (int i = 0; i < 12; i++) {
				if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
					res[i] = '1';
			}
			couTime[1] = cTimeCodeHigh + res;
		}
		else if (cTimeCodeHigh == "010") {
			string sTimeCodeLow = couTime[2].substr(3, 12);
			string res = "000000000000";
			for (int i = 0; i < 12; i++) {
				if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
					res[i] = '1';
			}
			couTime[2] = cTimeCodeHigh + res;
		}
		else if (cTimeCodeHigh == "011") {
			string sTimeCodeLow = couTime[3].substr(3, 12);
			string res = "000000000000";
			for (int i = 0; i < 12; i++) {
				if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
					res[i] = '1';
			}
			couTime[3] = cTimeCodeHigh + res;
		}
		else if (cTimeCodeHigh == "100") {
			string sTimeCodeLow = couTime[4].substr(3, 12);
			string res = "000000000000";
			for (int i = 0; i < 12; i++) {
				if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
					res[i] = '1';
			}
			couTime[4] = cTimeCodeHigh + res;
		}
	}
}

void Student::updateCouTime(string cTimeCode)
{
	string cTimeCodeHigh = cTimeCode.substr(0, 3);
	string cTimeCodeLow = cTimeCode.substr(3, 12);
	if (cTimeCodeHigh == "000") {
		string sTimeCodeLow = couTime[0].substr(3, 12);
		string res = "000000000000";
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
				res[i] = '1';
		}
		couTime[0] = cTimeCodeHigh + res;
	}
	else if (cTimeCodeHigh == "001") {
		string sTimeCodeLow = couTime[1].substr(3, 12);
		string res = "000000000000";
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
				res[i] = '1';
		}
		couTime[1] = cTimeCodeHigh + res;
	}
	else if (cTimeCodeHigh == "010") {
		string sTimeCodeLow = couTime[2].substr(3, 12);
		string res = "000000000000";
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
				res[i] = '1';
		}
		couTime[2] = cTimeCodeHigh + res;
	}
	else if (cTimeCodeHigh == "011") {
		string sTimeCodeLow = couTime[3].substr(3, 12);
		string res = "000000000000";
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
				res[i] = '1';
		}
		couTime[3] = cTimeCodeHigh + res;
	}
	else if (cTimeCodeHigh == "100") {
		string sTimeCodeLow = couTime[4].substr(3, 12);
		string res = "000000000000";
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') || (cTimeCodeLow[i] == '1'))
				res[i] = '1';
		}
		couTime[4] = cTimeCodeHigh + res;
	}
}

void Student::MinusCouTime(string cTimeCode)
{
	string cTimeCodeHigh = cTimeCode.substr(0, 3);
	string cTimeCodeLow = cTimeCode.substr(3, 12);
	if (cTimeCodeHigh == "000") {
		string sTimeCodeLow = couTime[0].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				sTimeCodeLow[i] = '0';
		}
		couTime[0] = cTimeCodeHigh + sTimeCodeLow;
	}
	else if (cTimeCodeHigh == "001") {
		string sTimeCodeLow = couTime[1].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				sTimeCodeLow[i] = '0';
		}
		couTime[0] = cTimeCodeHigh + sTimeCodeLow;
	}
	else if (cTimeCodeHigh == "010") {
		string sTimeCodeLow = couTime[2].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				sTimeCodeLow[i] = '0';
		}
		couTime[0] = cTimeCodeHigh + sTimeCodeLow;
	}
	else if (cTimeCodeHigh == "011") {
		string sTimeCodeLow = couTime[3].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				sTimeCodeLow[i] = '0';
		}
		couTime[0] = cTimeCodeHigh + sTimeCodeLow;
	}
	else if (cTimeCodeHigh == "100") {
		string sTimeCodeLow = couTime[4].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				sTimeCodeLow[i] = '0';
		}
		couTime[0] = cTimeCodeHigh + sTimeCodeLow;
	}
}

void Student::printStuInfo(){
	cout << setw(18) << no;
	cout << setw(10) << name;
	cout << setw(10) << sex;
	cout << setw(10) << age;
	cout << setw(10) << dept;
	cout << setw(10) << cla;
	cout << setw(15) << tel << endl;
}

bool Student::operator==(Student & s)
{
	return no==s.no;
}

bool Student::operator<(Student & s)
{
	return no < s.no;
}

bool Student::IsSelect(string cno)
{
	for (int i = 0; i < cnoList.size(); i++) {
		if (cno == cnoList[i])
			return true;
	}
	return false;
}

bool Student::SelectCourse(string cno)
{
	if (!IsSelect(cno)) {
		cnoList.push_back(cno);
		return true;
	}
	else
		return false;
}

bool Student::DropCourse(string cno)
{
	for (int i = 0; i < cnoList.size(); i++) {
		if (cnoList[i] == cno) {
			cnoList.erase(cnoList.begin() + i);
			return true;
		}
	}
	return false;
}

bool Student::IsTimeConflict(string cTimeCode)
{
	string cTimeCodeHigh = cTimeCode.substr(0, 3);
	string cTimeCodeLow = cTimeCode.substr(3, 12);
	if (cTimeCodeHigh == "000") {
		string sTimeCodeLow = couTime[0].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				return true;
		}
	}
	else if (cTimeCodeHigh == "001") {
		string sTimeCodeLow = couTime[1].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				return true;
		}
	}
	else if (cTimeCodeHigh == "010") {
		string sTimeCodeLow = couTime[2].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				return true;
		}
	}
	else if (cTimeCodeHigh == "011") {
		string sTimeCodeLow = couTime[3].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				return true;
		}
	}
	else if (cTimeCodeHigh == "100") {
		string sTimeCodeLow = couTime[4].substr(3, 12);
		for (int i = 0; i < 12; i++) {
			if ((sTimeCodeLow[i] == '1') && (cTimeCodeLow[i] == '1'))
				return true;
		}
	}
	return false;
}
