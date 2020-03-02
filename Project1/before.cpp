#include <sstream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <cassert>
#include <functional>
#include <conio.h>
#include<cstring> 
#include <stdio.h>
#include<string>
#include<cstdlib>
#include <cstdio>
#include <iostream>
#include <fstream>
#include <Windows.h>
#include<iomanip>
#include <winbase.h>
//#include <stdlib.h>
using namespace std;
class song {//����������һ���������������ܶ�ĸ�������ʵ��
public:
	string songname;//�������
	string pinyin;
	string singername;//���ֵ���
	int serialnum;//���кţ������ڸ赥�������
	int ranknum;//���е�λ��
	int playstatus;//�Ƿ��ڲ���״̬
	int playfrequence;
	int judgefrequence;//���ŵĴ�������Ϊ����ĸ���
	double totalscore;//�ܷ֣�Ҳ�Ǽ���ĸ���
	double starnum;//������
};

class admin
{
public:
	admin();

	friend class ktvsystem;

	friend class user;

	vector<song> mysong;

	int changepassword();//����������ֵ���Ǳ�ʾ״̬���ĳɹ��͵�½�ɹ�

	int login();//��½����

	int add_song();//�Ӹ�

	int delete_song();//ɾ���������ɹ�����1

	int file_in();//���������ļ��ĸ��������سɹ��ͷ���1

	int file_out();//�����ļ�

	int sort_song();//�Ը�������

	int admenu();//��ʾ����Ա��ר�ý��棬����������Ĳ���ֵ

	int initialsong(song& temp);

	int printall(vector<song>& A);

	int printsong(song& temp);

	int legalID(string A);

	int legalpassword(string B);

	int realprintall();

private:
	string ID;
	string password;//��������
};

class user {
public:
	//user();
	friend class ktvsystem;

	friend class admin;

	int usmenu(admin& A);//��ʾ�û����沢���ز���ֵ

	int ordersong(admin& A);//���

	int see_playingqueue(admin& A);//�鿴�����Ŷ��������

	int make_song_top(admin& A);//�ö�

	int change_song(admin& A);//�и�

	int delete_song_inqueue(admin& A);//ɾ�����Ŷ����еĸ�

	int judge_song(admin& A);//����

	int realsee_playingqueue(admin& A);

	int search_song(admin& A);

private:
	//int usopnum;//����ֵ
	vector<int>playing_queue;//���ڲ��ŵĶ��У��������еĲ��ŵĸ���
};

class ktvsystem {
public:
	admin A;
	user B;
	int pmainmenu();
	int initialsys();
	void run();
private:
	int syoperationnum;//system�Ĳ�������
};

bool comp_srerial(const song& A, const song& B)
{
	return A.serialnum < B.serialnum;
}

bool comp_starnum(const song& A, const song& B)
{
	return A.starnum > B.starnum;
}

bool comp_frenum(const song& A, const song& B)
{
	return A.playfrequence > B.playfrequence;
}
#include"alldefine.h"
//��ע���������кź�������������±��ǲ�һ����

int main()
{
	ktvsystem cursys;
	cursys.run();
	return 0;
}


admin::admin(void)
{
	ID = "NJUCS";
	password = "CSNB12";
}

int admin::admenu()
{
	system("cls");
	system("color f1");
	cout << "\n\n\t\t\t��==============================��\n";
	cout << "\t\t\t ��                            \n";
	cout << "\t\t\t �� 1->�鿴���еĸ���            \n";
	cout << "\t\t\t �� 2->��Ӹ���                 \n";
	cout << "\t\t\t �� 3->�����ĵ������            \n";
	cout << "\t\t\t �� 4->�����ĵ�������            \n";
	cout << "\t\t\t �� 5->ɾ������                  \n";
	cout << "\t\t\t �� 6->��������                  \n";
	cout << "\t\t\t �� 7->�޸�����                  \n";
	cout << "\t\t\t �� 8->�˳�                     \n";
	cout << "\t\t\t ��                             \n";
	cout << "\t\t\t��==============================��\n";
	rewind(stdin);
	while (1)
	{
		char op;
		int adnumtemp(0);
		rewind(stdin);
		cin >> op;
		rewind(stdin);
		if (op < '0' || op>'8')
		{
			adnumtemp = 100;
		}
		else
		{
			adnumtemp = op - '0';
		}
		switch (adnumtemp)
		{
		case 1:realprintall(); break;
		case 2:add_song(); break;
		case 3:file_in(); break;
		case 4:file_out(); break;
		case 5:delete_song(); break;
		case 6:sort_song(); break;
		case 7:changepassword(); break;
		case 8:cout << "�ټ�" << endl; return 0;
		default:cout << "������������������" << endl;
		}
		system("cls");
		system("color f1");
		cout << "\n\n\t\t\t��==============================��\n";
		cout << "\t\t\t �� ��\n";
		cout << "\t\t\t �� 1->�鿴���еĸ���  \n";
		cout << "\t\t\t �� 2->��Ӹ���       \n";
		cout << "\t\t\t �� 3->�����ĵ������  \n";
		cout << "\t\t\t �� 4->�����ĵ������� \n";
		cout << "\t\t\t �� 5->ɾ������       \n";
		cout << "\t\t\t �� 6->��������       \n";
		cout << "\t\t\t �� 7->�޸�����       \n";
		cout << "\t\t\t �� 8->�˳�           \n";
		cout << "\t\t\t ��                   \n";
		cout << "\t\t\t��==============================��\n";
		rewind(stdin);
	}
	return 1;
}

int admin::login()
{
	system("cls");
	system("color f1");
	printf("\n\n\t\t\t��==============================��\n");
	printf("\t\t\t��                              \n");
	printf("\t\t\t��  *********����Ա��½********  \n");
	printf("\t\t\t�� ����ԱID��                    \n");
	printf("\t\t\t�� ����Ա���룺                  \n");
	printf("\t\t\t��==============================��\n");
	rewind(stdin);

	string IDtemp;
	string passwordtemp;
	int IDlegal(1);
	int passwordlegal(1);
	int boolsuccess(0);
	char  temp = 's';
	int times(0);
	while (!boolsuccess && times < 3)
	{
		boolsuccess = 1;
		rewind(stdin);
		IDtemp.clear();
		passwordtemp.clear();
		cout << "|********��������˺ţ���ע�������ʽ********|" << endl;
		while (IDlegal)
		{
			IDlegal = 0;
			temp = 's';
			while (temp != '\r' && temp != '\n')
			{
				temp = _getch();
				if ((temp >= 'a' && temp <= 'z') || (temp >= 'A' && temp <= 'Z') || (temp >= '0' && temp <= '9'))
				{
					//putchar('*');
					putchar(temp);
					IDtemp += temp;
				}
				else
				{
					if (temp != '\r' && temp != '\n')
					{
						if ((temp & 0xff) == 8)
						{
							if (IDtemp.length() > 0)
							{
								cout << temp << " " << temp;
								IDtemp.pop_back();
							}
							rewind(stdin);
							continue;
						}
						else
						{
							IDlegal = 1;
							cout << '\r';
							cout << "|*******�����˷Ƿ��ַ�������������*******|" << endl;
							rewind(stdin);
							continue;
						}
					}
					else
					{
						IDlegal = 0;
						cout << endl;
					}

				}
			}
			if (IDtemp.length() >= 12)
			{
				cout << "|*******�������������������*******|" << endl;
				IDlegal = 1;
				IDtemp.clear();
				rewind(stdin);
			}
		}
		IDlegal = 1;
		cout << "|*******����������룬��ע�������ʽ*******|" << endl;
		while (passwordlegal)
		{
			if (passwordlegal == 1)
			{
				passwordtemp.clear();
			}
			rewind(stdin);
			temp = 's';
			passwordlegal = 0;
			while (temp != '\r' && temp != '\n')
			{
				temp = _getch();
				if (temp != '\r' && temp != '\b' && temp != '\n')
				{
					putchar('*');
					passwordtemp += temp;
				}
				if ((temp & 0xff) == 8)
				{
					if (passwordtemp.length() > 0)
					{
						cout << temp;
						cout << " ";
						cout << temp;
						passwordtemp.pop_back();
					}
					rewind(stdin);
					continue;
				}
			}
			cout << endl;
			if (legalpassword(passwordtemp))
			{
				passwordlegal = 0;
			}
			else
			{
				passwordlegal = 1;
				cout << "|***���벻�Ϸ�������������***|" << endl;
			}
		}
		passwordlegal = 1;
		if (IDtemp.length() != ID.length())//���жϳ��ȣ���һ����һ���Ǵ��
		{
			boolsuccess = 0;
			times++;
			cout << "|***û�����ID***|" << endl;
			cout << "�㻹��" << 3 - times << "�εĻ���" << endl;
			continue;
		}
		if (passwordtemp.length() != password.length())
		{
			boolsuccess = 0;
			times++;
			cout << "|***���벻�԰�***|" << endl;
			cout << "�㻹��" << 3 - times << "�εĻ���" << endl;
			continue;
		}
		for (int i = 0; i < IDtemp.length(); i++)//���Ž��б����ȶ�
		{
			if (IDtemp[i] != ID[i])
			{
				boolsuccess = 0;
				times++;
				cout << "|***û�����ID***|" << endl;
				Sleep(1500);
				break;
			}
		}
		for (int i = 0; i < passwordtemp.length(); i++)
		{
			if (passwordtemp[i] != password[i])
			{
				boolsuccess = 0;
				times++;
				cout << "|***���벻�԰�***|" << endl;
				break;
			}
		}
		if (times != 3 && boolsuccess == 0)
		{
			cout << "�㻹��" << 3 - times << "�εĻ���" << endl;
		}
	}
	if (times == 3)
	{
		cout << "|*****������Ͳ��ǹ���Ա���ټ���******|" << endl;
		Sleep(1500);
		return 0;
	}
	cout << "С���ӣ�û�뵽��Ҳ�ǹ���Ա��" << endl;
	cout << "������תҳ��" << endl;
	Sleep(1500);
	admenu();
	return 1;
}

int admin::file_out()
{
	fstream myoperate;
	myoperate.open("ktvsong.txt", ofstream::out);
	if (myoperate.fail())
	{
		cout << "�ļ�����ʧ��!!!" << endl;
		Sleep(2000);
		return 0;
	}
	int length(0);
	length = mysong.size();
	for (int i(0); i < length; i++)
	{
		string mysinger;
		mysinger = mysong[i].singername;
		myoperate << mysinger << " ";

		string mysongname;
		mysongname = mysong[i].songname;
		myoperate << mysongname << " ";

		string mypinyin;
		mypinyin = mysong[i].pinyin;
		myoperate << mypinyin << " ";
		myoperate << endl;
	}
	cout << "�ļ������ɹ�,������һ��" << endl;
	Sleep(2000);
	return 0;
}

int admin::file_in()
{
	ifstream infile;
	string filesite;
	int sus(0);
	int fai(0);
	cout << "���뵼����ļ���" << endl;
	rewind(stdin);
	cin >> filesite;
	infile.open(filesite);
	if (infile.fail())
	{
		cout << "�ļ�����ʧ��!!!" << endl;
		Sleep(2000);
		return 0;
	}
	int n = mysong.size();
	for (int j(1); !infile.eof(); )
	{
		song temp;
		infile >> temp.singername;
		infile >> temp.songname;
		infile >> temp.pinyin;
		temp.judgefrequence = 0;
		temp.playfrequence = 0;
		temp.totalscore = 0;
		if (temp.judgefrequence == 0)
		{
			temp.starnum = 0;
		}
		else
			temp.starnum = temp.totalscore / temp.judgefrequence;
		temp.serialnum = j + n;
		temp.playstatus = 0;
		temp.starnum = 0;
		temp.ranknum = 0;
		int flag = 0;
		for (int i(0); i < mysong.size(); i++)
		{
			if (temp.songname == mysong[i].songname && temp.singername == mysong[i].singername)
			{
				flag = 1;
				break;
			}
		}
		if (flag == 1)
		{
			fai++;
		}
		else
		{
			sus++;
			j++;
			mysong.push_back(temp);
		}
	}
	mysong.pop_back();
	cout << "�ļ�����ɹ�" << endl;
	cout << "����ɹ� " << sus - 1 << "��" << "��ʧ���� " << fai + 1 << "��" << endl;
	cout << "���ڷ�����һ��" << endl;
	Sleep(2000);
	return 1;
}

int admin::add_song()
{
	song temp;
	cout << "input singer name" << endl;
	string singer;
	cin >> singer;
	temp.singername = singer;

	cout << "input song name" << endl;
	rewind(stdin);
	string songname;
	cin >> songname;
	temp.songname = songname;

	cout << "input song pinyin" << endl;
	string mypinyin;
	rewind(stdin);
	cin >> mypinyin;
	temp.pinyin = mypinyin;

	int i = mysong.size();
	temp.serialnum = i + 1;

	initialsong(temp);
	for (int i(0); i < mysong.size(); i++)
	{
		if (temp.singername == mysong[i].singername && temp.songname == mysong[i].songname)
		{
			cout << "�Ѿ�����һ�׸��ˣ�����������һ��" << endl;
			Sleep(1500);
			return 0;
		}
	}
	mysong.push_back(temp);
	cout << "������ӳɹ����ڷ�����һ��" << endl;
	Sleep(2000);
	return 0;
}

int admin::delete_song()
{
	cout << "����������ɾ���ĸ����ı��" << endl;
	int serielnumber;
	cin >> serielnumber;
	if (serielnumber<1 || serielnumber>mysong.size())
	{
		cout << "���벻�Ϸ�������������һ��" << endl;
		Sleep(2000);
		return 0;
	}
	for (int i(0); i < mysong.size(); i++)
	{
		if (mysong[i].serialnum == serielnumber)
		{
			mysong.erase(mysong.begin() + i);
		}
	}
	for (int i(0); i < mysong.size(); i++)
	{
		mysong[i].serialnum = i + 1;
	}
	cout << "ɾ���ɹ�������" << endl;
	Sleep(2000);
	return 1;
}

int admin::initialsong(song& temp)
{
	temp.judgefrequence = 0;
	temp.playstatus = 0;
	temp.ranknum = 0;
	temp.starnum = 0;
	temp.totalscore = 0;
	temp.playfrequence = 0;
	return 0;
}

int admin::printall(vector<song>& A)
{
	int pagenum(1);
	int maxpage(0);
	int songsize = A.size();
	maxpage = songsize / 5;
	if (maxpage * 5 != songsize)
	{
		maxpage++;
	}
	system("cls");
	system("color f1");
	cout << "���ǵ� " << pagenum << " ҳ" << endl;
	cout << left << setw(10) << "���к�" << "|";
	cout << left << setw(30) << "����" << "|";
	cout << left << setw(30) << "����" << "|";
	cout << left << setw(15) << "����" << "|";
	cout << left << setw(15) << "���Ŵ���" << endl;
	for (int i(-5); i < 0 && (i + pagenum * 5) < songsize; i++)
	{
		song temp = A[i + pagenum * 5];
		printsong(temp);
	}
	cout << endl;
	cout << "���ϻ��·�ҳ����esc�˳����ģʽ" << endl;
	char ch;
	while ((ch = _getch()) != 0x1B)
	{
		if (ch == -32)
		{
			ch = _getch();
			if (ch == 80)
			{
				system("cls");
				system("color f1");
				if (pagenum == maxpage)
				{
					cout << "�Ѿ������һҳ����" << endl;
				}
				else
					pagenum++;
				cout << "���ǵ� " << pagenum << " ҳ" << endl;
				cout << left << setw(10) << "���к�" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(15) << "����" << "|";
				cout << left << setw(15) << "���Ŵ���" << endl;
				for (int i(-5); i < 0 && (i + pagenum * 5) < songsize; i++)
				{
					song temp = A[i + pagenum * 5];
					printsong(temp);
				}
				cout << endl;
				cout << "���ϻ��·�ҳ����esc�˳����ģʽ" << endl;
			}
			if (ch == 72)
			{
				system("cls");
				system("color f1");
				if (pagenum == 1)
				{
					cout << "�Ѿ��ǵ�һҳ����" << endl;
				}
				else
					pagenum--;
				cout << "���ǵ� " << pagenum << " ҳ" << endl;
				cout << left << setw(10) << "���к�" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(15) << "����" << "|";
				cout << left << setw(15) << "���Ŵ���" << endl;
				for (int i(-5); i < 0 && (i + pagenum * 5) < songsize; i++)
				{
					song temp = A[i + pagenum * 5];
					printsong(temp);
				}
				cout << endl;
				cout << "���ϻ��·�ҳ����esc�˳����ģʽ" << endl;
			}
		}
		else
		{
			{
				system("cls");
				system("color f1");
				cout << "���ǵ� " << pagenum << " ҳ" << endl;
				cout << left << setw(10) << "���к�" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(30) << "����" << "|";
				cout << left << setw(15) << "����" << "|";
				cout << left << setw(15) << "���Ŵ���" << endl;
				for (int i(-5); i < 0 && (i + pagenum * 5) < songsize; i++)
				{
					song temp = A[i + pagenum * 5];
					printsong(temp);
				}
				cout << endl;
				cout << "���ϻ��·�ҳ����esc�˳����ģʽ" << endl;
				cout << "**********���Ϸ��İ���************" << endl;
			}
		}
		rewind(stdin);
	}
	return 0;
}

int admin::printsong(song& temp)
{
	cout << left << setw(10) << temp.serialnum << "|";
	cout << left << setw(30) << temp.singername << "|";
	cout << left << setw(30) << temp.songname << "|";
	cout << left << setw(15) << temp.starnum << "|";
	cout << left << setw(15) << temp.playfrequence << "|";
	if (temp.playstatus == 1)
		cout << "--playing" << " ";
	cout << endl;
	return 0;
}

int admin::changepassword()
{
	int legalchange(1);
	while (legalchange)
	{
		cout << "�������µ�����" << endl;
		rewind(stdin);
		string temp;
		cin >> temp;
		if (temp == password)
		{
			cout << "�;�����һ��������������" << endl;
			continue;
		}
		string confirm;
		cout << "��������һ��ȷ������" << endl;
		rewind(stdin);
		cin >> confirm;
		if (temp != confirm)
		{
			cout << "ǰ���������벻һ������������" << endl;
			temp.clear();
			confirm.clear();
			rewind(stdin);
			continue;
		}
		if (!legalpassword(temp))
		{
			cout << "��������벻�Ϸ�" << endl;
			temp.clear();
			confirm.clear();
			rewind(stdin);
			continue;
		}
		cout << "������ĳɹ�������Ϊ����תҳ��" << endl;
		password = temp;
		legalchange = 0;
	}
	Sleep(2000);
	return 1;
}

int admin::sort_song()
{
	system("cls");
	system("color f1");
	printf("\n\n\t\t\t��==============================��\n");
	printf("\t\t\t��                              \n");
	printf("\t\t\t�� 1->���к�����                \n");
	printf("\t\t\t�� 2->��������                   \n");
	printf("\t\t\t�� 3->���Ŵ�������                 \n");
	printf("\t\t\t�� ������ѡ��[ ]                 \n");
	printf("\t\t\t��                              \n");
	printf("\t\t\t��==============================��\n");
	char i;
	int opnum;
	rewind(stdin);
	cin >> i;
	if (i < '1' || i>'3')
	{
		cout << "���벻�Ϸ���������һ��" << endl;
		Sleep(2000);
		return 0;
	}
	opnum = i - '0';
	if (opnum == 1)
	{
		sort(mysong.begin(), mysong.end(), comp_srerial);
		cout << "����������" << endl;
		Sleep(1000);
		realprintall();
		cout << "���ڷ�����һ��" << endl;
		Sleep(1500);
		return 1;
	}
	if (opnum == 2)
	{
		sort(mysong.begin(), mysong.end(), comp_starnum);
		cout << "����������" << endl;
		Sleep(1000);
		realprintall();
		sort(mysong.begin(), mysong.end(), comp_srerial);
		cout << "���ڷ�����һ��" << endl;
		Sleep(1500);
		return 1;
	}
	if (opnum == 3)
	{
		sort(mysong.begin(), mysong.end(), comp_frenum);
		cout << "����������" << endl;
		Sleep(1000);
		realprintall();
		sort(mysong.begin(), mysong.end(), comp_srerial);
		cout << "���ڷ�����һ��" << endl;
		Sleep(1500);
		return 1;
	}
	cout << "���벻�Ϸ���������һ��" << endl;
	Sleep(2000);
	return 0;
}

int admin::legalID(string A)
{
	int legalnum(1);
	if (A.length() > 20)
	{
		return 0;
	}
	for (int i(0); i < A.length(); i++)
	{
		if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z') || (A[i] >= '0' && A[i] <= '9'))
			legalnum = 1;
		else
		{
			legalnum = 0;
			break;
		}
	}
	return legalnum;

}

int admin::legalpassword(string A)
{
	int wordlegalnum(0);
	int numberlegalnum(0);
	if (A.length() > 12)
	{
		return 0;
	}
	for (int i(0); i < A.length(); i++)
	{
		if ((A[i] >= 'a' && A[i] <= 'z') || (A[i] >= 'A' && A[i] <= 'Z'))
		{
			wordlegalnum += 1;
		}
		else
			if ((A[i] >= '0' && A[i] <= '9'))
			{
				numberlegalnum += 1;
			}
	}
	if (numberlegalnum > 0 && wordlegalnum > 0)
	{
		return 1;
	}
	else
		return 0;
}

int admin::realprintall()
{
	printall(mysong);
	char i;
	cout << "�������뷵��" << endl;
	rewind(stdin);
	cin >> i;
	return 0;
}



int ktvsystem::pmainmenu()
{
	while (1)
	{
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t��==============================��\n");
		printf("\t\t\t��                              \n");
		printf("\t\t\t��  1->�û�ֱ��                 \n");
		printf("\t\t\t��  2->����Ա��½               \n");
		printf("\t\t\t��  3->�˳�ϵͳ                \n");
		printf("\t\t\t��  ������ѡ��[]                  \n");
		printf("\t\t\t��                              \n");
		printf("\t\t\t��==============================��\n");
		rewind(stdin);
		char temp;
		cin >> temp;
		rewind(stdin);
		if (temp < '1' || temp>'3')
		{
			cout << "�������,����������" << endl;
			Sleep(1000);
		}
		else
		{
			syoperationnum = temp - '0';
			return syoperationnum;
		}
	}
}

void ktvsystem::run()
{
	initialsys();
	Sleep(1500);
	int opnumtemp = 100;
	while (opnumtemp != 3)
	{
		opnumtemp = pmainmenu();
		if (opnumtemp != 3 && opnumtemp != 1 && opnumtemp != 2)
		{
			cout << "������ˣ�������Ϸ����ַ�������" << endl;
			opnumtemp = 111;
			rewind(stdin);
			continue;
		}
		switch (opnumtemp)
		{
		case 3:cout << "�ټ�����лʹ�ã���ӭ�´�����" << endl; break;
		case 1:B.usmenu(A); break;
		case 2:A.login(); break;
		}
	}
}

int ktvsystem::initialsys()
{
	//��ʼ�����������
	system("cls");
	system("color f1");
	cout << "��ӭʹ�ñ�KTV���ϵͳ     " << endl;
	cout << "��ʼ��ϵͳ�У����Ժ�    " << endl;
	ifstream infile;
	infile.open("ktvsong.txt");
	if (infile.fail())
	{
		cout << "�ļ�����ʧ��!!!" << endl;
		Sleep(2000);
		return 0;
	}
	for (int j(1); !infile.eof(); j++)
	{
		song temp;
		infile >> temp.singername;
		infile >> temp.songname;
		infile >> temp.pinyin;
		temp.judgefrequence = 0;
		temp.playfrequence = 0;
		temp.totalscore = 0;
		if (temp.judgefrequence == 0)
		{
			temp.starnum = 0;
		}
		else
			temp.starnum = temp.totalscore / temp.judgefrequence;
		temp.serialnum = j;
		temp.playstatus = 0;
		temp.starnum = 0;
		temp.ranknum = 0;
		A.mysong.push_back(temp);
	}
	A.mysong.pop_back();
	cout << "��ʼ���ɹ�" << endl;
	return 1;
}



int user::usmenu(admin& A)
{
	system("cls");
	system("color f1");
	printf("\n\n\t\t\t��=====================================��\n");
	printf("\t\t\t��                                   \n");
	printf("\t\t\t�� 1->���                            \n");
	printf("\t\t\t�� 2->�ö�����                        \n");
	printf("\t\t\t�� 3->ɾ������                        \n");
	printf("\t\t\t�� 4->��������                        \n");
	printf("\t\t\t�� 5->�鿴�ѵ����                    \n");
	printf("\t\t\t�� 6->����ѡ��                        \n");
	printf("\t\t\t�� 7->��������                        \n");
	printf("\t\t\t�� 8->�˳�                            \n");
	printf("\t\t\t��                                    \n");
	printf("\t\t\t��=====================================��\n");
	rewind(stdin);
	int adnumtemp = 100;
	while (1)
	{
		char temp;
		rewind(stdin);
		cin >> temp;
		if (temp < '0' || temp>'8')
		{
			adnumtemp = 100;
		}
		else
			adnumtemp = temp - '0';
		switch (adnumtemp)
		{
		case 1:ordersong(A); break;
		case 2:make_song_top(A); break;
		case 3:delete_song_inqueue(A); break;
		case 4:judge_song(A); break;
		case 5:realsee_playingqueue(A); break;
		case 6:change_song(A); break;
		case 7:search_song(A); break;
		case 8:cout << "�ټ�" << endl; return 0;
		default:cout << "������������������" << endl; Sleep(1000);
		}
		system("cls");
		system("color f1");
		printf("\n\n\t\t\t��=====================================��\n");
		printf("\t\t\t��                                    \n");
		printf("\t\t\t�� 1->���                            \n");
		printf("\t\t\t�� 2->�ö�����                        \n");
		printf("\t\t\t�� 3->ɾ������                        \n");
		printf("\t\t\t�� 4->��������                        \n");
		printf("\t\t\t�� 5->�鿴�ѵ����                    \n");
		printf("\t\t\t�� 6->����ѡ��                        \n");
		printf("\t\t\t�� 7->��������                        \n");
		printf("\t\t\t�� 8->�˳�                            \n");
		printf("\t\t\t��                                    \n");
		printf("\t\t\t��=====================================��\n");
		rewind(stdin);
	}
	return 1;
}

int user::ordersong(admin& A)
{
	while (1)
	{
		system("cls");
		system("color f1");
		A.printall(A.mysong);
		cout << "���������ĸ����ı��" << endl;
		int i(0);
		rewind(stdin);
		cin >> i;
		if (i<1 || i>A.mysong.size())
		{
			cout << "����ĺ��벻�Ϸ���������һ��" << endl;
			Sleep(2000);
			return 0;
		}
		for (int j(0); j < playing_queue.size(); j++)
		{
			if (playing_queue[j] == i)
			{
				cout << "�赥�����Ѿ�����һ�׸���,׼��������һ��" << endl;
				Sleep(2000);
				return 0;
			}
		}
		if (i != -1)
		{
			playing_queue.push_back(i);
			cout << "��ӳɹ�" << endl;
		}
		cout << "������裿����1����������������" << endl;
		char nextop;
		rewind(stdin);
		cin >> nextop;
		if (nextop == '1');
		else
			return 1;
	}

}

int user::make_song_top(admin& A)
{
	system("cls");
	system("color f1");
	see_playingqueue(A);
	if (playing_queue.size() == 0)
	{
		Sleep(1000);
		return 0;
	}
	cout << "���������ö��ĸ����ı��" << endl;
	int i(0);
	rewind(stdin);
	cin >> i;
	if (i<1 || i>A.mysong.size())
	{
		cout << "û�����׸裬������һ��" << endl;
		Sleep(2000);
		return 0;
	}
	playing_queue.insert(playing_queue.begin(), i);
	vector<int>::iterator it;
	for (it = playing_queue.begin() + 1; it != playing_queue.end(); )
	{
		if (*it == i)
		{
			it = playing_queue.erase(it);
		}
		else
		{
			++it;
		}
	}
	cout << "�ö��ɹ������ڷ�����һ��" << endl;
	Sleep(2000);
	return 0;
}

int user::delete_song_inqueue(admin& A)
{
	system("cls");
	system("color f1");
	see_playingqueue(A);
	if (playing_queue.size() == 0)
	{
		cout << "���ڷ�����һ��" << endl;
		Sleep(1000);
		return 0;
	}
	cout << "��������ɾ���ĸ�ı��" << endl;
	int number;
	rewind(stdin);
	cin >> number;
	if (number < 1)
	{
		cout << "�������󣬽��᷵����һ��" << endl;
		Sleep(2000);
		return 0;
	}
	vector<int>::iterator it;
	int flag = 0;
	for (it = playing_queue.begin(); it != playing_queue.end(); )
	{
		if (*it == number)
		{
			it = playing_queue.erase(it);
			flag = 1;
		}
		else
		{
			++it;
		}
	}
	if (flag == 1)
	{
		cout << "ɾ���ɹ�,���ڷ�����һ��" << endl;
	}
	else
	{
		cout << "û����һ�׸�" << endl;
	}
	Sleep(2000);
	return 0;
}

int user::judge_song(admin& A)
{
	double star;
	int IDnum;
	system("cls");
	system("color f1");
	A.printall(A.mysong);
	cout << "������Ҫ���ֵĸ�����Ӧ��ID��" << endl;
	rewind(stdin);
	cin >> IDnum;
	if (IDnum<1 || IDnum>A.mysong.size())
	{
		cout << "�������󣬷��ص���һ��" << endl;
		Sleep(2000);
		return 0;
	}
	cout << "����������֣�����1-5��" << endl;
	rewind(stdin);
	cin >> star;

	if (star < 1 || star>5)
	{
		cout << "�������󣬷��ص���һ��" << endl;
		Sleep(2000);
		return 0;
	}
	A.mysong[IDnum - 1].totalscore += star;
	A.mysong[IDnum - 1].judgefrequence += 1;
	A.mysong[IDnum - 1].starnum = A.mysong[IDnum - 1].totalscore / A.mysong[IDnum - 1].judgefrequence;
	cout << "���ֳɹ������ڷ�����һ��" << endl;
	Sleep(2000);
	return 1;
}

int user::see_playingqueue(admin& A)
{
	if (playing_queue.size() == 0)
	{
		cout << "�տ���Ҳ�ĸ赥����ȥ�������ԣ�" << endl;
		Sleep(1000);
		return 0;
	}
	vector<song>result;
	for (int i(0); i < playing_queue.size(); i++)
	{
		result.push_back(A.mysong[playing_queue[i] - 1]);
	}
	A.printall(result);
	return 0;
}

int user::realsee_playingqueue(admin& A)
{
	see_playingqueue(A);
	char i;
	cout << "�����������ַ���" << endl;
	rewind(stdin);
	cin >> i;
	return 0;
}

int user::change_song(admin& A)
{
	system("cls");
	system("color f1");
	see_playingqueue(A);
	if (playing_queue.size() == 0)
	{
		cout << "׼��������һ��" << endl;
		Sleep(2000);
		return 0;
	}
	cout << "���������뿪ʼ���ŵĸ����ı��" << endl;
	int number;
	rewind(stdin);
	cin >> number;
	if (number < 1)
	{
		cout << "���������⣬׼���ص���һ��" << endl;
		Sleep(2000);
		return 1;
	}
	for (int i(0); i < playing_queue.size(); i++)
	{
		if (number == playing_queue[i])
		{
			A.mysong[number - 1].playstatus = 1;
			A.mysong[number - 1].playfrequence++;
			for (int i(0); i < playing_queue.size(); i++)
			{
				if (playing_queue[i] == number)
					continue;
				A.mysong[playing_queue[i] - 1].playstatus = 0;
			}
			cout << "�и�ɹ���׼��������һ��" << endl;
			Sleep(2000);
			return 0;
		}
	}
	cout << "�����б�û�����ף�׼��������һ��" << endl;
	Sleep(2000);
	return 0;

}

int user::search_song(admin& A)
{
	system("cls");
	system("color f1");
	printf("\n\n\t\t\t��==============================��\n");
	printf("\t\t\t�� ��\n");
	printf("\t\t\t�� 1->��������                      \n");
	printf("\t\t\t�� 2->��������                      \n");
	printf("\t\t\t�� 3->ƴ������                      \n");
	printf("\t\t\t�� ������ѡ��[ ]                    \n");
	printf("\t\t\t�� ��\n");
	printf("\t\t\t\t\t��==============================��\n");
	vector<song>result;
	string temp;
	int i(0);
	rewind(stdin);
	cin >> i;
	if (i == 1)
	{
		cout << "������Ҷ���ĸ���" << endl;
		rewind(stdin);
		cin >> temp;
		for (int i(0); i < A.mysong.size(); i++)
		{
			if (A.mysong[i].songname == temp)
			{
				result.push_back(A.mysong[i]);
			}
		}
		if (result.size() == 0)
		{
			cout << "û���ҵ�,������һ��" << endl;
			Sleep(1500);
			return 0;
		}
		A.printall(result);
		cout << "����1���,����������" << endl;
		rewind(stdin);
		char s;
		cin >> s;
		if (s == '1')
		{
			while (1)
			{
				cout << "���������ĸ����ı��" << endl;
				int i(0);
				rewind(stdin);
				cin >> i;
				if (i<1 || i>A.mysong.size())
				{
					cout << "����ĺ��벻�Ϸ���������һ��" << endl;
					Sleep(2000);
					return 0;
				}
				for (int j(0); j < playing_queue.size(); j++)
				{
					if (playing_queue[j] == i)
					{
						cout << "�赥�����Ѿ�����һ�׸���,׼��������һ��" << endl;
						Sleep(2000);
						return 0;
					}
				}
				if (i != -1)
				{
					playing_queue.push_back(i);
					cout << "��ӳɹ�" << endl;
				}
				cout << "������裿����1����������������" << endl;
				char nextop;
				rewind(stdin);
				cin >> nextop;
				if (nextop == '1');
				else
					return 1;
			}
		}
		return 0;
	}
	if (i == 2)
	{
		cout << "������Ҷ���ĸ�����" << endl;
		rewind(stdin);
		cin >> temp;
		for (int i(0); i < A.mysong.size(); i++)
		{
			if (A.mysong[i].singername == temp)
			{
				result.push_back(A.mysong[i]);
			}
		}
		if (result.size() == 0)
		{
			cout << "û���ҵ�,������һ��" << endl;
			Sleep(1500);
			return 0;
		}
		A.printall(result);
		cout << "����1���,����������" << endl;
		rewind(stdin);
		char s;
		cin >> s;
		if (s == '1')
		{
			while (1)
			{
				cout << "���������ĸ����ı��" << endl;
				int i(0);
				rewind(stdin);
				cin >> i;
				if (i<1 || i>A.mysong.size())
				{
					cout << "����ĺ��벻�Ϸ���������һ��" << endl;
					Sleep(2000);
					return 0;
				}
				for (int j(0); j < playing_queue.size(); j++)
				{
					if (playing_queue[j] == i)
					{
						cout << "�赥�����Ѿ�����һ�׸���,׼��������һ��" << endl;
						Sleep(2000);
						return 0;
					}
				}
				if (i != -1)
				{
					playing_queue.push_back(i);
					cout << "��ӳɹ�" << endl;
				}
				cout << "������裿����1����������������" << endl;
				char nextop;
				rewind(stdin);
				cin >> nextop;
				if (nextop == '1');
				else
					return 1;
			}
		}
		return 0;
	}
	if (i == 3)
	{
		cout << "������Ҷ����ƴ����" << endl;
		rewind(stdin);
		cin >> temp;
		for (int i(0); i < A.mysong.size(); i++)
		{
			if (A.mysong[i].pinyin == temp)
			{
				result.push_back(A.mysong[i]);
			}
		}
		if (result.size() == 0)
		{
			cout << "û���ҵ�,������һ��" << endl;
			Sleep(1500);
			return 0;
		}
		A.printall(result);
		cout << "����1���,����������" << endl;
		rewind(stdin);
		char s;
		cin >> s;
		if (s == '1')
		{
			while (1)
			{
				cout << "���������ĸ����ı��" << endl;
				int i(0);
				rewind(stdin);
				cin >> i;
				if (i<1 || i>A.mysong.size())
				{
					cout << "����ĺ��벻�Ϸ���������һ��" << endl;
					Sleep(2000);
					return 0;
				}
				for (int j(0); j < playing_queue.size(); j++)
				{
					if (playing_queue[j] == i)
					{
						cout << "�赥�����Ѿ�����һ�׸���,׼��������һ��" << endl;
						Sleep(2000);
						return 0;
					}
				}
				if (i != -1)
				{
					playing_queue.push_back(i);
					cout << "��ӳɹ�" << endl;
				}
				cout << "������裿����1����������������" << endl;
				char nextop;
				rewind(stdin);
				cin >> nextop;
				if (nextop == '1');
				else
					return 1;
			}
		}
		return 0;
	}
	cout << "���벻�Ϸ�" << endl;
	return 0;
}
