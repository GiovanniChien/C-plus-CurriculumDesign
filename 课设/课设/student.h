#pragma once

#include<iostream>
#include<string>
#include<vector>
#include"CourseList.h"

using namespace std;

class Student {
private:
	string no;//学号
	string name;//姓名
	string sex;//性别
	string age;//年龄
	string dept;//系别
	string cla;//班级
	string tel;//联系方式
	vector<string> cnoList;//选课记录
	vector<string> couTime;//所选课程的时间码
public:
	Student();//无参构造函数
	Student(string Sno, string Sname, string Ssex, string Sage, string Sdept, string Scla, string Stel);//有参构造函数
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
	void updateCouTime(string cTimeCode);//选课之后更新学生的时间码
	void MinusCouTime(string cTimeCode);//退课之后更新学生的时间码
	void printStuInfo();//打印学生信息
	bool operator==(Student& s);
	bool operator<(Student& s);
	bool IsSelect(string cno);//判断该学生是否已经选修某门课程
	bool SelectCourse(string cno);//选课
	bool DropCourse(string cno);//退课
	bool IsTimeConflict(string cTimeCode);
};