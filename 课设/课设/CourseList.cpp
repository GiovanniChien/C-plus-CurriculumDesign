#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <sstream>
#include <fstream>
#include <iomanip>
#include "CourseList.h"
using namespace std;

CourseList::CourseList(vector<Course> mCouList)
{
	couList = mCouList;
}

CourseList::CourseList(string filePos)
{
	Course tempCou;
	string str;
	string no, name, type;
	int period, credit, term, num, maxNum;
	string timeCode;
	vector<string> temp;
	temp.resize(10);
	ifstream in(filePos);
	if (!in) {
		cout << endl;
		cout << setw(56) << "�޷���ȡ����!" << endl;
	}
	else
	{
		while (getline(in, str)) {
			istringstream sin(str);
			int i = 0;
			while (sin >> temp[i]) {
				i++;
			}
			no = temp[0], name = temp[1], type = temp[2];
			period = atoi(temp[3].c_str()), credit = atoi(temp[4].c_str()), term = atoi(temp[5].c_str()), num = atoi(temp[6].c_str());
			maxNum = atoi(temp[7].c_str()), timeCode = temp[8];
			tempCou = *(new Course(no, name, type, period, credit, term, num, maxNum, timeCode));
			couList.push_back(tempCou);
		}
	}
}

int CourseList::GetListLength()
{
	return couList.size();
}

Course* CourseList::SearchWithPos(int pos)
{
	if (pos < 0 || pos >= couList.size())
		return NULL;
	return &(couList[pos]);
}

int CourseList::SearchWithNo(string Cno)
{
	for (int i = 0; i < couList.size(); i++)
		if (couList[i].getNo() == Cno)
			return i;
	return -1;
}

int CourseList::SearchWithName(string Cname)
{
	for (int i = 0; i < couList.size(); i++)
		if (couList[i].getName() == Cname)
			return i;
	return -1;
}

void CourseList::SearchWithTerm(int Cterm, vector<int>& pos)
{
	for (int i = 0; i < couList.size(); i++)
		if (couList[i].getTerm() == Cterm)
			pos.push_back(i);
}

void CourseList::UpdateCouInfo(string no)
{
	int pos = SearchWithNo(no);
	if (pos == -1)
	{
		cout << "\n";
		cout << setw(58) << "δ�ҵ��γ̼�¼!" << endl;
	}
	else
	{
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
		cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
		couList[pos].printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
		string name, type;
		int period, credit, term, num, maxNum;
		int day, begint, endt;
		string timeCode;
		cout << "\n\n";
		cout << setw(49) << "����¿γ���Ϣ:" << endl;
		cout << "\n";
		cout << setw(50) << "�γ����ƣ�";
		cin >> name;
		cout << setw(50) << "�γ����ʣ�";
		cin >> type;
		cout << setw(50) << "��ѧʱ��";
		cin >> period;
		if (cin.good() != 1 || period<=0) {
			cin.clear();
			cin.ignore(1024,'\n');
			cout << endl;
			cout << setw(56) << "������������!" << endl;
			return;
		}
		cout << setw(50) << "ѧ�֣�";
		cin >> credit;
		if (cin.good() != 1 || credit<=0) {
			cin.clear();
			cin.ignore(1024,'\n');
			cout << endl;
			cout << setw(56) << "������������!" << endl;
			return;
		}
		cout << setw(50) << "����ѧ��(1-8)��";
		cin >> term;
		if (cin.good() != 1) {
			cin.clear();
			cin.ignore(1024,'\n');
			cout << endl;
			cout << setw(56) << "����������!" << endl;
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
		if (cin.good() != 1||maxNum<=0) {
			cin.clear();
			cin.ignore(1024,'\n');
			cout << endl;
			cout << setw(55) << "������������!" << endl;
			return;
		}
		cout << setw(50) << "�Ͽ�ʱ��(1-5)[ʾ��:1��ʾ��һ����]��";
		cin >> day;
		if (cin.good() != 1) {
			cin.clear();
			cin.ignore(1024, '\n');
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
			cin.ignore(1024, '\n');
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
		if (begint >= 1 && endt >= begint&&endt <= 12)
			for (int i = begint; i <= endt; i++)
				timeCode[i + 2] = '1';
		else
		{
			cout << endl;
			cout << setw(54) << "�ڴηǷ�!" << endl;
			return;
		}
		Course tempCou = *(new Course(no, name, type, period, credit, term, 0, maxNum, timeCode));
		couList[pos] = tempCou;
	}
}

void CourseList::Insert(int pos, Course c)
{
	couList.insert(couList.begin() + pos, c);
}

void CourseList::Insert(Course c)
{
	couList.insert(couList.end(), c);
	Sort();
}

void CourseList::Merge(CourseList cList)
{
	for (int i = 0; i < cList.GetListLength(); i++) {
		int pos = SearchWithNo(cList.couList[i].getNo());
		if (pos == -1)
			Insert(cList.couList[i]);
	}
}

void CourseList::Delete(int pos)
{
	couList.erase(couList.begin() + pos);
}

void CourseList::Delete(vector<int> pos)
{
	vector<Course> temp;
	temp.resize(couList.size() - pos.size());
	int j = 0, k = 0;
	for (int i = 0; i < couList.size(); i++)
		if (k < pos.size() && i == pos[k])
			k++;
		else
			temp[j++] = couList[i];
	couList = temp;
}

void CourseList::Sort()
{
	sort(couList.begin(), couList.end());
}

void CourseList::PrintCouList()
{
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	cout << "   �γ̴���        �γ�����       �γ�����    ��ѧʱ     ѧ��    ����ѧ��  ��ѡ����  ��ѡ����" << endl;
	cout << "  ---------------------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < couList.size(); i++)
	{
		couList[i].printCouInfo();
		cout << "  ---------------------------------------------------------------------------------------------" << endl;
	}
}

void CourseList::Save(string filePos)
{
	ofstream out;
	out.open(filePos);
	if (!out) {
		cout << endl;
		cout << setw(56) << "�޷��洢����" << endl;
	}
	else {
		for (int i = 0; i < couList.size(); i++) {
			out << couList[i].getNo() << ' ' << couList[i].getName() << ' ';
			out << couList[i].getType() << ' ' << couList[i].getPeriod() << ' ';
			out << couList[i].getCredit() << ' ' << couList[i].getTerm() << ' ';
			out << couList[i].getNum() << ' ' << couList[i].getMaxNum() << ' ';
			out << couList[i].getTimeCode() << endl;
		}
	}
}

void CourseList::Minus(string cno)
{
	int pos = SearchWithNo(cno);
	couList[pos].minus();
}
