#include"menu.h"
#include<iostream>
#include<iomanip>

using namespace std;

void menu()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "==========学生选课管理系统==========" << endl;
	cout << setw(68) << "||          1 学生管理            ||" << endl;
	cout << setw(68) << "||          2 课程管理            ||" << endl;
	cout << setw(68) << "||          3 账户管理            ||" << endl;
	cout << setw(68) << "||          4 选课管理            ||" << endl;
	cout << setw(68) << "||          5 修改密码            ||" << endl;
	cout << setw(68) << "||          6 退出                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menus()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========学生管理子系统===========" << endl;
	cout << setw(68) << "||        1 添加学生信息          ||" << endl;
	cout << setw(68) << "||        2 删除学生信息          ||" << endl;
	cout << setw(68) << "||        3 修改学生信息          ||" << endl;
	cout << setw(68) << "||        4 查询学生信息          ||" << endl;
	cout << setw(68) << "||        5 显示所有学生信息      ||" << endl;
	cout << setw(68) << "||        6 退出学生管理子系统    ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menus1()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========学生管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~添加~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 添加学生信息            ||" << endl;
	cout << setw(68) << "||      2 文件批量导入学生信息    ||" << endl;
	cout << setw(68) << "||      3 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menus2()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========学生管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~删除~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 删除学生信息            ||" << endl;
	cout << setw(68) << "||      2 批量删除学生信息        ||" << endl;
	cout << setw(68) << "||      3 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menus4()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========学生管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~查询~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 按学号查询              ||" << endl;
	cout << setw(68) << "||      2 按系别查询              ||" << endl;
	cout << setw(68) << "||      3 按班级查询              ||" << endl;
	cout << setw(68) << "||      4 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menuc()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========课程管理子系统===========" << endl;
	cout << setw(68) << "||        1 添加课程信息          ||" << endl;
	cout << setw(68) << "||        2 删除课程信息          ||" << endl;
	cout << setw(68) << "||        3 修改课程信息          ||" << endl;
	cout << setw(68) << "||        4 查询课程信息          ||" << endl;
	cout << setw(68) << "||        5 显示所有课程信息      ||" << endl;
	cout << setw(68) << "||        6 退出课程管理子系统    ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menuc1()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========课程管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~添加~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 添加课程信息            ||" << endl;
	cout << setw(68) << "||      2 文件批量导入课程信息    ||" << endl;
	cout << setw(68) << "||      3 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menuc4()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========课程管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~查询~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 按课程代码查询          ||" << endl;
	cout << setw(68) << "||      2 按课程名称查询          ||" << endl;
	cout << setw(68) << "||      3 按开课学期查询          ||" << endl;
	cout << setw(68) << "||      4 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menua()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========账户管理子系统===========" << endl;
	cout << setw(68) << "||        1 注册账户              ||" << endl;
	cout << setw(68) << "||        2 注销账户              ||" << endl;
	cout << setw(68) << "||        3 退出账户管理子系统    ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menusc()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========选课管理子系统===========" << endl;
	cout << setw(68) << "||     1 选课                     ||" << endl;
	cout << setw(68) << "||     2 退选                     ||" << endl;
	cout << setw(68) << "||     3 开放学生选课             ||" << endl;
	cout << setw(68) << "||     4 关闭学生选课             ||" << endl;
	cout << setw(68) << "||     5 退出选课管理子系统       ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menusc1()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========选课管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~选课~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 学生补选课              ||" << endl;
	cout << setw(68) << "||      2 批量选课                ||" << endl;
	cout << setw(68) << "||      3 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menusc2()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "===========选课管理子系统===========" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~退选~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      ~~~~~~~~~~~~~~~~~~~~      ||" << endl;
	cout << setw(68) << "||      1 学生退选课              ||" << endl;
	cout << setw(68) << "||      2 批量退选                ||" << endl;
	cout << setw(68) << "||      3 返回上级目录...         ||" << endl;
	cout << setw(68) << "||                                ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}

void menustu()
{
	cout << "\n\n\n\n";
	cout << setw(68) << "============学生选课系统============" << endl;
	cout << setw(68) << "||        1 查看已选课程          ||" << endl;
	cout << setw(68) << "||        2 选课                  ||" << endl;
	cout << setw(68) << "||        3 退选                  ||" << endl;
	cout << setw(68) << "||        4 修改密码              ||" << endl;
	cout << setw(68) << "||        5 退出                  ||" << endl;
	cout << setw(68) << "====================================" << endl;
	cout << "\n";
	cout << setw(47) << "请选择操作:";
}
