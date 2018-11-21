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
	}//�޲ι��캯��
	CourseList(vector<Course> mCouList);//�вι��캯��
	CourseList(string filePos);//�ӿγ���Ϣ���ж�ȡ����
	int GetListLength();//��ȡ������
	Course* SearchWithPos(int pos);//��λ����
	int SearchWithNo(string Cno);//���γ̴������
	int SearchWithName(string Cname);//���γ����Ʋ���
	void SearchWithTerm(int Cterm, vector<int>& pos);//������ѧ�ڲ���
	void UpdateCouInfo(string no);//���¿γ���Ϣ
	void Insert(int pos, Course c);//����γ���Ϣ
	void Insert(Course c);
	void Merge(CourseList cList);//����γ���Ϣ
	void Delete(int pos);//ɾ���γ���Ϣ
	void Delete(vector<int> pos);//����ɾ���γ���Ϣ
	void Sort();//����
	void PrintCouList();//�������ѧ����Ϣ
	void Save(string filePos);//����γ���Ϣ
	void Minus(string cno);
};