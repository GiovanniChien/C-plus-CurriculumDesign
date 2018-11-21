#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"student.h"

using namespace std;

class StudentList {
private:
	vector<Student> stuList;
public:
	StudentList() {
		stuList.resize(0);
	}//无参构造函数
	StudentList(vector<Student> mStuList);//有参构造函数
	StudentList(string filePos);//从学生信息表中读取数据，所有学生选课情况为空
	StudentList(string stuFile,string selCouFile);//分别从学生信息表和选课情况表中读取数据
//	~StudentList();//析构函数
	int GetListLength();//获取链表长度
	Student* SearchWithPos(int pos);//按位查找
	int SearchWithNo(string Sno);//按学号查找
	void SearchWithDept(string Sdept,vector<int>& pos);//按系别查找
	void SearchWithCla(string Scla,vector<int>& pos);//按班级查找
	void UpdateStuInfo(string no);//更新学生信息
	void Insert(int pos, Student s);//插入学生信息
	void Insert(Student s);
	void Merge(StudentList sList);//批量添加学生信息
	void Delete(int pos);//删除学生信息
	void Delete(vector<int> pos);//批量删除学生信息
	void Sort();//排序
	void PrintStuList();//输出所有学生信息
	void Save(string stuFile,string selCouFile);//将学生信息写入指定文件中
	void SetTimeCode(CourseList& gloCouList);
};