#include<iostream>
#include<vector>

#include <fstream>
#include <sstream>
#include <Windows.h>
#include<iomanip>
#include"base.h"
using namespace std;

student::student(int a, string b, string c, int d)
{
	student_ID = a;
	student_name = b;
	department_name = c;
	class_ID = d;
}

int School::show_menu()
{
	while (1)
	{
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t��==============================��\n");
		printf("\t\t\t��                              \n");
		printf("\t\t\t��  1->����ѧ��                 \n");
		printf("\t\t\t��  2->ɾ��ѧ��               \n");
		printf("\t\t\t��  2->����ѧ��               \n");
		printf("\t\t\t��  2->�޸�ѧ��              \n");
		printf("\t\t\t��  2->��ʾѧ��               \n");
		printf("\t\t\t��  6->��ʾѧ��               \n");
		printf("\t\t\t��  ������ѡ��[]                  \n");
		printf("\t\t\t��                              \n");
		printf("\t\t\t��==============================��\n");
		rewind(stdin);
		string temp;
		cin >> temp;
		rewind(stdin);
		int res;
		stringstream ss;
		ss << temp;
		ss >> res;
		if (res>6||res<1)
		{
			cout << "�������,����������" << endl;
			Sleep(1000);
		}
		else
		{
			return res;
		}
	}
}

int School::my_run()
{
	int opnumtemp;
	opnumtemp = 100;
	while (opnumtemp != 3)
	{
		opnumtemp = show_menu();
		switch (opnumtemp)
		{
		case 6:cout << "�ټ�����лʹ�ã���ӭ�´�����" << endl; break;
		case 1:insert_student(); break;
		case 2:delete_student(); break;
		}
	}
	return 0;
}

vector<student> School::student_file_in(string path)
{
    fstream infile;
    infile.open(path);
}

int School::file_in()
{
	fstream infile;
	string filesite = "cache/init.txt";
	rewind(stdin);
	infile.open(filesite);
	if (infile.fail())
	{	
		cout << "ȱʧ�����Թؼ��ļ������´�����" << endl;
		infile.open("cache/init.txt", std::ios::out | std::ios::app);
		Sleep(2000);
		return 0;
	}
	for (int j(1); !infile.eof(); )
	{	
		string temp_name;
		infile >> temp_name;
		department temp2;
		temp2.department_name = temp_name;
		my_school.push_back(temp2);
	}
	for (int i(0); i < my_school.size(); i++)
	{
		string file_path = "cache/" + my_school[i].department_name;
		
	}
	return 1;
}

int School::file_out()
{
	fstream myoperate;
	myoperate.open("cache/init.txt", ofstream::out);
	if (myoperate.fail())
	{
		cout << "�ļ�����ʧ��!!!" << endl;
		Sleep(2000);
		return 0;
	}
	
	for (int i(0); i < my_school.size(); i++)
	{
		string department_name;
		department_name = my_school[i].department_name;
		myoperate << department_name << endl;
	}
	myoperate.close();
	cout << "�ļ������ɹ�,������һ��" << endl;
	Sleep(2000);
	
	return 0;
}

int School::insert_student()
{
	while (1)
	{
		string temp_name;
		int temp_ID;
		int temp_class_ID;
		string temp_department_name;


		system("cls");
		system("color f1");
		cout << "����ѧ������" << endl;
		cin >> temp_name;
		cout << "����ѧ��ѧ��" << endl;
		cin >> temp_ID;
		cout << "����༶���" << endl;
		cin >> temp_class_ID;
		cout << "����ѧ��Ժϵ" << endl;
		cin >> temp_department_name;
		int department_code(-1);
		for (int i(0); i < my_school.size(); i++)
		{
			if (my_school[i].department_name == temp_department_name)
			{
				department_code = i;
				break;
			}
		}
		if (department_code == -1)
		{
			cout << "the department " << temp_department_name << " does not exists" << endl;
			return 0;
		}
		else
		{
			student temp(temp_ID, temp_name, temp_department_name, temp_class_ID);
			my_school[department_code].student_list.push_back(temp);		
		}
	}
	return 1;
}

int School::delete_student()
{
	return 0;
}
