#include "function.h"
#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
#include<vector>
#include<string>
#include <algorithm>
#include <iomanip>
#include <conio.h>
#include"AccountList.h"
#include"CourseList.h"
#include"studentList.h"

using namespace std;

void AddStuInfo(StudentList& gloStuList, AccountList& gloAcntList)
{
	string no, name, sex, age, dept, cla, tel;
	cout << "\n";
	cout << setw(49) << "请输入学生信息:" << endl;
	cout << "\n";
	cout << setw(50) << "学号：";
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos != -1) {
		cout << "\n";
		cout << setw(58) << "学生信息已存在!" << endl;
		Sleep(2000);
		return;
	}
	cout << setw(50) << "姓名：";
	cin >> name;
	cout << setw(50) << "性别：";
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
	for (int i = 0; i<11; i++)
		if (tel[i]<'0' || tel[i]>'9')
		{
			cout << endl;
			cout << setw(55) << "输入非法!" << endl;
			return;
		}
	Student tempStu = *(new Student(no, name, sex, age, dept, cla, tel));
	gloStuList.Insert(tempStu);
	gloAcntList.Insert(no,0);
	cout << endl << endl;
	cout << setw(57) << "添加学生成功!" << endl;
	cout << setw(59) << "学生账户注册成功!" << endl;
}

void MergeStuInfo(StudentList & gloStuList, AccountList& gloAcntList)
{
	string filePos;
	cout << "\n";
	cout << setw(50) << "请输入文件地址：";
	cin >> filePos;
	StudentList exStuList(filePos);
	gloStuList.Merge(exStuList);
	ifstream in(filePos);
	if (!in)
		return;
	else
	{
		string str, no;
		while (getline(in, str))
		{
			istringstream sin(str);
			sin >> no;
			gloAcntList.Insert(no, 0);
		}
		cout << endl << endl;
		cout << setw(57) << "添加学生成功!" << endl;
		cout << setw(59) << "学生账户注册成功!" << endl;
	}
}

void DelStuInfo(StudentList & gloStuList, AccountList& gloAcntList, CourseList &gloCouList)
{
	string no;
	cout << endl;
	cout << setw(50) << "请输入学号：";
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "学生信息不存在!" << endl;
		return;
	}
	Student* s = gloStuList.SearchWithPos(pos);
	vector<string> selected = s->getCnoList();
	for (int i = 0; i < selected.size(); i++)
		gloCouList.Minus(selected[i]);
	gloStuList.Delete(pos);
	gloAcntList.Delete(no);
	cout << endl << endl;
	cout << setw(57) << "删除学生成功!" << endl;
	cout << setw(59) << "学生账户注销成功!" << endl;
}

void DelSomeStu(StudentList & gloStuList, AccountList & gloAcntList, CourseList &gloCouList)
{
	string cla;
	cout << endl;
	cout << setw(50) << "请输入班级：";
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	sort(pos.begin(), pos.end());
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "未找到满足条件的学生！" << endl;
		return;
	}
	Student* s;
	for (int i = pos.size()-1; i >=0; i--) {
		s = gloStuList.SearchWithPos(pos[i]);
		vector<string> selected = s->getCnoList();
		for (int i = 0; i < selected.size(); i++)
			gloCouList.Minus(selected[i]);
		gloAcntList.Delete(s->getNo());
		gloStuList.Delete(pos[i]);
	}
	cout << endl << endl;
	cout << setw(57) << "删除学生成功!" << endl;
	cout << setw(59) << "学生账户注销成功!" << endl;
}

void UpdateStuInfo(StudentList & gloStuList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "请输入学生学号：";
	cin >> no;
	gloStuList.UpdateStuInfo(no);
	cout << "\n\n";
	cout << setw(58) << "学生信息更新成功!" << endl;
}

void SearchWithSNo(StudentList & gloStuList)
{
	cout << endl;
	cout << setw(50) << "请输入学号：";
	string no;
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "学生信息不存在！" << endl;
		return;
	}
	Student* s = gloStuList.SearchWithPos(pos);
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             学号       姓名       性别      年龄    系别       班级      联系方式" << endl;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	s->printStuInfo();
	cout << "          ---------------------------------------------------------------------------------" << endl;
}

void SearchWithDept(StudentList & gloStuList)
{
	cout << endl;
	cout << setw(50) << "请输入系别：";
	string dept;
	cin >> dept;
	vector<int> pos;
	gloStuList.SearchWithDept(dept, pos);
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "未找到满足条件的学生！" << endl;
		return;
	}
	Student* s;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             学号       姓名       性别      年龄    系别       班级      联系方式" << endl;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < pos.size(); i++) {
		s = gloStuList.SearchWithPos(pos[i]);
		s->printStuInfo();
		cout << "          ---------------------------------------------------------------------------------" << endl;
	}
}

void SearchWithCla(StudentList & gloStuList)
{
	cout << endl;
	cout << setw(50) << "请输入班级：";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "未找到满足条件的学生！" << endl;
		return;
	}
	Student* s;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             学号       姓名       性别      年龄    系别       班级      联系方式" << endl;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < pos.size(); i++) {
		s = gloStuList.SearchWithPos(pos[i]);
		s->printStuInfo();
		cout << "          ---------------------------------------------------------------------------------" << endl;
	}
}

void AddCouInfo(CourseList & gloCouList)
{
	string no, name, type, timeCode;
	int period, credit, term, num, maxNum;
	int day, begint, endt;
	cout << endl;
	cout << setw(49) << "请输入课程信息:" << endl; 
	cout << endl;
	cout << setw(50) << "课程代码：";
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos != -1) {
		cout << "\n";
		cout << setw(58) << "课程信息已存在！" << endl;
		return;
	}
	cout << setw(50) << "课程名称：";
	cin >> name;
	cout << setw(50) << "课程性质：";
	cin >> type;
	cout << setw(50) << "总学时：";
	cin >> period;
	if (cin.good() != 1 || period <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(56) << "请输入正整数!" << endl;
		return;
	}
	cout << setw(50) << "学分：";
	cin >> credit;
	if (cin.good() != 1 || credit <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(56) << "请输入正整数!" << endl;
		return;
	}
	cout << setw(50) << "开课学期：";
	cin >> term;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(55) << "请输入整数!" << endl;
		return;
	}
	if (term <= 0 || term > 8)
	{
		cout << endl;
		cout << setw(55) << "输入非法!" << endl;
		return;
	}
	cout << setw(50) << "限选人数：";
	cin >> maxNum;
	if (cin.good() != 1 || maxNum <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(55) << "请输入正整数!" << endl;
		return;
	}
	cout << setw(50) << "上课时间(1-5)[示例:1表示周一开课]：";
	cin >> day;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << endl;
		cout << setw(55) << "请输入整数!" << endl;
		return;
	}
	switch (day)
	{
	case 1:
		timeCode = "000";
		break;
	case 2:
		timeCode = "001";
		break;
	case 3:
		timeCode = "010";
		break;
	case 4:
		timeCode = "011";
		break;
	case 5:
		timeCode = "100";
		break;
	default:
		cout << endl;
		cout << setw(56) << "上课时间非法!" << endl;
		return;
	}
	cout << setw(50) << "节次(1-12)[示例:3 5表示上课时间为3-5节]：";
	cin >> begint;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << setw(55) << "请输入整数!" << endl;
		return;
	}
	cin >> endt;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << setw(55) << "请输入整数!" << endl;
		return;
	}
	timeCode += "000000000000";
	if(begint>=1&&endt>=begint&&endt<=12)
		for (int i = begint; i <= endt; i++)
			timeCode[i+2] = '1';
	else
	{
		cout << endl;
		cout << setw(55) << "节次非法!" << endl;
		return;
	}
	Course tempCou = *(new Course(no, name, type, period, credit, term, 0, maxNum, timeCode));
	gloCouList.Insert(tempCou);
	cout << endl << endl;
	cout << setw(57) << "添加课程成功！" << endl;
}

void MergeCouInfo(CourseList & gloCouList)
{
	string filePos;
	cout << "\n";
	cout << setw(50) << "请输入文件地址：";
	cin >> filePos;
	CourseList exCouList(filePos);
	gloCouList.Merge(exCouList);
	ifstream in(filePos);
	if (!in)
		return;
	else
	{
		cout << endl << endl;
		cout << setw(57) << "添加课程成功！" << endl;
	}
}

void DelCouInfo(CourseList & gloCouList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "课程信息不存在！" << endl;
		return;
	}
	gloCouList.Delete(pos);
	cout << "\n\n";
	cout << setw(57) << "删除课程成功！" << endl;
}

void UpdateCouInfo(CourseList & gloCouList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> no;
	gloCouList.UpdateCouInfo(no);
	cout << "\n\n";
	cout << setw(58) << "课程信息更新成功!" << endl;
}

void SearchWithCNo(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "请输入课程代码：";
	string no;
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "课程信息不存在！" << endl;
		return;
	}
	Course* c = gloCouList.SearchWithPos(pos);
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	c->printCouInfo();
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
}

void SearchWithCName(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "请输入课程名称：";
	string name;
	cin >> name;
	int pos = gloCouList.SearchWithName(name);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "课程信息不存在！" << endl;
		return;
	}
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	Course* c = gloCouList.SearchWithPos(pos);
	c->printCouInfo();
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
}

void SearchWithTerm(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "请输入开课学期：";
	int term;
	cin >> term;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << endl;
		cout << setw(55) << "请输入整数!" << endl;
		return;
	}
	vector<int> pos;
	gloCouList.SearchWithTerm(term, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "未找到满足条件的课程！" << endl;
		return;
	}
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	Course* c;
	for (int i = 0; i < pos.size(); i++) {
		c = gloCouList.SearchWithPos(pos[i]);
		c->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
}
	
void AddAcntInfo(AccountList & gloAcntList)
{
	string no;
	cout << "\n";
	cout << setw(52) << "请输入管理员工号：";
	cin >> no;
	int pos = gloAcntList.Search(no);
	if (pos != -1)
	{
		cout << "\n";
		cout << setw(58) << "该账户已被注册!" << endl;
		return;
	}
	gloAcntList.Insert(no,1);
	cout << "\n";
	cout << setw(60) << "管理员账户注册成功！" << endl;
}

void DelAcntList(AccountList & gloAcntList)
{
	string no;
	cout << "\n";
	cout << setw(52) << "请输入管理员工号：";
	cin >> no;
	int pos = gloAcntList.Search(no);
	if (pos == -1)
	{
		cout << "\n";
		cout << setw(62) << "该账户不存在或已被注销!" << endl;
		return;
	}
	gloAcntList.Delete(no);
	cout << "\n";
	cout << setw(60) << "管理员账户注销成功！" << endl;
}

void ResetAcntPassword(string Ano, AccountList & gloAcntList)
{
	string origin, newp1, newp2;
	cout << "\n\n";
	cout << setw(50) << "请输入原密码:" << endl;
	cout << setw(47) << " ";
	origin = InputPassword();
	cout << "\n\n";
	cout << setw(50) << "请输入新密码:" << endl;
	cout << setw(47) << " ";
	newp1 = InputPassword();
	cout << "\n\n";
	cout << setw(54) << "请再次输入新密码:" << endl;
	cout << setw(47) << " ";
	newp2 = InputPassword();
	gloAcntList.ResetPassword(Ano, origin, newp1, newp2);
}

string InputPassword()
{
	char c;
	string password;
	do {
		c = _getch();
		//int flag = _getch();  VS2017补充
		if (c == '\b')
		{
			password.pop_back();
			cout << '\b';
			cout << ' ';
			cout << '\b';
		}
		else if (c == '\r')
			break;
		else
		{
			password.push_back(c);
			cout << '*';
		}
	} while (1);
	return password;
}

void AdminSelectCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	string sno;
	string cno;
	cout << "\n";
	cout << setw(50) << "请输入学生学号：";
	cin >> sno;
	int spos = gloStuList.SearchWithNo(sno);
	if (spos == -1) {
		cout << "\n";
		cout << setw(58) << "学生信息不存在!" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(spos);
	vector<int> course = ShowCanSelect(sInfo, gloCouList);
	if (course.size() == 0) {
		cout << "\n";
		cout << setw(58) << "该生无可选课程!" << endl;
		return;
	}
	cout << "\n";
	cout << "      该生可选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->SelectCourse(cno);
		Course*c = gloCouList.SearchWithPos(cpos);
		c->plus();
		sInfo->updateCouTime(c->getTimeCode());
		cout << endl;
		cout << setw(55) << "选课成功!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于该生的可选课程!" << endl;
		return;
	}
}

vector<int> ShowCanSelect(Student* sInfo, CourseList& gloCouList)
{
	vector<int> course;
	vector<int> selected;
	vector<string> selectedNo = sInfo->getCnoList();
	for (int i = 0; i < selectedNo.size(); i++) {
		int tempPos = gloCouList.SearchWithNo(selectedNo[i]);
		selected.push_back(tempPos);
	}
	sort(selected.begin(), selected.end());
	int k = 0;
	for (int i = 0; i < gloCouList.GetListLength(); i++) {
		if (k < selected.size() && i == selected[k]) {
			k++;
		}
		else {
			course.push_back(i);
		}
	}
	vector<int> canSelect;
	Course* c;
	for (int i = 0; i < course.size(); i++) {
		c = gloCouList.SearchWithPos(course[i]);
		if (c->canSelect() && !(sInfo->IsTimeConflict(c->getTimeCode()))) {
			canSelect.push_back(course[i]);
		}
	}
	return canSelect;
}

void AdminSelectSomeCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	cout << "\n";
	cout << setw(50) << "请输入班级：";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "未找到满足条件的学生！" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(pos[0]);
	vector<int> course = ShowCanSelect(sInfo, gloCouList);
	if (course.size() == 0) {
		cout << endl;
		cout << setw(58) << "该班无可选课程!" << endl;
		return;
	}
	cout << endl;
	cout << "      该班的可选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	string cno;
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->SelectCourse(cno);
		Course*c = gloCouList.SearchWithPos(cpos);
		c->plus();
		sInfo->updateCouTime(c->getTimeCode());
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于该班的可选课程!" << endl;
		return;
	}
	for (int i = 1; i < pos.size(); i++)
	{
		Student* sInfo = gloStuList.SearchWithPos(pos[i]);
		sInfo->SelectCourse(cno);
		Course*c = gloCouList.SearchWithPos(cpos);
		c->plus();
		sInfo->updateCouTime(c->getTimeCode());
	}
	cout << endl;
	cout << setw(55) << "选课成功!" << endl;
}

void AdminDropCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	string sno;
	string cno;
	cout << "\n";
	cout << setw(50) << "请输入学生学号：";
	cin >> sno;
	int spos = gloStuList.SearchWithNo(sno);
	if (spos == -1) {
		cout << "\n";
		cout << setw(58) << "学生信息不存在!" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(spos);
	vector<string> selectedNo = sInfo->getCnoList();
	vector<int> course;
	for (int i = 0; i < selectedNo.size(); i++) {
		int tempPos = gloCouList.SearchWithNo(selectedNo[i]);
		course.push_back(tempPos);
	}
	if (course.size() == 0) {
		cout << "\n";
		cout << setw(58) << "该生无选课记录!" << endl;
		return;
	}
	cout << "\n";
	cout << setw(50) << "      该生已选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->DropCourse(cno);
		Course* c = gloCouList.SearchWithPos(cpos);
		sInfo->MinusCouTime(c->getTimeCode());
		c->minus();
		cout << endl;
		cout << setw(55) << "退选成功!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于该生的已选课程!" << endl;
		return;
	}
}

void AdminDropSomeCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	cout << "\n";
	cout << setw(50) << "请输入班级：";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "未找到满足条件的学生！" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(pos[0]);
	vector<string> selectedNo = sInfo->getCnoList();
	vector<int> course;
	for (int i = 0; i < selectedNo.size(); i++) {
		int tempPos = gloCouList.SearchWithNo(selectedNo[i]);
		course.push_back(tempPos);
	}
	if (course.size() == 0) {
		cout << endl;
		cout << setw(58) << "该班无选课记录!" << endl;
		return;
	}
	cout << endl;
	cout << "      该班的已选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	string cno;
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->DropCourse(cno);
		Course* c = gloCouList.SearchWithPos(cpos);
		sInfo->MinusCouTime(c->getTimeCode());
		c->minus();
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于该班的已选课程!" << endl;
		return;
	}
	for (int i = 1; i < pos.size(); i++)
	{
		Student* sInfo = gloStuList.SearchWithPos(pos[i]);
		sInfo->DropCourse(cno);
		Course* c = gloCouList.SearchWithPos(cpos);
		sInfo->MinusCouTime(c->getTimeCode());
		c->minus();
	}
	cout << endl;
	cout << setw(55) << "退选成功!" << endl;
}

void ShowSelected(string sno, StudentList & gloStuList, CourseList & gloCouList)
{
	int pos = gloStuList.SearchWithNo(sno);
	Student* s = gloStuList.SearchWithPos(pos);
	vector<string> selectedNo = s->getCnoList();
	vector<int> selected;
	for (int i = 0; i < selectedNo.size(); i++) {
		int tempPos = gloCouList.SearchWithNo(selectedNo[i]);
		selected.push_back(tempPos);
	}
	if (selected.size() == 0) {
		cout << endl;
		cout << setw(55) << "无选课记录" << endl;
		return;
	}
	cout << "    您的已选课程为：" << endl << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < selected.size(); i++) {
		gloCouList.SearchWithPos(selected[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
}

void StuSelectCourse(string sno, StudentList & gloStuList, CourseList & gloCouList)
{
	string cno;
	int spos = gloStuList.SearchWithNo(sno);
	Student* sInfo = gloStuList.SearchWithPos(spos);
	vector<int> course = ShowCanSelect(sInfo, gloCouList);
	if (course.size() == 0) {
		cout << endl;
		cout << setw(55) << "无可选课程!" << endl;
		return;
	}
	cout << endl;
	cout << "      您的可选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->SelectCourse(cno);
		Course*c = gloCouList.SearchWithPos(cpos);
		c->plus();
		sInfo->updateCouTime(c->getTimeCode());
		cout << endl;
		cout << setw(55) << "选课成功!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于您的可选课程!" << endl;
		return;
	}
}

void StuDropCourse(string sno, StudentList & gloStuList, CourseList & gloCouList)
{
	string cno;
	int spos = gloStuList.SearchWithNo(sno);
	Student* sInfo = gloStuList.SearchWithPos(spos);
	vector<string> selectedNo = sInfo->getCnoList();
	vector<int> course;
	for (int i = 0; i < selectedNo.size(); i++) {
		int tempPos = gloCouList.SearchWithNo(selectedNo[i]);
		course.push_back(tempPos);
	}
	if (course.size() == 0) {
		cout << endl;
		cout << setw(55) << "无选课记录!" << endl;
		return;
	}
	cout << endl;
	cout << "      您的已选课程为：" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   课程代码        课程名称       课程类型    总学时     学分    开课学期  已选人数  限选人数" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "请输入课程代码：";
	cin >> cno;
	int cpos = gloCouList.SearchWithNo(cno);
	int i = 0;
	for (; i < course.size(); i++)
		if (cpos == course[i])
			break;
	if (i < course.size())
	{
		sInfo->DropCourse(cno);
		Course* c = gloCouList.SearchWithPos(cpos);
		sInfo->MinusCouTime(c->getTimeCode());
		c->minus();
		cout << endl;
		cout << setw(55) << "退选成功!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "课程代码非法!不属于您的已选课程!" << endl;
		return;
	}
}