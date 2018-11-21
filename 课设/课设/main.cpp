#include<iostream>
#include"student.h"
#include"studentList.h"
#include"function.h"
#include<Windows.h>
#include"CourseList.h"
#include"AccountList.h"
#include"menu.h"
#include<string>
#include<vector>
#include<iomanip>
#include <conio.h>

using namespace std;

int main() {
	system("mode con cols=40 lines=20");
	system("color F0");
	StudentList gloStuList("StuInfo.txt", "SelectResult.txt");
	CourseList gloCouList("CousInfo.txt");
	AccountList gloAcntList("AcntList.txt");
	string no, password;
	do {
		system("cls");
		cout << "\n\n\n\n";
		cout << setw(22) << "��½" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << setw(18) << "�˺�:  ";
		cin >> no;
		//no = "100002";
		//no = "000002";
		cout << endl;
		cout << setw(18) << "����:  ";
		password = InputPassword();
		//password = "123456";
		if (gloAcntList.Login(no, password))
			break;
	} while (1);
	system("mode con cols=100 lines=30");
	if (gloAcntList.isAdmin(no))
	{
		int cmd, cmd1, cmd2;
		do {
			system("cls");
			menu();
			cin >> cmd;
			switch (cmd)
			{
			case 1:
				do {
					system("cls");
					menus();
					cin >> cmd1;
					switch (cmd1)
					{
					case 1:
						do {
							system("cls");
							menus1();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*���ѧ����Ϣ*/
								AddStuInfo(gloStuList, gloAcntList);
								Sleep(2000);
								break;
							case 2:
								/*�������ѧ����Ϣ*/
								MergeStuInfo(gloStuList, gloAcntList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 2:
						do {
							system("cls");
							menus2();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*ɾ��ѧ����Ϣ*/
								DelStuInfo(gloStuList, gloAcntList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*����ɾ��ѧ����Ϣ*/
								DelSomeStu(gloStuList, gloAcntList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 3:
						/*�޸�ѧ����Ϣ*/
						UpdateStuInfo(gloStuList);
						Sleep(2000);
						break;
					case 4:
						do {
							system("cls");
							menus4();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*��ѧ�Ų�ѯ*/
								SearchWithSNo(gloStuList);
								system("pause");
								break;
							case 2:
								/*��ϵ���ѯ*/
								SearchWithDept(gloStuList);
								system("pause");
								break;
							case 3:
								/*���༶��ѯ*/
								SearchWithCla(gloStuList);
								system("pause");
								break;
							case 4:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 4);
						break;
					case 5:
						/*��ʾ����ѧ����Ϣ*/
						gloStuList.PrintStuList();
						system("pause");
						break;
					case 6:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "�Ƿ�����!" << endl;
						Sleep(2000);
					}
				} while (cmd1 != 6);
				break;
			case 2:
				do {
					system("cls");
					menuc();
					cin >> cmd1;
					switch (cmd1)
					{
					case 1:
						do {
							system("cls");
							menuc1();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*��ӿγ���Ϣ*/
								AddCouInfo(gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*�ļ���������γ���Ϣ*/
								MergeCouInfo(gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 2:
						DelCouInfo(gloCouList);
						Sleep(2000);
						break;
					case 3:
						/*�޸Ŀγ���Ϣ*/
						UpdateCouInfo(gloCouList);
						Sleep(2000);
						break;
					case 4:
						do {
							system("cls");
							menuc4();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*���γ̴����ѯ*/
								SearchWithCNo(gloCouList);
								system("pause");
								break;
							case 2:
								/*���γ����Ʋ�ѯ*/
								SearchWithCName(gloCouList);
								system("pause");
								break;
							case 3:
								/*������ѧ�ڲ�ѯ*/
								SearchWithTerm(gloCouList);
								system("pause");
								break;
							case 4:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 4);
						break;
					case 5:
						/*��ʾ���пγ���Ϣ*/
						gloCouList.PrintCouList();
						system("pause");
						break;
					case 6:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "�Ƿ�����!" << endl;
						Sleep(2000);
					}
				} while (cmd1 != 6);
				break;
			case 3:
				do {
					system("cls");
					menua();
					cin >> cmd1;
					switch (cmd1)
					{
					case 1:
						AddAcntInfo(gloAcntList);
						Sleep(2000);
						break;
					case 2:
						DelAcntList(gloAcntList);
						Sleep(2000);
						break;
					case 3:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "�Ƿ�����!" << endl;
						Sleep(2000);
					}
				} while (cmd1 != 3);
				break;
			case 4:
				do {
					system("cls");
					menusc();
					cin >> cmd1;
					switch (cmd1)
					{
					case 1:
						do {
							system("cls");
							menusc1();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*ѧ����ѡ��*/
								AdminSelectCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*����ѡ��*/
								AdminSelectSomeCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 2:
						do {
							system("cls");
							menusc2();
							cin >> cmd2;
							switch (cmd2)
							{
							case 1:
								/*ѧ����ѡ��*/
								AdminDropCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*������ѡ*/
								AdminDropSomeCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "�Ƿ�����!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 3:
						/*����ѧ��ѡ��*/
						gloAcntList.OpenSys();
						Sleep(2000);
						break;
					case 4:
						/*�ر�ѧ��ѡ��*/
						gloAcntList.CloseSys();
						Sleep(2000);
						break;
					case 5:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "�Ƿ�����!" << endl;
						Sleep(2000);
					}
				} while (cmd1 != 5);
				break;
			case 5:
				ResetAcntPassword(no, gloAcntList);
				Sleep(2000);
				break;
			case 6:
				break;
			default:
				cout << "\n";
				cout << setw(55) << "�Ƿ�����!" << endl;
				Sleep(2000);
			}
		} while (cmd != 6);
	}
	else
	{
		int cmd;
		do {
			system("cls");
			menustu();
			cin >> cmd;
			switch (cmd)
			{
			case 1:
				/*�鿴��ѡ�γ�*/
				ShowSelected(no, gloStuList, gloCouList);
				system("pause");
				break;
			case 2:
				/*ѡ��*/
				if (!gloAcntList.IsOpen()) 
				{
					cout << endl;
					cout <<setw(58)<< "ѡ��ϵͳδ����!" << endl;
				}
				else {
					StuSelectCourse(no, gloStuList, gloCouList);
				}
				Sleep(2000);
				break;
			case 3:
				/*��ѡ*/
				if (!gloAcntList.IsOpen()) 
				{
					cout << endl;
					cout << setw(58) << "ѡ��ϵͳδ����!" << endl;
				}
				else {
					StuDropCourse(no, gloStuList, gloCouList);
				}
				Sleep(2000);
				break;
			case 4:
				/*����*/
				ResetAcntPassword(no, gloAcntList);
				Sleep(2000);
				break;
			case 5:
				break;
			}
		} while (cmd != 5);
	}
	gloAcntList.Save("AcntList.txt");
	gloCouList.Save("CousInfo.txt");
	gloStuList.Save("StuInfo.txt", "SelectResult.txt");
	return 0;
}