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

class User{//�û���
	
	
private:
	string username;//�û���
	string password;//����
	int uSub;//��������
	int uAdd;//�ӷ�����
	int uMul;//�˷�����
	int uTest;//���Դ���
	double uAve;//ƽ����ȷ��
	double u_correct_rate[3];//�����β��Ե���ȷ��
	string p_name;//��Ŀ����:���Դ���
	string p_ave;//��Ŀ����:ƽ����ȷ��
public:
	
	User() {
	uSub = 0;
	uAdd = 0;
	uMul = 0;
	uTest = 0; 
	p_name = "���Դ���";
	p_ave = "ƽ����ȷ��";
	};
	void Registers();//ע��
	void Login();//��¼
	void save();//����
	void read();//��ȡ
	void statics();//�û���¼
	void Test();//�Զ��������ϵͳ
};

class RationalNumber{ //����һ����������
	friend class User;
private:
	int denominator;//��������ĸ
	int molecule;//����������
	User usr;
public:
	RationalNumber(int a=1,int b=1);//��Ĭ���βεĹ��캯����������ʼ�����ӷ�ĸ
	void setNumber(int a,int b);//���÷��ӷ�ĸ�ĺ���
	RationalNumber operator +(RationalNumber &c2);//���ؼӷ������
 	RationalNumber operator -(RationalNumber &c2);//���ؼ��������
 	RationalNumber operator *(RationalNumber &c2);//���س˷������
 	RationalNumber operator /(RationalNumber &c2);//���س��������
	bool equals(RationalNumber &c1,RationalNumber &c2);//�ж������������Ƿ����
	void dispaly();//�������������
	friend RationalNumber& reduction(RationalNumber& r);//��Լ�ֺ�����Ϊ��Ԫ����
	friend double change(RationalNumber r);//��������ת��Ϊʵ��
	friend std::istream& operator >>(std::istream& input,RationalNumber & r);//�����������ŵ�����
	friend std::ostream& operator <<(std::ostream& output,RationalNumber & r);//����������ŵ�����
	void statics();
	void add();//�������ӷ����㷨��
	void subtract();//�������������㷨��
	void multiply();//�������˷����㷨��
	void devide();//�������������㷨��
};
	void menu();//ϵͳ�˵�
	char select();//ѡ�����������㷨��
	void setWindowsStyle();//���ô�������
	void calc();//������ʵ��
	void time();//ʱ���ȡģ��
	void start();//��ʼʹ�ü�����
