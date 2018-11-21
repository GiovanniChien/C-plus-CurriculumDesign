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
		cout << setw(22) << "登陆" << endl;
		cout << endl;
		cout << endl;
		cout << endl;
		cout << setw(18) << "账号:  ";
		cin >> no;
		//no = "100002";
		//no = "000002";
		cout << endl;
		cout << setw(18) << "密码:  ";
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
								/*添加学生信息*/
								AddStuInfo(gloStuList, gloAcntList);
								Sleep(2000);
								break;
							case 2:
								/*批量添加学生信息*/
								MergeStuInfo(gloStuList, gloAcntList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
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
								/*删除学生信息*/
								DelStuInfo(gloStuList, gloAcntList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*批量删除学生信息*/
								DelSomeStu(gloStuList, gloAcntList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 3:
						/*修改学生信息*/
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
								/*按学号查询*/
								SearchWithSNo(gloStuList);
								system("pause");
								break;
							case 2:
								/*按系别查询*/
								SearchWithDept(gloStuList);
								system("pause");
								break;
							case 3:
								/*按班级查询*/
								SearchWithCla(gloStuList);
								system("pause");
								break;
							case 4:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 4);
						break;
					case 5:
						/*显示所有学生信息*/
						gloStuList.PrintStuList();
						system("pause");
						break;
					case 6:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "非法操作!" << endl;
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
								/*添加课程信息*/
								AddCouInfo(gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*文件批量导入课程信息*/
								MergeCouInfo(gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 2:
						DelCouInfo(gloCouList);
						Sleep(2000);
						break;
					case 3:
						/*修改课程信息*/
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
								/*按课程代码查询*/
								SearchWithCNo(gloCouList);
								system("pause");
								break;
							case 2:
								/*按课程名称查询*/
								SearchWithCName(gloCouList);
								system("pause");
								break;
							case 3:
								/*按开课学期查询*/
								SearchWithTerm(gloCouList);
								system("pause");
								break;
							case 4:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 4);
						break;
					case 5:
						/*显示所有课程信息*/
						gloCouList.PrintCouList();
						system("pause");
						break;
					case 6:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "非法操作!" << endl;
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
						cout << setw(55) << "非法操作!" << endl;
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
								/*学生补选课*/
								AdminSelectCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*批量选课*/
								AdminSelectSomeCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
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
								/*学生退选课*/
								AdminDropCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 2:
								/*批量退选*/
								AdminDropSomeCourse(gloStuList, gloCouList);
								Sleep(2000);
								break;
							case 3:
								break;
							default:
								cout << "\n";
								cout << setw(55) << "非法操作!" << endl;
								Sleep(2000);
							}
						} while (cmd2 != 3);
						break;
					case 3:
						/*开放学生选课*/
						gloAcntList.OpenSys();
						Sleep(2000);
						break;
					case 4:
						/*关闭学生选课*/
						gloAcntList.CloseSys();
						Sleep(2000);
						break;
					case 5:
						break;
					default:
						cout << "\n";
						cout << setw(55) << "非法操作!" << endl;
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
				cout << setw(55) << "非法操作!" << endl;
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
				/*查看已选课程*/
				ShowSelected(no, gloStuList, gloCouList);
				system("pause");
				break;
			case 2:
				/*选课*/
				if (!gloAcntList.IsOpen()) 
				{
					cout << endl;
					cout <<setw(58)<< "选课系统未开放!" << endl;
				}
				else {
					StuSelectCourse(no, gloStuList, gloCouList);
				}
				Sleep(2000);
				break;
			case 3:
				/*退选*/
				if (!gloAcntList.IsOpen()) 
				{
					cout << endl;
					cout << setw(58) << "选课系统未开放!" << endl;
				}
				else {
					StuDropCourse(no, gloStuList, gloCouList);
				}
				Sleep(2000);
				break;
			case 4:
				/*改密*/
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