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
	}//�޲ι��캯��
	StudentList(vector<Student> mStuList);//�вι��캯��
	StudentList(string filePos);//��ѧ����Ϣ���ж�ȡ���ݣ�����ѧ��ѡ�����Ϊ��
	StudentList(string stuFile,string selCouFile);//�ֱ��ѧ����Ϣ���ѡ��������ж�ȡ����
//	~StudentList();//��������
	int GetListLength();//��ȡ������
	Student* SearchWithPos(int pos);//��λ����
	int SearchWithNo(string Sno);//��ѧ�Ų���
	void SearchWithDept(string Sdept,vector<int>& pos);//��ϵ�����
	void SearchWithCla(string Scla,vector<int>& pos);//���༶����
	void UpdateStuInfo(string no);//����ѧ����Ϣ
	void Insert(int pos, Student s);//����ѧ����Ϣ
	void Insert(Student s);
	void Merge(StudentList sList);//�������ѧ����Ϣ
	void Delete(int pos);//ɾ��ѧ����Ϣ
	void Delete(vector<int> pos);//����ɾ��ѧ����Ϣ
	void Sort();//����
	void PrintStuList();//�������ѧ����Ϣ
	void Save(string stuFile,string selCouFile);//��ѧ����Ϣд��ָ���ļ���
	void SetTimeCode(CourseList& gloCouList);
};