
#include"head.h"

/*----------------*/
//                //
//   �������ݿ�   //
//                //
/*----------------*/
string uName = "";//ÿ�ε�¼���û���
int scount_a = 0;//��¼�û����
int uSub_p = 0;//��¼��������
int	uAdd_p = 0;//��¼�ӷ�����
int	uMul_p = 0;//��¼�˷�����
string uname_pwd_file = "user.txt";  //�洢�û�����������ļ�λ��
string fName = "";//����û�ʹ�ü�¼
string FName = "";//�����ʱ����


/*----------------*/
//                //
//�û�ע���¼ģ��//
//                //
/*----------------*/
#define SIZE 100//����û�����
int scount = 0;//�������浱ǰ��ע���û���

User user[SIZE];
User us;
//����
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

//��ȡ
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
//�û�ʹ�ô���ͳ��
void User::statics(){
	for (int i = 0; i < scount; i++)
	{
		if (uName == user[i].username)
		{
			ofstream ofile;
			string fName = "F:\\STUDY\\C++\\code\\project\\���������������ϣ�\\���������������ϣ�\\user_record\\"  + uName +  "_record.txt";
			ofile.open(fName,ios::out);
			user[i].uAdd = uAdd_p;
			user[i].uSub = uSub_p;
			user[i].uMul = uMul_p;
			ofile<<"-------------------------"<<endl;
			ofile<<"-------�û�ʹ�ü�¼------"<<endl;
			ofile <<uName<<"�ǵ�"<<scount_a<<"λ�û���"<<"������: "<<"\n"<<user[i].uAdd <<"�μӷ�" <<endl<<user[i].uSub <<"�μ���" << endl<<user[i].uMul <<"�γ˷�" << endl<<"-------------------------";

			cout<<"-------------------------"<<endl;
			cout<<"-------�û�ʹ�ü�¼------"<<endl;
			cout<<user[i].username<<"�ǵ�"<<scount_a<<"λ�û���"<<"������: "<<endl<<user[i].uAdd <<"�μӷ�" << endl <<user[i].uSub <<"�μ���" << endl<<user[i].uMul <<"�γ˷�" << endl<<"-------------------------";

			ofile.close();

		}
		else ;
	}


}

//�Զ��������ϵͳ
void User::Test(){

	for (int i = 0; i < scount; i++)
	{
		if (uName == user[i].username)
		{
			fName = "F:\\STUDY\\C++\\code\\project\\���������������ϣ�\\���������������ϣ�\\test_record\\"  + uName +  "_test_record.txt";//����û�ʹ�ü�¼
			FName = "F:\\STUDY\\C++\\code\\project\\���������������ϣ�\\���������������ϣ�\\test_record\\"  + uName +  "_test_record_temp.txt";//�����ʱ����
			cout<<"uName="<<uName<<endl;
			int times ;//������ʱ������²��Դ���
			ifstream ifile;//��ȡ
			ofstream ofile;//д��

			ifile.open(fName,ios::in);//�ȴ��ļ�
			if(ifile.eof() || !ifile.is_open()){//�������Ϊ�ջ��߲����ڣ��򽫲�������д���ļ�

				ofile.open(fName,ios::out);
				user[i].uTest ++;//���Ϊ�ջ����ļ������ڣ�˵���û���һ��ʹ�ã�uTest��ʼֵΪ0��++������Ϊ1

				times = user[i].uTest;
				ofile<<user[i].p_name<<':';//�����Դ���1д���ļ�
				ofile<<user[i].uTest<<endl;


			}else{//�����Ϊ�գ���ֱ�Ӷ�ȡ���� 

				//��ȡ���Դ���
				getline(ifile,user[i].p_name,':');
				string str;
				getline(ifile,str);
				stringstream sStream;
				sStream << str;
				sStream >>user[i].uTest;

				user[i].uTest++;  //����һ�β��ԵĻ����ϣ���++���������Դ�����1����Ϊ���β������Դ���
				times = user[i].uTest;


				ofile.open(fName,ios_base::out);//���ļ�
				ofile<<user[i].p_name<<':';//�����β��Դ���д���ļ�
				ofile<<user[i].uTest<<endl;
			}
			ifile.close();
			ofile.close();

			cout<<user[i].username<<"�ı���"<<user[i].p_name<<"��"<<user[i].uTest<<endl;
			time(); //��¼ʱ��
			cout<<uName<<"�������"<<endl;
			cout<<"��ʮ���⣬����100�֣�������"<<endl;


			int denominator1;//��һ����������ĸ
			int molecule1;//��һ������������

			int denominator2;//�ڶ�����������ĸ
			int molecule2;//�ڶ�������������

			RationalNumber  answer,input;//���������ȷ�𰸺��û�����Ĵ�
			char op;//����ѡ�����



			ofstream ofile_a(fName,ios::app);//����Ŀд������

			int test_num = 0; //��¼�û��������������
			int correct_num = 0;//������� ��ȷ����Ŀ����
			srand(time(0));//�����������������Ҫ����ͷ�ļ�ctime
			for(int k = 0;k<10;k++){

				cout <<endl<<"��"<<k+1<<"�⣺"<<endl;
				ofile_a <<endl<<"��"<<k+1<<"�⣺"<<endl;
				denominator1 = (rand()%200+1)-100; //�������������һλ���������и�
				molecule1 = rand()%200-100;
				denominator2 = (rand()%200+1)-100;
				molecule2 = rand()%200-100;

				/*
					��������ж���������ģ�����ʱ��ԭ��ͼʡ�£��Ͱѷ���Ϊ0�����Ҳpass����
				*/
				if (denominator2 == 0 || denominator1==0 || molecule1==0 || molecule2 == 0){ //��ֹ���ӷ�ĸ����0����ֹ���ӳ���0��ԭ���ǣ�û��ʱ����ˣ�����ʱ�����޸�Сbug
					denominator1 = (rand()%200+1)-100;
					denominator2 = (rand()%200+1)-100;
					molecule1 = (rand()%200+1)-100;
					molecule2 = (rand()%200+1)-100;
				}

				RationalNumber r1,r2; //����������������
				r1.denominator = denominator1;
				r1.molecule = molecule1;
				r2.denominator = denominator2;
				r2.molecule = molecule2;

				op = rand()%4;  //����������������

				if(op==0){
					answer = reduction(r1+r2);
					
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"����ӷ�����1"<<endl;
						cout<<reduction(r1)<<reduction(r2)<<"="<<endl;			
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<reduction(r2)<<"="<<endl;
					}else{	
						cout<<"����ӷ�����2"<<endl;
						cout<<reduction(r1)<<"+"<<reduction(r2)<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"+"<<reduction(r2)<<"="<<endl;
					}
				}
				else if(op==1){
					answer = reduction(r1-r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"�����������1"<<endl;
						cout<<reduction(r1)<<reduction(r2)<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<reduction(r2)<<"="<<endl;
					}else{
						cout<<"�����������2"<<endl;
						cout<<reduction(r1)<<"-"<<reduction(r2)<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"-"<<reduction(r2)<<"="<<endl;
					}
				}
				else if(op==2){
					answer = reduction(r1*r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"����˷�������1"<<endl;
						cout<<reduction(r1)<<"*"<<"("<<reduction(r2)<<")"<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"*"<<"("<<reduction(r2)<<")"<<"="<<endl;
					}else{
						cout<<"����˷�����2"<<endl;
						cout<<reduction(r1)<<"*"<<reduction(r2)<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"*"<<reduction(r2)<<"="<<endl;
					} 
				}
				else if(op==3){
					answer = reduction(r1/r2);
					if(r2.denominator<0 ||r2.molecule<0){
						cout<<"�����������1"<<endl;
						cout<<reduction(r1)<<"/"<<"("<<reduction(r2)<<")"<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"/"<<"("<<reduction(r2)<<")"<<"="<<endl;
					}else{
						cout<<"�����������2"<<endl;
						cout<<reduction(r1)<<"/"<<reduction(r2)<<"="<<endl;
						cout<<"��ȷ��"<<answer<<endl;
						ofile_a<<reduction(r1)<<"/"<<reduction(r2)<<"="<<endl;
					}
					
				}
				cin>>input; //��������û�����Ľ��

				test_num++;
				RationalNumber RN;
				if(RN.equals(answer,input)) 
				{
					correct_num+=1;
					cout<<"�û��𰸣�"<<input<<endl<<"��ϲ���ش���ȷ"<<endl;
					cout<<endl;
					ofile_a<<"�û��𰸣�"<<input<<endl<<"��ϲ���ش���ȷ"<<endl;
					ofile_a<<endl;
				}
				else{
					cout<<"�û��𰸣�"<<input<<endl;
					ofile_a<<"�û��𰸣�"<<input<<endl;
					cout<<"�����������"<<endl;
					cout<<"��ȷ��Ϊ��"<<answer<<endl;
					cout<<endl;
					ofile_a<<"�û��𰸣�"<<input<<endl;
					ofile_a<<"�����������";
					ofile_a<<"��ȷ��Ϊ��"<<answer<<endl;
					ofile_a<<endl;
					
				}
			}

			

			double rate = 0;//��ȡ��ǰ����ȷ��
			rate  = (correct_num*1.0/test_num*1.0)*100;
			//cout<<"�����ȷ���ǣ�"<<rate<<"%"<<endl;


			user[i].uTest = times;//��ȡ��ǰ���Դ���


			ifstream ifile_temp (FName,ios::in);//��ȡ

			ofstream ofile_b(fName,ios::app);



			int s1 = 0; //��¼��һ��
			int s2 = 0;	//��¼�ڶ���
			int s3 = 0;	//��¼������
			int s = 0;  //��¼��ȷ��֮��
			double ave = 0;//ƽ����ȷ��


			
			if(user[i].uTest == 1){
				ofstream ofile_temp (FName,ios::out);//д��
				
				ofile_temp<<rate<<endl;
				
				ofile_b<<"���Դ���Ϊ"<<user[i].uTest<<"��"<<user[i].p_ave<<"Ϊ��"<<rate<<"%";
				cout<<user[i].username<<"�����Դ����������Σ�ǰ"<<user[i].uTest<<"�ε�"<<user[i].p_ave<<"Ϊ��"<<rate<<"%"<<endl;
				ofile.close();
			}else if(user[i].uTest == 2){

				string str;
				getline(ifile_temp,str);
				stringstream sStream;
				sStream <<str;
				sStream >> s1;

				s2 = rate;//���ڶ��β�����ȷ�ʴ���cr
				s = s1 +s2;//ǰ������ȷ��֮��
				ave =s*1.0/user[i].uTest*1.0; //ǰ���ε�ƽ����ȷ��


				ofstream ofile_temp (FName,ios::out);//д��
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<endl;

				ofile_b<<"���Դ���Ϊ"<<user[i].uTest<<"��"<<user[i].p_ave<<"Ϊ��"<<ave<<"%";
				
				cout<<user[i].username<<"�����Դ����������Σ�ǰ"<<user[i].uTest<<"�ε�"<<user[i].p_ave<<"Ϊ��"<<ave<<"%"<<endl;
			}else if(user[i].uTest == 3){


				//��ȡ��һ����ȷ��
				string str1;
				getline(ifile_temp,str1,',');
				stringstream sStream1;
				sStream1 <<str1;
				sStream1 >> s1;

				//��ȡ�ڶ�����ȷ��
				string str2;
				getline(ifile_temp,str2);
				stringstream sStream2;
				sStream2 <<str2;
				sStream2 >> s2;


				s3 = rate;//���ڶ��β�����ȷ�ʴ���cr
				s = s1 + s2 + s3;//ǰ������ȷ��֮��
				ave =s*1.0/user[i].uTest*1.0; //ǰ���ε�ƽ����ȷ��


				ofstream ofile_temp (FName,ios::out);//д��
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<',';
				ofile_temp<<s3<<endl;
				

				ofile_b<<"���Դ���Ϊ"<<user[i].uTest<<"��"<<user[i].p_ave<<"Ϊ��"<<ave<<"%";
				cout<<user[i].username<<"�����Դ���Ϊ���Σ�ǰ"<<user[i].uTest<<"�ε�"<<user[i].p_ave<<"Ϊ��"<<ave<<"%"<<endl;

			}
			else if(user[i].uTest > 3){


				//��ȡ��һ����ȷ��
				string str1;
				getline(ifile_temp,str1,',');

				stringstream sStream1;
				sStream1 <<str1;
				sStream1 >> s1;

				//��ȡ�ڶ�����ȷ��
				string str2;
				getline(ifile_temp,str2,',');
				stringstream sStream2;
				sStream2 <<str2;
				sStream2 >> s2;


				//��ȡ��������ȷ��
				string str3;
				getline(ifile_temp,str3);
				stringstream sStream3;
				sStream3 <<str3;
				sStream3 >> s3;
				//cout << ">3s3 = " << s3<<endl;
				

				s1 = s2;//��ǰһ������Ĩ��
				s2 = s3;
				s3 = rate;



				s = s1 + s2 + s3;//ǰ������ȷ��֮��
				ave =s*1.0/3.0; //ǰ���ε�ƽ����ȷ��

				ofstream ofile_temp (FName,ios::out);//д��
				ofile_temp<<s1<<',';
				ofile_temp<<s2<<',';
				ofile_temp<<s3<<endl;

				ofile_b<<"���Դ���Ϊ"<<user[i].uTest<<"�������ε�"<<user[i].p_ave<<"Ϊ��"<<ave<<"%";
				cout<<user[i].username<<"�����Դ����������Σ������ε�"<<user[i].p_ave<<"Ϊ��"<<ave<<"%"<<endl;
			}
		}
	}
}

//ע��
void User::Registers()
{
	us.read();//��ȡ�Ѵ����û�����
	string usr;//�û���
	string pw1;//����1
	string pw2;//����2
	for (int i = scount; i < SIZE; i++)
	{
here:
		cout << "\t\t\t��ϵͳ��ʾ���������û�����";
		cin >> usr;
		//�ж���������û���Ϣ�Ƿ��Ѵ��ڣ�����Ѵ������������룩
		for (int i = 0; i < scount; i++)
		{
			if (usr == user[i].username)
			{

				cout << "\t\t\t��ϵͳ��ʾ���û��Ѵ��ڣ�" << endl;
				goto here;
			}
		}
		user[i].username = usr;

		int chose = -1;
		cout << endl;
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��       1.��ʾ����     2.��������      ��\t\n";
		cout << "\t\t\t��������������������������������������������������������������������������������\n";
		cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
		cin >> chose;
		if (chose > 2 || chose < -1)
		{
			cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
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
			cout << "\t\t\t��ϵͳ��ʾ�����������룺";
			cin >> pword;
			user[i].password = pword;
			cout << "\t\t\t��ϵͳ��ʾ�����ٴ����룺";
			cin >> pword1;
			if (pword1 != user[i].password)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����벻һ�£�" << endl;
				goto here;
			}
			else
			{
				scount++;//��ע���û���1
				cout << "\t\t\t��ϵͳ��ʾ��ע��ɹ���" << endl;
				us.save();//�����û�����
			}
			break;
		case 2:
			cout << "\t\t\t��ϵͳ��ʾ�����������룺";
			while ((ch = _getch()) != '\r' && x <= 20)
			{
				if (ch == '\b')
				{
					if (x > 0)
					{
						x--;
						cout << "\b \b";//����֧���˸��ʵ��
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

			cout << "\t\t\t��ϵͳ��ʾ�����ٴ����룺";
			while ((ch1 = _getch()) != '\r' && x1 <= 20)
			{
				if (ch1 == '\b')
				{
					if (x1 > 0)
					{
						x1--;
						cout << "\b \b";//����֧���˸��ʵ��
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
			//�Ƚ���������������Ƿ�ͳһ�������ͳһ���������룩
			if (passwords1 != user[i].password)
			{
				cout << "\t\t\t��ϵͳ��ʾ�����벻һ�£�" << endl;
				goto here;
			}
			else
			{
				scount++;//��ע���û���1
				cout << "\t\t\t��ϵͳ��ʾ��ע��ɹ���" << endl;
				us.save();//�����û�����
			}
			break;
		}
		char choice;
		cout << "\t\t\t��ϵͳ��ʾ���Ƿ����ע��(Y/N)�� :";
		while (1)
		{
			cin >> choice;
			if (choice == 'y' || choice == 'Y' || choice == 'n' || choice == 'N')
				break;
			else
				cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺 ";
		}
		if (choice == 'n' || choice == 'N')
		{	
			cout << "\t\t\t��ϵͳ��ʾ��ע����ɣ����˳����µ�¼�� "<<endl;
			exit(1);
		}
	}
	
	
}

//��¼
void User::Login()
{
	
	us.read();//��ȡ�Ѵ����û�����
register_1:
	if(scount == 0){
		cout<<"\t\t\t��ϵͳ��ʾ�����ǵ�һ���û�������ע�᣺"<<endl;
		cout<<"\t\t\t��ϵͳ��ʾ���Ƿ�ע��(y/n)��";
		char c;
			cin>>c;
			switch(c){
			case 'y':Registers();break;
			case 'Y':Registers();break;
			case 'n':exit(1); break;
			case 'N':exit(1);break;
			default:
				cout<<"����������������룡"<<endl;
				goto register_1;
			}
	}
	string usr;//�û���
	string pw;//����
	int time = 0;//ͳ�ƱȽϴ���

	cout << "\t\t\t��ϵͳ��ʾ���������û�����";
	cin >> usr;
	for (int i = 0; i < scount; i++)
	{	
		if(usr == user[i].username){
			break;
		}
		 else if(usr != user[i].username && i==scount-1){
register_2:
			char c;
			cout<<"δ�ҵ��û����Ƿ�ע��(y/n)��:";
			cin>>c;
			switch(c){
			case 'y':Registers();break;
			case 'Y':Registers();break;
			case 'n':exit(1); break;
			case 'N':exit(1);break;
			default:
				cout<<"����������������룡"<<endl;
				goto register_2;
			}
		}
	}

here:
	int chose = -1;
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��       1.��ʾ����     2.��������      ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
	cin >> chose;
	if (chose > 2 || chose < 1)
	{
		cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺";
		cin >> chose;
	}

	string pword;
	char ch, passwords0[20];
	int x = 0;
	switch (chose)
	{
	case 1:
		cout << "\t\t\t��ϵͳ��ʾ�����������룺";
		cin >> pword;
		for (int i = 0; i < scount; i++)
		{

			if (usr == user[i].username && pword == user[i].password)
			{	
				scount_a = i+1;
				uName = user[i].username;
				time++;

				cout << "\t\t\t��ϵͳ��ʾ����¼�ɹ���" << endl;
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t��ϵͳ��ʾ���������������������������" << endl;
			goto here;
		}
		break;
	case 2:
		cout << "\t\t\t��ϵͳ��ʾ�����������룺";
		while ((ch = _getch()) != '\r' && x <= 20)
		{
			if (ch == '\b')
			{
				if (x > 0)
				{
					x--;
					cout << "\b \b";//����֧���˸��ʵ��
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
		//���αȽ��Ѵ�����Ϣ���Ƚ��Ƿ�ƥ�䣨�粻ƥ������ʾ����
		for (int i = 0; i < scount; i++)
		{
			if (usr == user[i].username && passwords0 == user[i].password)
			{
				scount_a = i+1;
				uName = user[i].username;
				time++;
				cout << "\t\t\t��ϵͳ��ʾ����¼�ɹ���" << endl;
			}
		}
		if (time == 0)
		{
			cout << "\t\t\t��ϵͳ��ʾ���������������������������" << endl;
			goto here;
		}
		break;
	}
}

/*----------------*/
//                //
//�����������ģ��//
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


void RationalNumber::dispaly(){ //�������������ʵ��
	cout<<molecule<<"/"<<denominator<<endl;
}

ostream & operator<<(ostream& output,RationalNumber & r){  //ʵ�������������
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
istream & operator>>(istream& input,RationalNumber &r){ //ʵ����������������
	input >> r.molecule>>r.denominator;
	return input;
}
double change(RationalNumber r){  //ʵ��������ת����ʵ��
	return static_cast<double>(r.molecule*1.0)/static_cast<double>(r.denominator);
}
RationalNumber & reduction(RationalNumber &r){ //ʵ��Լ��
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
	cout<<"�����������ļӷ�����"<<endl;
	cout<<"�������һ���������ķ��Ӻͷ�ĸ"<<endl;
	cin>>a;
	cout<<"������ڶ����������ķ��Ӻͷ�ĸ"<<endl;
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
	cout<<"�����������ļ�������"<<endl;
	cout<<"�������һ���������ķ��Ӻͷ�ĸ"<<endl;
	cin>>a;
	cout<<"������ڶ����������ķ��Ӻͷ�ĸ"<<endl;
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
	cout<<"�����������ĳ˷�����"<<endl;
	cout<<"�������һ���������ķ��Ӻͷ�ĸ"<<endl;
	cin>>a;
	cout<<"������ڶ����������ķ��Ӻͷ�ĸ"<<endl;
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
	cout<<"�����������ĳ�������"<<endl;
	cout<<"�������һ���������ķ��Ӻͷ�ĸ"<<endl;
	cin>>a;
	cout<<"������ڶ����������ķ��Ӻͷ�ĸ"<<endl;
	cin>>b;
	if(b.denominator<0 ||b.molecule<0){
		cout<<reduction(a)<<"/"<<"("<<reduction(b)<<")"<<"="<<reduction(a+b)<<endl;
	}
	else{
		cout<<reduction(a)<<"/"<<reduction(b)<<"="<<reduction(a/b)<<endl;
	}
}



void menu(){
	cout<<"---------1.�������ӷ�����----------"<<endl;
	cout<<"---------2.��������������----------"<<endl;
	cout<<"---------3.�������˷�����----------"<<endl;
	cout<<"---------4.��������������----------"<<endl;
	cout<<"---------5.�������������----------"<<endl;
	cout<<"---------6.�˳�������----------"<<endl;
}
void calc(){
	char a;
	cout<<"�Ƿ����̳�?(y/n)"<<endl;
Loop:
	a=getch();
	switch(a){
	case 'y':
		{
			cout<<"���������������ʽ��Ϊ��a/b��"<<endl;
			RationalNumber r1(3,5),r2(2,9),r3,r4;
			cout<<"r1��r2�ɴ��ι��캯������"<<endl;
			cout<<"r1��"<<r1<<" r2: "<<r2<<endl;
			cout<<"r3��r4�ɼ��̼���      ���밴�������ʼ�Ӽ������룩"<<endl;
			getch();
			cout<<"������r3: ";
			cin>>r3;
			cout<<"������r4: ";
			cin>>r4;
			cout<<"r1:  "<<r1<<"  r2:  "<<r2<<"  r3:  "<<reduction(r3)<<"  r4:  "<<reduction(r4)<<endl;
			cout<<"r1: "<<r1<<"      ת����ʵ��Ϊ��"<<setprecision(3)<<change(r1)<<endl;
			cout<<"r2: "<<r2<<"      ת����ʵ��Ϊ��"<<setprecision(3)<<change(r2)<<endl;
			cout<<"r3: "<<r3<<"      ת����ʵ��Ϊ��"<<setprecision(3)<<change(r3)<<endl;
			cout<<"r4: "<<r4<<"      ת����ʵ��Ϊ��"<<setprecision(3)<<change(r4)<<endl;
			cout<<"r1+r2: "<<reduction(r1)<<"+"<<reduction(r2)<<"="<<reduction(r1+r2)<<endl;
			cout<<"r2-r3: "<<reduction(r2)<<"-"<<reduction(r3)<<"="<<reduction(r2-r3)<<endl;
			cout<<"r3*r4: "<<reduction(r3)<<"*"<<reduction(r4)<<"*"<<reduction(r3*r4)<<endl;
			cout<<"r2/r4: "<<reduction(r2)<<"/"<<reduction(r4)<<"="<<reduction(r2/r4)<<endl;
		};
	case 'n':
		{
			cout<<"�Ƿ����˵���(y/n)"<<endl;

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

			cout<<"�Ѿ��˳����㣬��������˳�����"<<endl;
			getch();
			cout<<"�ɹ��˳���"<<endl;
		};
		break;
	default:
		cout<<"����������������������(y/n)"<<endl;
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
	system("title ������������");
	system("color f0");
	system("mode con cols=80 lines=40");
}
void time(){
	fName = "F:\\STUDY\\C++\\code\\project\\���������������ϣ�\\���������������ϣ�\\test_record\\"  + uName +  "_test_record.txt";//����û�ʹ�ü�¼
	fstream ofile(fName,ios::app);
	// ���ڵ�ǰϵͳ�ĵ�ǰ����/ʱ��

	time_t now = time(0);
	tm *ltm = localtime(&now);

	// ��� tm �ṹ�ĸ�����ɲ���
	cout <<"�����ʱ��Ϊ��"<<endl;
	cout <<1900 + ltm->tm_year << "��";
	cout << 1 + ltm->tm_mon<< "��";
	cout <<  ltm->tm_mday << "��"<< endl;
	cout << "ʱ��: "<< ltm->tm_hour << ":";
	cout << ltm->tm_min << ":";
	cout << ltm->tm_sec << endl;
	cout << "--------------------------"<<endl;

	ofile<<"�����ʱ��Ϊ��"<<endl;
	ofile <<1900 + ltm->tm_year << "��";
	ofile << 1 + ltm->tm_mon<< "��";
	ofile <<  ltm->tm_mday << "��"<< endl;
	ofile << "ʱ��: "<< ltm->tm_hour << ":";
	ofile << ltm->tm_min << ":";
	ofile << ltm->tm_sec << endl;
	ofile << "--------------------------"<<endl;

	ofile.close();
}
void start(){
	cout << endl;
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��       1.ע    ��     2.��    ¼      ��\t\n";
	cout << "\t\t\t��������������������������������������������������������������������������������\n";
	cout << "\t\t\t��ϵͳ��ʾ�����������ѡ��";
	char chose;	
	while (1)
		{
			cin >> chose;
			if (chose == '1' ||chose == '2')
				break;
			else
				cout << "\t\t\t��ϵͳ��ʾ�������ʽ�������������룺 ";
		}
	switch (chose)
	{
	case '1':us.Registers(); break;
	case '2':us.Login(); break;
	}
}

int main(){
	//���ô�������
	setWindowsStyle();

	//��ʼ������ʹ��
	start();

	//������ģ��
	calc();

	//ͳ��ģ��
	us.statics();

	system("pause");
	return 0;
}

