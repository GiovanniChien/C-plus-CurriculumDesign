#pragma once
#include<iostream>
#include<vector>
#include"studentList.h"
#include"AccountList.h"
#include"CourseList.h"

using namespace std;

//ѧ������
void AddStuInfo(StudentList& gloStuList, AccountList& gloAcntList);
void MergeStuInfo(StudentList& gloStuList, AccountList& gloAcntList);
void DelStuInfo(StudentList& gloStuList, AccountList& gloAcntList, CourseList &gloCouList);
void DelSomeStu(StudentList & gloStuList, AccountList & gloAcntList, CourseList &gloCouList);
void UpdateStuInfo(StudentList& gloStuList);
void SearchWithSNo(StudentList& gloStuList);
void SearchWithDept(StudentList& gloStuList);
void SearchWithCla(StudentList& gloStuList);

//�γ̹���
void AddCouInfo(CourseList& gloCouList);
void MergeCouInfo(CourseList& gloCouList);
void DelCouInfo(CourseList& gloCouList);
void UpdateCouInfo(CourseList& gloCouList);
void SearchWithCNo(CourseList& gloCouList);
void SearchWithCName(CourseList& gloCouList);
void SearchWithTerm(CourseList& gloCouList);

//�˻�����
void AddAcntInfo(AccountList& gloAcntList);
void DelAcntList(AccountList& gloAcntList);
void ResetAcntPassword(string Ano, AccountList& gloAcntList);
string InputPassword();

//Adminѡ��
void AdminSelectCourse(StudentList& gloStuList, CourseList& gloCouList);
vector<int> ShowCanSelect(Student* sInfo, CourseList& gloCouList);
void AdminSelectSomeCourse(StudentList& gloStuList, CourseList& gloCouList);
void AdminDropCourse(StudentList& gloStuList, CourseList& gloCouList);
void AdminDropSomeCourse(StudentList& gloStuList, CourseList& gloCouList);

//Stuѡ��
void ShowSelected(string sno, StudentList& gloStuList, CourseList& gloCouList);
void StuSelectCourse(string sno, StudentList& gloStuList, CourseList& gloCouList);
void StuDropCourse(string sno, StudentList& gloStuList, CourseList& gloCouList);