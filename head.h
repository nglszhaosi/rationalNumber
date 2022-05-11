#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <conio.h>
#include <iomanip> 
#include <stdlib.h>
#include <ctime>
#include <sstream>
#include<cmath>
using namespace std;

class User{//用户类
	
	
private:
	string username;//用户名
	string password;//密码
	int uSub;//减法次数
	int uAdd;//加法次数
	int uMul;//乘法次数
	int uTest;//测试次数
	double uAve;//平均正确率
	double u_correct_rate[3];//后三次测试的正确率
	string p_name;//项目名称:测试次数
	string p_ave;//项目名称:平均正确率
public:
	
	User() {
	uSub = 0;
	uAdd = 0;
	uMul = 0;
	uTest = 0; 
	p_name = "测试次数";
	p_ave = "平均正确率";
	};
	void Registers();//注册
	void Login();//登录
	void save();//保存
	void read();//读取
	void statics();//用户记录
	void Test();//自动出题测试系统
};

class RationalNumber{ //定义一个有理数类
	friend class User;
private:
	int denominator;//有理数分母
	int molecule;//有理数分子
	User usr;
public:
	RationalNumber(int a=1,int b=1);//带默认形参的构造函数，用来初始化分子分母
	void setNumber(int a,int b);//设置分子分母的函数
	RationalNumber operator +(RationalNumber &c2);//重载加法运算符
 	RationalNumber operator -(RationalNumber &c2);//重载减法运算符
 	RationalNumber operator *(RationalNumber &c2);//重载乘法运算符
 	RationalNumber operator /(RationalNumber &c2);//重载除法运算符
	bool equals(RationalNumber &c1,RationalNumber &c2);//判断两个有理数是否相等
	void dispaly();//输出有理数函数
	friend RationalNumber& reduction(RationalNumber& r);//将约分函数设为友元函数
	friend double change(RationalNumber r);//将有理数转换为实数
	friend std::istream& operator >>(std::istream& input,RationalNumber & r);//对输入流符号的重载
	friend std::ostream& operator <<(std::ostream& output,RationalNumber & r);//对输出流符号的重载
	void statics();
	void add();//有理数加法运算法则
	void subtract();//有理数减法运算法则
	void multiply();//有理数乘法运算法则
	void devide();//有理数除法运算法则
};
	void menu();//系统菜单
	char select();//选择有理数运算法则
	void setWindowsStyle();//设置窗口类型
	void calc();//计算器实现
	void time();//时间获取模块
	void start();//开始使用计算器
