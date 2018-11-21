#pragma once
#include <iostream>
#include <vector>
#include "Course.h"
using namespace std;

class CourseList {
private:
	vector<Course> couList;
public:
	CourseList() {
		couList.resize(0);
	}//无参构造函数
	CourseList(vector<Course> mCouList);//有参构造函数
	CourseList(string filePos);//从课程信息表中读取数据
	int GetListLength();//获取链表长度
	Course* SearchWithPos(int pos);//按位查找
	int SearchWithNo(string Cno);//按课程代码查找
	int SearchWithName(string Cname);//按课程名称查找
	void SearchWithTerm(int Cterm, vector<int>& pos);//按开课学期查找
	void UpdateCouInfo(string no);//更新课程信息
	void Insert(int pos, Course c);//插入课程信息
	void Insert(Course c);
	void Merge(CourseList cList);//插入课程信息
	void Delete(int pos);//删除课程信息
	void Delete(vector<int> pos);//批量删除课程信息
	void Sort();//排序
	void PrintCouList();//输出所有学生信息
	void Save(string filePos);//保存课程信息
	void Minus(string cno);
};