#include "studentList.h"
#include<iostream>
#include<string>
#include<vector>
#include<sstream>
#include<fstream>
#include<algorithm>
#include <iomanip>
using namespace std;

StudentList::StudentList(vector<Student> mStuList){
	stuList = mStuList;
}

StudentList::StudentList(string filePos)
{
	Student tempStu;
	string str;
	string no, name, sex, age, dept, cla, tel;
	vector<string> temp;
	temp.resize(8);
	ifstream in(filePos);
	if (!in) {
		cout << endl;
		cout << setw(56)<< "无法读取数据!" << endl;
	}
	else {
		while (getline(in, str)) {
			istringstream sin(str);
			int i = 0;
			while (sin >> temp[i]) {
				i++;
			}
			no = temp[0], name = temp[1], sex = temp[2], age = temp[3], dept = temp[4], cla = temp[5], tel = temp[6];
			tempStu = *(new Student(no, name, sex, age, dept, cla, tel));
			stuList.push_back(tempStu);
		}
	}
}

StudentList::StudentList(string stuFile, string selCouFile)
{
	Student tempStu;
	string str;
	string cStr;
	string no, name, sex, age, dept, cla, tel;
	vector<string> temp;
	temp.resize(8);
	ifstream stuIn(stuFile);
	ifstream selIn(selCouFile);
	if ((!stuIn)||(!selIn)) {
		cout << endl;
		cout << setw(56) << "无法读取数据!" << endl;
	}
	else
	{
		while (getline(stuIn, str)) {
			istringstream sin(str);
			int i = 0;
			while (sin >> temp[i]) {
				i++;
			}
			no = temp[0], name = temp[1], sex = temp[2], age = temp[3], dept = temp[4], cla = temp[5], tel = temp[6];
			getline(selIn, cStr);
			istringstream csin(cStr);
			string tempStr;
			vector<string> cTemp;
			csin >> tempStr;
			while (csin >> tempStr) {
				cTemp.push_back(tempStr);
			}
			tempStu = *(new Student(no, name, sex, age, dept, cla, tel, cTemp));
			stuList.push_back(tempStu);
		}
	}
}

int StudentList::GetListLength()
{
	return stuList.size();
}

Student* StudentList::SearchWithPos(int pos)
{
	if (pos < 0 || pos >= stuList.size()) {
		//cout << "查找位置非法" << endl;
		return NULL;
	}
	return &(stuList[pos]);
}

int StudentList::SearchWithNo(string Sno)
{
	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i].getNo() == Sno)
			return i;
	}
	return -1;
}

void StudentList::SearchWithDept(string Sdept,vector<int>& pos)
{
	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i].getDept() == Sdept)
			pos.push_back(i);
	}
}

void StudentList::SearchWithCla(string Scla,vector<int>& pos)
{
	for (int i = 0; i < stuList.size(); i++) {
		if (stuList[i].getCla() == Scla)
			pos.push_back(i);
	}
}

void StudentList::UpdateStuInfo(string no)
{
	int pos = SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(55) << "未找到学生记录!" << endl;
	}
	else {
		cout << "          ---------------------------------------------------------------------------------" << endl;
		cout << "             学号       姓名       性别      年龄    系别       班级      联系方式" << endl;
		cout << "          ---------------------------------------------------------------------------------" << endl;
		stuList[pos].printStuInfo();
		cout << "          ---------------------------------------------------------------------------------" << endl;
		string name, sex, age, dept, cla, tel;
		cout << endl << endl;
		cout << setw(49) << "请更新学生信息:" << endl;
		cout << endl;
		cout << setw(50) << "姓名：";
		cin >> name;
		cout << setw(50) << "性别(男/女)：";
		cin >> sex;
		if (sex != "男"&&sex != "女")
		{
			cout << endl;
			cout << setw(56) << "请输入男/女!" << endl;
			return;
		}
		cout << setw(50) << "年龄：";
		cin >> age;
		if (atoi(age.c_str()) <= 0 || atoi(age.c_str()) >= 100)
		{
			cout << endl;
			cout << setw(55) << "输入非法!" << endl;
			return;
		}
		cout << setw(50) << "系别：";
		cin >> dept;
		cout << setw(50) << "班级：";
		cin >> cla;
		cout << setw(54) << "联系方式：";
		cin >> tel;
		if (tel.size() != 11)
		{
			cout << endl;
			cout << setw(55) << "输入非法!" << endl;
			return;
		}
		for(int i=0;i<11;i++)
			if (tel[i]<'0' || tel[i]>'9')
			{
				cout << endl;
				cout << setw(55) << "输入非法!" << endl;
				return;
			}
		Student tempStu = *(new Student(no, name, sex, age, dept, cla, tel));
		stuList[pos] = tempStu;
	}
}

void StudentList::Insert(int pos, Student s)
{
	stuList.insert(stuList.begin() + pos, s);
}

void StudentList::Insert(Student s)
{
	stuList.insert(stuList.end(), s);
	Sort();
}

void StudentList::Merge(StudentList sList)
{
	for (int i = 0; i < sList.GetListLength(); i++) {
		int pos = SearchWithNo(sList.stuList[i].getNo());
		if (pos == -1)
			Insert(sList.stuList[i]);
	}
}

void StudentList::Delete(int pos)
{
	stuList.erase(stuList.begin() + pos);
}

void StudentList::Delete(vector<int> pos)
{
	vector<Student> temp;
	int j = 0;
	int k = 0;
	temp.resize(stuList.size() - pos.size());
	for (int i = 0; i < stuList.size(); i++) {
		if (k < pos.size() && i == pos[k])
			k++;
		else
			temp[j++] = stuList[i];
	}
	stuList = temp;
}

void StudentList::Sort()
{
	sort(stuList.begin(), stuList.end());
}

void StudentList::PrintStuList()
{
	cout << "          -------------------------------------------------------------------------------" << endl;
	cout << "             学号       姓名       性别      年龄    系别       班级      联系方式" << endl;
	cout << "          -------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < stuList.size(); i++) {
		stuList[i].printStuInfo();
		cout << "          -------------------------------------------------------------------------------" << endl;
	}
}

void StudentList::Save(string stuFile,string selCouFile)
{
	ofstream sOut,cOut;
	sOut.open(stuFile);
	cOut.open(selCouFile);
	if ((!sOut)||(!cOut)) {
		cout << endl;
		cout << setw(56) << "无法存储数据!" << endl;
	}
	else {
		for (int i = 0; i < stuList.size(); i++) {
			sOut << stuList[i].getNo() << ' ' << stuList[i].getName() << ' ';
			sOut << stuList[i].getSex() << ' ' << stuList[i].getAge() << ' ';
			sOut << stuList[i].getDept() << ' ' << stuList[i].getCla() << ' ';
			sOut << stuList[i].getTel() << endl;
			vector<string> temp = stuList[i].getCnoList();
			cOut << stuList[i].getNo();
			if (temp.size() == 0)
				cOut << endl;
			else
				cOut << " ";
			for (int j = 0; j < temp.size(); j++) {
				if (j != temp.size() - 1)
					cOut << temp[j] << ' ';
				else
					cOut << temp[j] << endl;
			}
		}
		//cout << "保存成功！" << endl;
	}
}

void StudentList::SetTimeCode(CourseList & gloCouList)
{
	for (int i = 0; i < stuList.size(); i++) {
		stuList[i].setCouTime(gloCouList);
	}
}

