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
	cout << setw(49) << "������ѧ����Ϣ:" << endl;
	cout << "\n";
	cout << setw(50) << "ѧ�ţ�";
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos != -1) {
		cout << "\n";
		cout << setw(58) << "ѧ����Ϣ�Ѵ���!" << endl;
		Sleep(2000);
		return;
	}
	cout << setw(50) << "������";
	cin >> name;
	cout << setw(50) << "�Ա�";
	cin >> sex;
	if (sex != "��"&&sex != "Ů")
	{
		cout << endl;
		cout << setw(56) << "��������/Ů!" << endl;
		return;
	}
	cout << setw(50) << "���䣺";
	cin >> age;
	if (atoi(age.c_str()) <= 0 || atoi(age.c_str()) >= 100)
	{
		cout << endl;
		cout << setw(55) << "����Ƿ�!" << endl;
		return;
	}
	cout << setw(50) << "ϵ��";
	cin >> dept;
	cout << setw(50) << "�༶��";
	cin >> cla;
	cout << setw(54) << "��ϵ��ʽ��";
	cin >> tel;
	if (tel.size() != 11)
	{
		cout << endl;
		cout << setw(55) << "����Ƿ�!" << endl;
		return;
	}
	for (int i = 0; i<11; i++)
		if (tel[i]<'0' || tel[i]>'9')
		{
			cout << endl;
			cout << setw(55) << "����Ƿ�!" << endl;
			return;
		}
	Student tempStu = *(new Student(no, name, sex, age, dept, cla, tel));
	gloStuList.Insert(tempStu);
	gloAcntList.Insert(no,0);
	cout << endl << endl;
	cout << setw(57) << "���ѧ���ɹ�!" << endl;
	cout << setw(59) << "ѧ���˻�ע��ɹ�!" << endl;
}

void MergeStuInfo(StudentList & gloStuList, AccountList& gloAcntList)
{
	string filePos;
	cout << "\n";
	cout << setw(50) << "�������ļ���ַ��";
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
		cout << setw(57) << "���ѧ���ɹ�!" << endl;
		cout << setw(59) << "ѧ���˻�ע��ɹ�!" << endl;
	}
}

void DelStuInfo(StudentList & gloStuList, AccountList& gloAcntList, CourseList &gloCouList)
{
	string no;
	cout << endl;
	cout << setw(50) << "������ѧ�ţ�";
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "ѧ����Ϣ������!" << endl;
		return;
	}
	Student* s = gloStuList.SearchWithPos(pos);
	vector<string> selected = s->getCnoList();
	for (int i = 0; i < selected.size(); i++)
		gloCouList.Minus(selected[i]);
	gloStuList.Delete(pos);
	gloAcntList.Delete(no);
	cout << endl << endl;
	cout << setw(57) << "ɾ��ѧ���ɹ�!" << endl;
	cout << setw(59) << "ѧ���˻�ע���ɹ�!" << endl;
}

void DelSomeStu(StudentList & gloStuList, AccountList & gloAcntList, CourseList &gloCouList)
{
	string cla;
	cout << endl;
	cout << setw(50) << "������༶��";
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	sort(pos.begin(), pos.end());
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "δ�ҵ�����������ѧ����" << endl;
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
	cout << setw(57) << "ɾ��ѧ���ɹ�!" << endl;
	cout << setw(59) << "ѧ���˻�ע���ɹ�!" << endl;
}

void UpdateStuInfo(StudentList & gloStuList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "������ѧ��ѧ�ţ�";
	cin >> no;
	gloStuList.UpdateStuInfo(no);
	cout << "\n\n";
	cout << setw(58) << "ѧ����Ϣ���³ɹ�!" << endl;
}

void SearchWithSNo(StudentList & gloStuList)
{
	cout << endl;
	cout << setw(50) << "������ѧ�ţ�";
	string no;
	cin >> no;
	int pos = gloStuList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "ѧ����Ϣ�����ڣ�" << endl;
		return;
	}
	Student* s = gloStuList.SearchWithPos(pos);
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             ѧ��       ����       �Ա�      ����    ϵ��       �༶      ��ϵ��ʽ" << endl;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	s->printStuInfo();
	cout << "          ---------------------------------------------------------------------------------" << endl;
}

void SearchWithDept(StudentList & gloStuList)
{
	cout << endl;
	cout << setw(50) << "������ϵ��";
	string dept;
	cin >> dept;
	vector<int> pos;
	gloStuList.SearchWithDept(dept, pos);
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "δ�ҵ�����������ѧ����" << endl;
		return;
	}
	Student* s;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             ѧ��       ����       �Ա�      ����    ϵ��       �༶      ��ϵ��ʽ" << endl;
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
	cout << setw(50) << "������༶��";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << endl;
		cout << setw(60) << "δ�ҵ�����������ѧ����" << endl;
		return;
	}
	Student* s;
	cout << "          ---------------------------------------------------------------------------------" << endl;
	cout << "             ѧ��       ����       �Ա�      ����    ϵ��       �༶      ��ϵ��ʽ" << endl;
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
	cout << setw(49) << "������γ���Ϣ:" << endl; 
	cout << endl;
	cout << setw(50) << "�γ̴��룺";
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos != -1) {
		cout << "\n";
		cout << setw(58) << "�γ���Ϣ�Ѵ��ڣ�" << endl;
		return;
	}
	cout << setw(50) << "�γ����ƣ�";
	cin >> name;
	cout << setw(50) << "�γ����ʣ�";
	cin >> type;
	cout << setw(50) << "��ѧʱ��";
	cin >> period;
	if (cin.good() != 1 || period <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(56) << "������������!" << endl;
		return;
	}
	cout << setw(50) << "ѧ�֣�";
	cin >> credit;
	if (cin.good() != 1 || credit <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(56) << "������������!" << endl;
		return;
	}
	cout << setw(50) << "����ѧ�ڣ�";
	cin >> term;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(55) << "����������!" << endl;
		return;
	}
	if (term <= 0 || term > 8)
	{
		cout << endl;
		cout << setw(55) << "����Ƿ�!" << endl;
		return;
	}
	cout << setw(50) << "��ѡ������";
	cin >> maxNum;
	if (cin.good() != 1 || maxNum <= 0) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << endl;
		cout << setw(55) << "������������!" << endl;
		return;
	}
	cout << setw(50) << "�Ͽ�ʱ��(1-5)[ʾ��:1��ʾ��һ����]��";
	cin >> day;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << endl;
		cout << setw(55) << "����������!" << endl;
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
		cout << setw(56) << "�Ͽ�ʱ��Ƿ�!" << endl;
		return;
	}
	cout << setw(50) << "�ڴ�(1-12)[ʾ��:3 5��ʾ�Ͽ�ʱ��Ϊ3-5��]��";
	cin >> begint;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << setw(55) << "����������!" << endl;
		return;
	}
	cin >> endt;
	if (cin.good() != 1) {
		cin.clear();
		cin.ignore(1024, '\n');
		cout << setw(55) << "����������!" << endl;
		return;
	}
	timeCode += "000000000000";
	if(begint>=1&&endt>=begint&&endt<=12)
		for (int i = begint; i <= endt; i++)
			timeCode[i+2] = '1';
	else
	{
		cout << endl;
		cout << setw(55) << "�ڴηǷ�!" << endl;
		return;
	}
	Course tempCou = *(new Course(no, name, type, period, credit, term, 0, maxNum, timeCode));
	gloCouList.Insert(tempCou);
	cout << endl << endl;
	cout << setw(57) << "��ӿγ̳ɹ���" << endl;
}

void MergeCouInfo(CourseList & gloCouList)
{
	string filePos;
	cout << "\n";
	cout << setw(50) << "�������ļ���ַ��";
	cin >> filePos;
	CourseList exCouList(filePos);
	gloCouList.Merge(exCouList);
	ifstream in(filePos);
	if (!in)
		return;
	else
	{
		cout << endl << endl;
		cout << setw(57) << "��ӿγ̳ɹ���" << endl;
	}
}

void DelCouInfo(CourseList & gloCouList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "�γ���Ϣ�����ڣ�" << endl;
		return;
	}
	gloCouList.Delete(pos);
	cout << "\n\n";
	cout << setw(57) << "ɾ���γ̳ɹ���" << endl;
}

void UpdateCouInfo(CourseList & gloCouList)
{
	string no;
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
	cin >> no;
	gloCouList.UpdateCouInfo(no);
	cout << "\n\n";
	cout << setw(58) << "�γ���Ϣ���³ɹ�!" << endl;
}

void SearchWithCNo(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "������γ̴��룺";
	string no;
	cin >> no;
	int pos = gloCouList.SearchWithNo(no);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "�γ���Ϣ�����ڣ�" << endl;
		return;
	}
	Course* c = gloCouList.SearchWithPos(pos);
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	c->printCouInfo();
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
}

void SearchWithCName(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "������γ����ƣ�";
	string name;
	cin >> name;
	int pos = gloCouList.SearchWithName(name);
	if (pos == -1) {
		cout << "\n";
		cout << setw(58) << "�γ���Ϣ�����ڣ�" << endl;
		return;
	}
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	Course* c = gloCouList.SearchWithPos(pos);
	c->printCouInfo();
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
}

void SearchWithTerm(CourseList & gloCouList)
{
	cout << endl;
	cout << setw(50) << "�����뿪��ѧ�ڣ�";
	int term;
	cin >> term;
	if (cin.fail()) {
		cin.clear();
		cin.ignore(1024,'\n');
		cout << endl;
		cout << setw(55) << "����������!" << endl;
		return;
	}
	vector<int> pos;
	gloCouList.SearchWithTerm(term, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "δ�ҵ����������Ŀγ̣�" << endl;
		return;
	}
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
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
	cout << setw(52) << "���������Ա���ţ�";
	cin >> no;
	int pos = gloAcntList.Search(no);
	if (pos != -1)
	{
		cout << "\n";
		cout << setw(58) << "���˻��ѱ�ע��!" << endl;
		return;
	}
	gloAcntList.Insert(no,1);
	cout << "\n";
	cout << setw(60) << "����Ա�˻�ע��ɹ���" << endl;
}

void DelAcntList(AccountList & gloAcntList)
{
	string no;
	cout << "\n";
	cout << setw(52) << "���������Ա���ţ�";
	cin >> no;
	int pos = gloAcntList.Search(no);
	if (pos == -1)
	{
		cout << "\n";
		cout << setw(62) << "���˻������ڻ��ѱ�ע��!" << endl;
		return;
	}
	gloAcntList.Delete(no);
	cout << "\n";
	cout << setw(60) << "����Ա�˻�ע���ɹ���" << endl;
}

void ResetAcntPassword(string Ano, AccountList & gloAcntList)
{
	string origin, newp1, newp2;
	cout << "\n\n";
	cout << setw(50) << "������ԭ����:" << endl;
	cout << setw(47) << " ";
	origin = InputPassword();
	cout << "\n\n";
	cout << setw(50) << "������������:" << endl;
	cout << setw(47) << " ";
	newp1 = InputPassword();
	cout << "\n\n";
	cout << setw(54) << "���ٴ�����������:" << endl;
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
		//int flag = _getch();  VS2017����
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
	cout << setw(50) << "������ѧ��ѧ�ţ�";
	cin >> sno;
	int spos = gloStuList.SearchWithNo(sno);
	if (spos == -1) {
		cout << "\n";
		cout << setw(58) << "ѧ����Ϣ������!" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(spos);
	vector<int> course = ShowCanSelect(sInfo, gloCouList);
	if (course.size() == 0) {
		cout << "\n";
		cout << setw(58) << "�����޿�ѡ�γ�!" << endl;
		return;
	}
	cout << "\n";
	cout << "      ������ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(55) << "ѡ�γɹ�!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "�γ̴���Ƿ�!�����ڸ����Ŀ�ѡ�γ�!" << endl;
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
	cout << setw(50) << "������༶��";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "δ�ҵ�����������ѧ����" << endl;
		return;
	}
	Student* sInfo = gloStuList.SearchWithPos(pos[0]);
	vector<int> course = ShowCanSelect(sInfo, gloCouList);
	if (course.size() == 0) {
		cout << endl;
		cout << setw(58) << "�ð��޿�ѡ�γ�!" << endl;
		return;
	}
	cout << endl;
	cout << "      �ð�Ŀ�ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(68) << "�γ̴���Ƿ�!�����ڸð�Ŀ�ѡ�γ�!" << endl;
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
	cout << setw(55) << "ѡ�γɹ�!" << endl;
}

void AdminDropCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	string sno;
	string cno;
	cout << "\n";
	cout << setw(50) << "������ѧ��ѧ�ţ�";
	cin >> sno;
	int spos = gloStuList.SearchWithNo(sno);
	if (spos == -1) {
		cout << "\n";
		cout << setw(58) << "ѧ����Ϣ������!" << endl;
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
		cout << setw(58) << "������ѡ�μ�¼!" << endl;
		return;
	}
	cout << "\n";
	cout << setw(50) << "      ������ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(55) << "��ѡ�ɹ�!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "�γ̴���Ƿ�!�����ڸ�������ѡ�γ�!" << endl;
		return;
	}
}

void AdminDropSomeCourse(StudentList & gloStuList, CourseList & gloCouList)
{
	cout << "\n";
	cout << setw(50) << "������༶��";
	string cla;
	cin >> cla;
	vector<int> pos;
	gloStuList.SearchWithCla(cla, pos);
	if (pos.size() == 0) {
		cout << "\n";
		cout << setw(60) << "δ�ҵ�����������ѧ����" << endl;
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
		cout << setw(58) << "�ð���ѡ�μ�¼!" << endl;
		return;
	}
	cout << endl;
	cout << "      �ð����ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(68) << "�γ̴���Ƿ�!�����ڸð����ѡ�γ�!" << endl;
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
	cout << setw(55) << "��ѡ�ɹ�!" << endl;
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
		cout << setw(55) << "��ѡ�μ�¼" << endl;
		return;
	}
	cout << "    ������ѡ�γ�Ϊ��" << endl << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
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
		cout << setw(55) << "�޿�ѡ�γ�!" << endl;
		return;
	}
	cout << endl;
	cout << "      ���Ŀ�ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(55) << "ѡ�γɹ�!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "�γ̴���Ƿ�!���������Ŀ�ѡ�γ�!" << endl;
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
		cout << setw(55) << "��ѡ�μ�¼!" << endl;
		return;
	}
	cout << endl;
	cout << "      ������ѡ�γ�Ϊ��" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < course.size(); i++) {
		gloCouList.SearchWithPos(course[i])->printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
	cout << "\n";
	cout << setw(50) << "������γ̴��룺";
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
		cout << setw(55) << "��ѡ�ɹ�!" << endl;
	}
	else
	{
		cout << endl;
		cout << setw(68) << "�γ̴���Ƿ�!������������ѡ�γ�!" << endl;
		return;
	}
}