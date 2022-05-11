
#include"head.h"

/*----------------*/
//                //
//   公共数据块   //
//                //
/*----------------*/
string uName = "";//每次登录的用户名
int scount_a = 0;//记录用户序号
int uSub_p = 0;//记录减法次数
int	uAdd_p = 0;//记录加法次数
int	uMul_p = 0;//记录乘法次数
string uname_pwd_file = "user.txt";  //存储用户名和密码的文件位置
string fName = "";//存放用户使用记录
string FName = "";//存放临时数据


/*----------------*/
//                //
//用户注册登录模块//
//                //
/*----------------*/
#define SIZE 100//最大用户容量
int scount = 0;//用作储存当前已注册用户数

User user[SIZE];
User us;
//保存
void User::save()
{
	ofstream ofile;
	ofile.open(uname_pwd_file, ios::out);

	for (int i = 0; i < scount; i++)
	{
		ofile << user[i].username << endl;
		ofile << user[i].password << endl;
	}
	ofile.close();
}

//读取
void User::read()
{
	ifstream ifile;
	ifile.open(uname_pwd_file, ios::in);

	scount = 0;

	if (!ifile.is_open())
	{
		return;
	}

	for (int i = 0; !ifile.eof(); i++)
	{
		ifile >> user[i].username;
		ifile >> user[i].password;

		scount++;
	}
	scount--;
	ifile.close();
}
//用户使用次数统计
void User::statics(){
	for (int i = 0; i < scount; i++)
	{
		if (uName == user[i].username)
		{
			ofstream ofile;
			string fName = "F:\\STUDY\\C++\\code\\project\\有理数计算器（合）\\有理数计算器（合）\\user_record\\"  + uName +  "_record.txt";
			ofile.open(fName,ios::out);
			user[i].uAdd = uAdd_p;
			user[i].uSub = uSub_p;
			user[i].uMul = uMul_p;
			ofile<<"-------------------------"<<endl;
			ofile<<"-------用户使用记录------"<<endl;
			ofile <<uName<<"是第"<<scount_a<<"位用户，"<<"共做了: "<<"\n"<<user[i].uAdd <<"次加法" <<endl<<user[i].uSub <<"次减法" << endl<<user[i].uMul <<"次乘法" << endl<<"-------------------------";

			cout<<"-------------------------"<<endl;
			cout<<"-------用户使用记录------"<<endl;
			cout<<user[i].username<<"是第"<<scount_a<<"位用户，"<<"共做了: "<<endl<<user[i].uAdd <<"次加法" << endl <<user[i].uSub <<"次减法" << endl<<user[i].uMul <<"次乘法" << endl<<"-------------------------";

			ofile.close();

		}
		else ;
	}


}

//自动出题测试系统
void User::Test(){

	for (int i = 0; i < scount; i++)
	{
		if (uName == user[i].username)
		{
			fName = "F:\\STUDY\\C++\\code\\project\\有理数计算器（合）\\有理数计算器（合）\\test_record\\"  + uName +  "_test_record.txt";//存放用户使用记录
			FName = "F:\\STUDY\\C++\\code\\project\\有理数计算器（合）\\有理数计算器（合）\\test_record\\"  + uName +  "_test_record_temp.txt";//存放临时数据
			cout<<"uName="<<uName<<endl;
			int times ;//用来临时存放最新测试次数
			ifstream ifile;//读取
			ofstream ofile;//写入

			ifile.open(fName,ios::in);//先打开文件
			if(ifile.eof() || !ifile.is_open()){//如果数据为空或者不存在，则将测试数据写入文件

				ofile.open(fName,ios::out);
				user[i].uTest ++;//如果为空或者文件不存在，说明用户第一次使用，uTest初始值为0，++操作变为1

				times = user[i].uTest;
				ofile<<user[i].p_name<<':';//将测试次数1写入文件
				ofile<<user[i].uTest<<endl;


			}else{//如果不为空，则直接读取内容 

				//获取测试次数
				getline(ifile,user[i].p_name,':');
				string str;
				getline(ifile,str);
				stringstream sStream;
				sStream << str;
				sStream >>user[i].uTest;

				user[i].uTest++;  //在上一次测试的基础上，做++操作，测试次数加1，作为本次操作测试次数
				times = user[i].uTest;


				ofile.open(fName,ios_base::out);//打开文件
				ofile<<user[i].p_name<<':';//将本次测试次数写入文件
				ofile<<user[i].uTest<<endl;
			}
			ifile.close();
			ofile.close();

			cout<<user[i].username<<"的本次"<<user[i].p_name<<"："<<user[i].uTest<<endl;
			time(); //记录时间
			cout<<uName<<"进入测试"<<endl;
			cout<<"共十道题，满分100分，请作答。"<<endl;


			int denominator1;//第一个有理数分母
			int molecule1;//第一个有理数分子

			int denominator2;//第二个有理数分母
			int molecule2;//第二个有理数分子

			RationalNumber  answer,input;//用来存放正确答案和用户输入的答案
			char op;//用来选择操作



			ofstream ofile_a(fName,ios::app);//将题目写入数据

			int test_num = 0; //记录用户做测试题的数量
			int correct_num = 0;//存放作答 正确的题目数量
			srand(time(0));//用来产生随机数，需要引入头文件ctime
			for(int k = 0;k<10;k++){

				cout <<endl<<"第"<<k+1<<"题："<<endl;
				ofile_a <<endl<<"第"<<k+1<<"题："<<endl;
				denominator1 = (rand()%200+1)-100; //产生的随机数是一位数，有正有负
				molecule1 = rand()%200-100;
				denominator2 = (rand()%200+1)-100;
				molecule2 = rand()%200-100;

				/*
					下面这个判断是有问题的，由于时间原因，图省事，就把分子为0的情况也pass掉了
				*/
				if (denominator2 == 0 || denominator1==0 || molecule1==0 || molecule2 == 0){ //防止分子分母出现0，防止分子出现0的原因是，没有时间改了，等有时间再修改小bug
					denominator1 = (rand()%200+1)-100;
					denominator2 = (rand()%200+1)-100;
					molecule1 = (rand()%200+1)-100;
					molecule2 = (rand()%200+1)-100;
				}

				RationalNumber r1,r2; //随机产生两个随机数
				r1.denominator = denominator1;
				r1.molecule = molecule1;
				r2.denominator = denominator2;
				r2.molecule = molecule2;

				op = rand()%4;  //随机产生四种运算符

				if(op==0){
					answer = reduction(r1+r2);
					
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"进入加法测试1"<<endl;
						cout<<reduction(r1)<<reduction(r2)<<"="<<endl;			
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<reduction(r2)<<"="<<endl;
					}else{	
						cout<<"进入加法测试2"<<endl;
						cout<<reduction(r1)<<"+"<<reduction(r2)<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"+"<<reduction(r2)<<"="<<endl;
					}
				}
				else if(op==1){
					answer = reduction(r1-r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"进入减法测试1"<<endl;
						cout<<reduction(r1)<<reduction(r2)<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<reduction(r2)<<"="<<endl;
					}else{
						cout<<"进入减法测试2"<<endl;
						cout<<reduction(r1)<<"-"<<reduction(r2)<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"-"<<reduction(r2)<<"="<<endl;
					}
				}
				else if(op==2){
					answer = reduction(r1*r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"进入乘法法测试1"<<endl;
						cout<<reduction(r1)<<"*"<<"("<<reduction(r2)<<")"<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"*"<<"("<<reduction(r2)<<")"<<"="<<endl;
					}else{
						cout<<"进入乘法测试2"<<endl;
						cout<<reduction(r1)<<"*"<<reduction(r2)<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"*"<<reduction(r2)<<"="<<endl;
					} 
				}
				else if(op==3){
					answer = reduction(r1/r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"进入除法测试1"<<endl;
						cout<<reduction(r1)<<"/"<<"("<<reduction(r2)<<")"<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"/"<<"("<<reduction(r2)<<")"<<"="<<endl;
					}else{
						cout<<"进入除法测试2"<<endl;
						cout<<reduction(r1)<<"/"<<reduction(r2)<<"="<<endl;
						cout<<"正确答案"<<answer<<endl;
						ofile_a<<reduction(r1)<<"/"<<reduction(r2)<<"="<<endl;
					}
					
				}
				cin>>input; //用来存放用户输入的结果

				test_num++;
				RationalNumber RN;
				if(RN.equals(answer,input)) 
				{
					correct_num+=1;
					cout<<"用户答案："<<input<<endl<<"恭喜！回答正确"<<endl;
					cout<<endl;
					ofile_a<<"用户答案："<<input<<endl<<"恭喜！回答正确"<<endl;
					ofile_a<<endl;
				}
				else{
					cout<<"用户答案："<<input<<endl;
					ofile_a<<"用户答案："<<input<<endl;
					cout<<"本题作答错误！"<<endl;
					cout<<"正确答案为："<<answer<<endl;
					cout<<endl;
					ofile_a<<"用户答案："<<input<<endl;
					ofile_a<<"本题作答错误！";
					ofile_a<<"正确答案为："<<answer<<endl;
					ofile_a<<endl;
					
				}
			}

			

			double rate = 0;//获取当前的正确率
			rate  = (correct_num*1.0/test_num*1.0)*100;
			//cout<<"你的正确率是："<<rate<<"%"<<endl;


			user[i].uTest = times;//获取当前测试次数


			ifstream ifile_temp (FName,ios::in);//读取

			ofstream ofile_b(fName,ios::app);



			int s1 = 0; //记录第一次
			int s2 = 0;	//记录第二次
			int s3 = 0;	//记录第三次
			int s = 0;  //记录正确率之和
			double ave = 0;//平均正确率


			
			if(user[i].uTest == 1){
				ofstream ofile_temp (FName,ios::out);//写入
				
				ofile_temp<<rate<<endl;
				
				ofile_b<<"测试次数为"<<user[i].uTest<<"，"<<user[i].p_ave<<"为："<<rate<<"%";
				cout<<user[i].username<<"，测试次数不足三次，前"<<user[i].uTest<<"次的"<<user[i].p_ave<<"为："<<rate<<"%"<<endl;
				ofile.close();
			}else if(user[i].uTest == 2){

				string str;
				getline(ifile_temp,str);
				stringstream sStream;
				sStream <<str;
				sStream >> s1;

				s2 = rate;//将第二次测试正确率存入cr
				s = s1 +s2;//前两次正确率之和
				ave =s*1.0/user[i].uTest*1.0; //前两次的平均正确率


				ofstream ofile_temp (FName,ios::out);//写入
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<endl;

				ofile_b<<"测试次数为"<<user[i].uTest<<"，"<<user[i].p_ave<<"为："<<ave<<"%";
				
				cout<<user[i].username<<"，测试次数不足三次，前"<<user[i].uTest<<"次的"<<user[i].p_ave<<"为："<<ave<<"%"<<endl;
			}else if(user[i].uTest == 3){


				//获取第一次正确率
				string str1;
				getline(ifile_temp,str1,',');
				stringstream sStream1;
				sStream1 <<str1;
				sStream1 >> s1;

				//获取第二次正确率
				string str2;
				getline(ifile_temp,str2);
				stringstream sStream2;
				sStream2 <<str2;
				sStream2 >> s2;


				s3 = rate;//将第二次测试正确率存入cr
				s = s1 + s2 + s3;//前两次正确率之和
				ave =s*1.0/user[i].uTest*1.0; //前两次的平均正确率


				ofstream ofile_temp (FName,ios::out);//写入
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<',';
				ofile_temp<<s3<<endl;
				

				ofile_b<<"测试次数为"<<user[i].uTest<<"，"<<user[i].p_ave<<"为："<<ave<<"%";
				cout<<user[i].username<<"，测试次数为三次，前"<<user[i].uTest<<"次的"<<user[i].p_ave<<"为："<<ave<<"%"<<endl;

			}
			else if(user[i].uTest > 3){


				//获取第一次正确率
				string str1;
				getline(ifile_temp,str1,',');

				stringstream sStream1;
				sStream1 <<str1;
				sStream1 >> s1;

				//获取第二次正确率
				string str2;
				getline(ifile_temp,str2,',');
				stringstream sStream2;
				sStream2 <<str2;
				sStream2 >> s2;


				//获取第三次正确率
				string str3;
				getline(ifile_temp,str3);
				stringstream sStream3;
				sStream3 <<str3;
				sStream3 >> s3;
				//cout << ">3s3 = " << s3<<endl;
				

				s1 = s2;//将前一次数据抹除
				s2 = s3;
				s3 = rate;



				s = s1 + s2 + s3;//前两次正确率之和
				ave =s*1.0/3.0; //前两次的平均正确率

				ofstream ofile_temp (FName,ios::out);//写入
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<',';
				ofile_temp<<s3<<endl;

				ofile_b<<"测试次数为"<<user[i].uTest<<"，后三次的"<<user[i].p_ave<<"为："<<ave<<"%";
				cout<<user[i].username<<"，测试次数大于三次，后三次的"<<user[i].p_ave<<"为："<<ave<<"%"<<endl;
			}
		}
	}
}

//注册
void User::Registers()
{
	us.read();//读取已储存用户数据
	string usr;//用户名
	string pw1;//密码1
	string pw2;//密码2
	for (int i = scount; i < SIZE; i++)
	{
here:
		cout << "\t\t\t【系统提示】请输入用户名：";
		cin >> usr;
		//判断新输入的用户信息是否已存在（如果已存在则重新输入）
		for (int i = 0; i < scount; i++)
		{
			if (usr == user[i].username)
			{

				cout << "\t\t\t【系统提示】用户已存在！" << endl;
				goto here;
			}
		}
		user[i].username = usr;

		int chose = -1;
		cout << endl;
		cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
		cout << "\t\t\t┃       1.显示密码     2.隐藏密码      ┃\t\n";
		cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
		cout << "\t\t\t【系统提示】请输入你的选择：";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
			cin >> chose;
		}

		string pword;
		char ch, passwords0[20];
		int x = 0;
		string pword1;
		char ch1, passwords1[20];
		int x1 = 0;
		switch (chose)
		{
		case 1:
			cout << "\t\t\t【系统提示】请输入密码：";
			cin >> pword;
			user[i].password = pword;
			cout << "\t\t\t【系统提示】请再次密码：";
			cin >> pword1;
			if (pword1 != user[i].password)
			{
				cout << "\t\t\t【系统提示】密码不一致！" << endl;
				goto here;
			}
			else
			{
				scount++;//已注册用户加1
				cout << "\t\t\t【系统提示】注册成功！" << endl;
				us.save();//保存用户数据
			}
			break;
		case 2:
			cout << "\t\t\t【系统提示】请输入密码：";
			while ((ch = _getch()) != '\r' && x <= 20)
			{
				if (ch == '\b')
				{
					if (x > 0)
					{
						x--;
						cout << "\b \b";//密码支持退格的实现
					}
					else
						putchar(7);
				}
				else
				{
					passwords0[x++] = ch;
					printf("*");
				}
			}
			passwords0[x] = '\0';
			cout << endl;
			user[i].password = passwords0;

			cout << "\t\t\t【系统提示】请再次密码：";
			while ((ch1 = _getch()) != '\r' && x1 <= 20)
			{
				if (ch1 == '\b')
				{
					if (x1 > 0)
					{
						x1--;
						cout << "\b \b";//密码支持退格的实现
					}
					else
						putchar(7);
				}
				else
				{
					passwords1[x1++] = ch1;
					printf("*");
				}
			}
			passwords1[x1] = '\0';
			cout << endl;
			//比较两次输入的密码是否统一（如果不统一则重新输入）
			if (passwords1 != user[i].password)
			{
				cout << "\t\t\t【系统提示】密码不一致！" << endl;
				goto here;
			}
			else
			{
				scount++;//已注册用户加1
				cout << "\t\t\t【系统提示】注册成功！" << endl;
				us.save();//保存用户数据
			}
			break;
		}
		char choice;
		cout << "\t\t\t【系统提示】是否继续注册(Y/N)？ :";
		while (1)
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
				break;
			else
				cout << "\t\t\t【系统提示】输入格式错误，请重新输入： ";
		}
		if (choice == 'n' || choice == 'N')
		{	
			cout << "\t\t\t【系统提示】注册完成，请退出重新登录！ "<<endl;
			exit(1);
		}
	}
	
	
}

//登录
void User::Login()
{
	
	us.read();//读取已储存用户数据
register_1:
	if(scount == 0){
		cout<<"\t\t\t【系统提示】您是第一个用户，请先注册："<<endl;
		cout<<"\t\t\t【系统提示】是否注册(y/n)：";
		char c;
			cin>>c;
			switch(c){
			case 'y':Registers();break;
			case 'Y':Registers();break;
			case 'n':exit(1); break;
			case 'N':exit(1);break;
			default:
				cout<<"输入错误，请重新输入！"<<endl;
				goto register_1;
			}
	}
	string usr;//用户名
	string pw;//密码
	int time = 0;//统计比较次数

	cout << "\t\t\t【系统提示】请输入用户名：";
	cin >> usr;
	for (int i = 0; i < scount; i++)
	{	
		if(usr == user[i].username){
			break;
		}
		 else if(usr != user[i].username && i==scount-1){
register_2:
			char c;
			cout<<"未找到用户，是否注册(y/n)？:";
			cin>>c;
			switch(c){
			case 'y':Registers();break;
			case 'Y':Registers();break;
			case 'n':exit(1); break;
			case 'N':exit(1);break;
			default:
				cout<<"输入错误，请重新输入！"<<endl;
				goto register_2;
			}
		}
	}

here:
	int chose = -1;
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃       1.显示密码     2.隐藏密码      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << "\t\t\t【系统提示】请输入你的选择：";
	cin >> chose;
	if (chose > 2 || chose < 1)
	{
		cout << "\t\t\t【系统提示】输入格式错误，请重新输入：";
		cin >> chose;
	}

	string pword;
	char ch, passwords0[20];
	int x = 0;
	switch (chose)
	{
	case 1:
		cout << "\t\t\t【系统提示】请输入密码：";
		cin >> pword;
		for (int i = 0; i < scount; i++)
		{

			if (usr == user[i].username && pword == user[i].password)
			{	
				scount_a = i+1;
				uName = user[i].username;
				time++;

				cout << "\t\t\t【系统提示】登录成功！" << endl;
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t【系统提示】密码输入错误！请重新输入密码" << endl;
			goto here;
		}
		break;
	case 2:
		cout << "\t\t\t【系统提示】请输入密码：";
		while ((ch = _getch()) != '\r' && x <= 20)
		{
			if (ch == '\b')
			{
				if (x > 0)
				{
					x--;
					cout << "\b \b";//密码支持退格的实现
				}
				else
					putchar(7);
			}
			else
			{
				passwords0[x++] = ch;
				printf("*");
			}
		}
		passwords0[x] = '\0';
		cout << endl;
		//依次比较已储存信息，比较是否匹配（如不匹配则提示错误）
		for (int i = 0; i < scount; i++)
		{
			if (usr == user[i].username && passwords0 == user[i].password)
			{
				scount_a = i+1;
				uName = user[i].username;
				time++;
				cout << "\t\t\t【系统提示】登录成功！" << endl;
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t【系统提示】密码输入错误！请重新输入密码" << endl;
			goto here;
		}
		break;
	}
}

/*----------------*/
//                //
//有理数计算机模块//
//                //
/*----------------*/
RationalNumber::RationalNumber(int a,int b){
	molecule=a;
	denominator=b;
}

void RationalNumber::setNumber(int a,int b){
	molecule=a;
	denominator=b;
}
RationalNumber RationalNumber::operator +(RationalNumber &c2){

	RationalNumber c;
	c.denominator = denominator*c2.denominator;
	c.molecule = molecule*c2.denominator+c2.molecule*denominator;
	return c;
}
RationalNumber RationalNumber::operator -(RationalNumber &c2){

	RationalNumber c;
	c.denominator = denominator*c2.denominator;
	c.molecule = molecule*c2.denominator-c2.molecule*denominator;
	return c;
}
RationalNumber RationalNumber::operator *(RationalNumber &c2){

	RationalNumber c;
	c.denominator = denominator*c2.denominator;
	c.molecule = molecule*c2.molecule;
	return c;
}
RationalNumber RationalNumber::operator /(RationalNumber &c2){
	RationalNumber c;
	c.denominator = denominator*c2.molecule;
	c.molecule = molecule*c2.denominator;
	return c;
}
bool RationalNumber::equals(RationalNumber &c1,RationalNumber &c2){
	if(c1.denominator*c2.molecule == c1.molecule*c2.denominator){
		return true;
	}else
	{
		return false;
	}
}


void RationalNumber::dispaly(){ //有理数输出函数实现
	cout<<molecule<<"/"<<denominator<<endl;
}

ostream & operator<<(ostream& output,RationalNumber & r){  //实现输出符号重载
	if(r.denominator<0){ 
		r.denominator=-1*r.denominator;
		output<<"-("<<r.molecule<<"/"<<r.denominator<<")";
		r.denominator=-1*r.denominator;
	}
	else if(r.molecule<0){
		r.molecule=-1*r.molecule;
		output<<"-("<<r.molecule<<"/"<<r.denominator<<")";
		r.molecule=-1*r.molecule;
	}
	else 
		output<<"("<<r.molecule<<"/"<<r.denominator<<")";
	return output;
}
istream & operator>>(istream& input,RationalNumber &r){ //实现输入流函数重载
	input >> r.molecule>>r.denominator;
	return input;
}
double change(RationalNumber r){  //实现有理数转换成实数
	return static_cast<double>(r.molecule*1.0)/static_cast<double>(r.denominator);
}
RationalNumber & reduction(RationalNumber &r){ //实现约分
	int a,b,temp;
	if(r.denominator<0){
		r.molecule = -r.molecule;
		r.denominator = -r.denominator;
	}
	if(r.denominator>abs(r.molecule)){
		a=r.denominator;
		b=abs(r.molecule);
	}
	else{
		a=abs(r.molecule);
		b=r.denominator;
	}
	while(b!=0){
		temp=a%b;
		a=b;
		b=temp;
	}
	r.molecule=r.molecule/a;
	r.denominator=r.denominator/a;

	return r;

}
void RationalNumber::add(){
	RationalNumber a;
	RationalNumber b;
	cout<<"进行有理数的加法运算"<<endl;
	cout<<"请输入第一个有理数的分子和分母"<<endl;
	cin>>a;
	cout<<"请输入第二个有理数的分子和分母"<<endl;
	cin>>b;
	if(b.denominator<0 ||b.molecule<0){
		cout<<reduction(a)<<reduction(b)<<"="<<reduction(a+b)<<endl;
	}
	else{
		cout<<reduction(a)<<"+"<<reduction(b)<<"="<<reduction(a+b)<<endl;
	}
}
void RationalNumber::subtract(){
	RationalNumber a;
	RationalNumber b;
	cout<<"进行有理数的减法运算"<<endl;
	cout<<"请输入第一个有理数的分子和分母"<<endl;
	cin>>a;
	cout<<"请输入第二个有理数的分子和分母"<<endl;
	cin>>b;
	if(b.denominator<0 ||b.molecule<0){
		cout<<reduction(a)<<reduction(b)<<"="<<reduction(a+b)<<endl;
	}
	else{
		cout<<reduction(a)<<"-"<<reduction(b)<<"="<<reduction(a-b)<<endl;
	}
}
void RationalNumber::multiply(){
	RationalNumber a;
	RationalNumber b;
	cout<<"进行有理数的乘法运算"<<endl;
	cout<<"请输入第一个有理数的分子和分母"<<endl;
	cin>>a;
	cout<<"请输入第二个有理数的分子和分母"<<endl;
	cin>>b;
	if(b.denominator<0 ||b.molecule<0){
		cout<<reduction(a)<<"*"<<"("<<reduction(b)<<")"<<"="<<reduction(a+b)<<endl;
	}
	else{
		cout<<reduction(a)<<"*"<<reduction(b)<<"="<<reduction(a*b)<<endl;
	}
}
void RationalNumber::devide(){
	RationalNumber a;
	RationalNumber b;
	cout<<"进行有理数的除法运算"<<endl;
	cout<<"请输入第一个有理数的分子和分母"<<endl;
	cin>>a;
	cout<<"请输入第二个有理数的分子和分母"<<endl;
	cin>>b;
	if(b.denominator<0 ||b.molecule<0){
		cout<<reduction(a)<<"/"<<"("<<reduction(b)<<")"<<"="<<reduction(a+b)<<endl;
	}
	else{
		cout<<reduction(a)<<"/"<<reduction(b)<<"="<<reduction(a/b)<<endl;
	}
}



void menu(){
	cout<<"---------1.有理数加法运算----------"<<endl;
	cout<<"---------2.有理数减法运算----------"<<endl;
	cout<<"---------3.有理数乘法运算----------"<<endl;
	cout<<"---------4.有理数除法运算----------"<<endl;
	cout<<"---------5.有理数运算测试----------"<<endl;
	cout<<"---------6.退出计算器----------"<<endl;
}
void calc(){
	char a;
	cout<<"是否进入教程?(y/n)"<<endl;
Loop:
	a=getch();
	switch(a){
	case 'y':
		{
			cout<<"以下有理数输出形式均为（a/b）"<<endl;
			RationalNumber r1(3,5),r2(2,9),r3,r4;
			cout<<"r1和r2由带参构造函数创建"<<endl;
			cout<<"r1："<<r1<<" r2: "<<r2<<endl;
			cout<<"r3和r4由键盘键入      （请按任意键开始从键盘输入）"<<endl;
			getch();
			cout<<"请输入r3: ";
			cin>>r3;
			cout<<"请输入r4: ";
			cin>>r4;
			cout<<"r1:  "<<r1<<"  r2:  "<<r2<<"  r3:  "<<reduction(r3)<<"  r4:  "<<reduction(r4)<<endl;
			cout<<"r1: "<<r1<<"      转换成实数为："<<setprecision(3)<<change(r1)<<endl;
			cout<<"r2: "<<r2<<"      转换成实数为："<<setprecision(3)<<change(r2)<<endl;
			cout<<"r3: "<<r3<<"      转换成实数为："<<setprecision(3)<<change(r3)<<endl;
			cout<<"r4: "<<r4<<"      转换成实数为："<<setprecision(3)<<change(r4)<<endl;
			cout<<"r1+r2: "<<reduction(r1)<<"+"<<reduction(r2)<<"="<<reduction(r1+r2)<<endl;
			cout<<"r2-r3: "<<reduction(r2)<<"-"<<reduction(r3)<<"="<<reduction(r2-r3)<<endl;
			cout<<"r3*r4: "<<reduction(r3)<<"*"<<reduction(r4)<<"*"<<reduction(r3*r4)<<endl;
			cout<<"r2/r4: "<<reduction(r2)<<"/"<<reduction(r4)<<"="<<reduction(r2/r4)<<endl;
		};
	case 'n':
		{
			cout<<"是否进入菜单？(y/n)"<<endl;

			char c;
			while(1){
				c=getch();
				if(c=='y'){
					c=select();
					if(c=='6')
						break;
				}
				else if(c=='n'){
					break;
				}
				else
					;
			}

			cout<<"已经退出运算，按任意键退出程序"<<endl;
			getch();
			cout<<"成功退出！"<<endl;
		};
		break;
	default:
		cout<<"您的输入有误，请重新输入(y/n)"<<endl;
		goto Loop;

	}
}

char select(){
	RationalNumber RN;
	User user;
	char c;
	while(1){
		menu();
		c=getch();
		switch(c){
		case'1':RN.add();uAdd_p++;break;
		case'2':RN.subtract();uSub_p++;break;
		case'3':RN.multiply();uMul_p++;break;
		case'4':RN.devide();break;
		case'5':user.Test();break;
		case'6':break;
		}
		if(c=='6')
			break;
	}
	return c;
}
void setWindowsStyle(){
	system("title 有理数计算器");
	system("color f0");
	system("mode con cols=80 lines=40");
}
void time(){
	fName = "F:\\STUDY\\C++\\code\\project\\有理数计算器（合）\\有理数计算器（合）\\test_record\\"  + uName +  "_test_record.txt";//存放用户使用记录
	fstream ofile(fName,ios::app);
	// 基于当前系统的当前日期/时间

	time_t now = time(0);
	tm *ltm = localtime(&now);

	// 输出 tm 结构的各个组成部分
	cout <<"作答的时间为："<<endl;
	cout <<1900 + ltm->tm_year << "年";
	cout << 1 + ltm->tm_mon<< "月";
	cout <<  ltm->tm_mday << "日"<< endl;
	cout << "时间: "<< ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
	cout << "--------------------------"<<endl;

	ofile<<"作答的时间为："<<endl;
	ofile <<1900 + ltm->tm_year << "年";
	ofile << 1 + ltm->tm_mon<< "月";
	ofile <<  ltm->tm_mday << "日"<< endl;
	ofile << "时间: "<< ltm->tm_hour << ":";
	ofile << ltm->tm_min << ":";
	ofile << ltm->tm_sec << endl;
	ofile << "--------------------------"<<endl;

	ofile.close();
}
void start(){
	cout << endl;
	cout << "\t\t\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n";
	cout << "\t\t\t┃       1.注    册     2.登    录      ┃\t\n";
	cout << "\t\t\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n";
	cout << "\t\t\t【系统提示】请输入你的选择：";
	char chose;	
	while (1)
		{
			cin >> chose;
			if (chose == '1' ||chose == '2')
				break;
			else
				cout << "\t\t\t【系统提示】输入格式错误，请重新输入： ";
		}
	switch (chose)
	{
	case '1':us.Registers(); break;
	case '2':us.Login(); break;
	}
}

int main(){
	//设置窗口类型
	setWindowsStyle();

	//开始计算器使用
	start();

	//计算器模块
	calc();

	//统计模块
	us.statics();

	system("pause");
	return 0;
}

