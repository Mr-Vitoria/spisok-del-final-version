#include <iostream>
#include<Windows.h>
#include<string.h>
#include <cstdlib>
using namespace std;
struct Del
{
	enum dayOfWeek { MON=1,THU,WEN,THUS,FRI,SAT,SUN=0 };
	string name;
	string opis;
	string prior;
	int year;
	int mes;
	int den;
	int hh;
	int mm;
	int nedela;
};
Del* delo = 0;
string resh, resh2;
string vihod = "���";
int razm = 0;
int nomer;
int temp = 0;
Del* tempm = new Del[1];
Del* tdelo = new Del[1];
Del* Addstr(Del* delo, const int& razm)
{
	if (razm == 0)
	{
		delo = new Del[razm + 1];
	}
	else
	{
		Del* tempdelo = new Del[razm + 1];
		for (int i = 0; i < razm; i++)
		{
			tempdelo[i] = delo[i];
		}
		delete[]delo;
		delo = tempdelo;
	}
	return delo;
}
int setnedela(Del* delo, const int razm)
{
	int tempnedela;
	int tyear;
	int tmes;
	if (delo[razm].mes == 1 || delo[razm].mes == 2)
	{
		tyear = delo[razm].year - 1;
		tmes = delo[razm].mes + 10;
		tempnedela = (delo[razm].den + ((31 * tmes) / 12) + tyear + (tyear / 4) - (tyear / 100) + (tyear / 400)) % 7;
	}
	else
	{
		tmes = delo[razm].mes - 2;
		tempnedela = (delo[razm].den + ((31 * tmes) / 12) + delo[razm].year + (delo[razm].year / 4) - (delo[razm].year / 100) + (delo[razm].year / 400)) % 7;
	}
	if (tempnedela == 1)
	{
		return delo[razm].MON;
	}
	else if (tempnedela == 2)
	{
		return delo[razm].THU;
	}
	else if (tempnedela == 3)
	{
		return delo[razm].WEN;
	}
	else if (tempnedela == 4)
	{
		return delo[razm].THUS;
	}
	else if (tempnedela == 5)
	{
		return delo[razm].FRI;
	}
	else if (tempnedela == 6)
	{
		return delo[razm].SAT;
	}
	else if (tempnedela == 0)
	{
		return delo[razm].SUN;
	}
}
void setvrema(Del* delo, const int& razm)
{
	while (true)
	{
		cout << "\n������� ����(������� ����,����� ������)\n";
		cin >> delo[razm].hh;
		if (delo[razm].hh >= 24)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\n������� ������\n";
		cin >> delo[razm].mm;
		if (delo[razm].mm >= 60)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else
		{
			break;
		}
	}

}
void setdata(Del* delo, const int& razm)
{
	while (true)
	{
		cout << "\n������� ��� ����\n";
		cin >> delo[razm].year;
		if (delo[razm].year <= 1582)
		{
			cout << "\n���������� ������� ��� �� 1583\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\n������� ����� ����\n(1-������,2-�������,3-����,4-������,5-���,6-����,7-����,8-������,9-��������,10-�������,11-������,12-�������)\n";
		cin >> delo[razm].mes;
		if (delo[razm].mes < 1 || delo[razm].mes > 12)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\n������� ���� ��� ����\n";
		cin >> delo[razm].den;
		if (delo[razm].mes % 2 != 0 && delo[razm].den > 31)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else if (delo[razm].mes % 2 == 0 && delo[razm].den > 30 && delo[razm].mes != 2)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else if (delo[razm].mes == 2 && delo[razm].year % 4 == 0 && delo[razm].den > 29)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else if (delo[razm].mes == 2 && delo[razm].year % 4 != 0 && delo[razm].den > 28)
		{
			cout << "\n����������,���������� ��� ���\n";
		}
		else
		{
			break;
		}
	}
	delo[razm].nedela = setnedela(delo, razm);
}
void setprior(Del* delo, const int& razm)
{
	while (true)
	{
		cout << "\n������� ��������� ����\n1.�������\n2.����������\n3.������\n";
		cin >> delo[razm].prior;
		if (delo[razm].prior == "�������" || delo[razm].prior == "����������" || delo[razm].prior == "������")
		{
			break;
		}
		else
		{
			cout << "\n����������,���������� ��� ���\n";
		}
	}
}
void setDelo(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "\n������� �������� ����\n";
	cin >> delo[razm].name;
	setprior(delo, razm);
	cout << "\n������� �������� ����(�������,���'_')\n";
	cin >> delo[razm].opis;
	setdata(delo, razm);
	setvrema(delo,razm);
}
void otobrdela(Del* delo, int i)
{
	cout << "\n��� ����: " << delo[i].name;
	cout << "\n�������� ����: " << delo[i].opis;
	cout << "\n��������� ����: " << delo[i].prior;
	cout << "\n���� ����: " << delo[i].year;
	cout << "." << delo[i].mes;
	cout << "." << delo[i].den;
	cout << "\n����� : " << delo[i].hh;
	cout << ":" << delo[i].mm;
	cout << endl;
}
void nedela(Del* delo,const int razm)
{
	cout << "\n������� ���� ��� �� ������,������� ����� ����������\n";
	cout << "\n������� ��� ����\n";
	cin >> tdelo[1].year;
	cout << "\n������� ����� ����\n(1-������,2-�������,3-����,4-������,5-���,6-����,7-����,8-������,9-��������,10-�������,11-������,12-�������)\n";
	cin >> tdelo[1].mes;
	cout << "\n������� ���� ��� ����\n";
	cin >> tdelo[1].den;
	tdelo[1].nedela = setnedela(tdelo, 1);
	if (tdelo[1].nedela == 1)
	{
		for (int j = 0;j < razm;j++)
		{
			for (int i = 0;i <= 7;i++)
			{
				if (tdelo[1].year == delo[j].year && delo[j].mes == tdelo[1].mes && delo[j].den == tdelo[1].den + i)
				{
					otobrdela(delo, j);
				}
			}
		}
	}
	else
	{
		for (int j = 0;j < razm;j++)
		{
			for (int i = tdelo[1].nedela;i <= 7;i++)
			{
				if (tdelo[1].year == delo[j].year && delo[j].mes == tdelo[1].mes && delo[j].den == tdelo[1].den + i)
				{
					otobrdela(delo, j);
				}
			}
		}
		for (int j = 0;j < razm;j++)
		{
			for (int i = tdelo[1].nedela;i > 0;i--)
			{
				if (tdelo[1].year == delo[j].year && delo[j].mes == tdelo[1].mes && delo[j].den == tdelo[1].den - i)
				{
					otobrdela(delo, j);
				}
			}
		}
	}
}
void otobr(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	int resh3=0;
	cout << "��� �� ������ ����������\n1-��� ����\n2-���� �� ������\n3-���� �� �����\n4-���� �� ����\n";
	cin >> resh;
	cout << "������ ��� ���� �������������?(�� ��� ���)\n";
	cin >> resh2;
	if (resh2 == "���")
	{
		if (resh == "1")
		{
			for (int i = 0; i < razm; i++)
			{
				otobrdela(delo, i);
			}
		}
		else if (resh == "4")
		{
			cout << "\n������� ���� ���������� ����\n";
			cin >> nomer;
			for (int i = 0; i < razm; i++)
			{
				if (delo[i].den == nomer)
				{
					otobrdela(delo, i);
				}
			}
		}
		else if (resh == "2")
		{
			nedela(delo,razm);
		}
		else if (resh == "3")
		{
			cout << "\n������� �����:\n1-������\n2-�������\n3-����\n4-������\n5-���\n6-����\n7-����\n8-������\n9-��������\n10-�������\n11-������\n12-�������\n";
			cin >> resh;
			for (int i = 0; i < razm; i++)
			{
				if (resh3 == delo[i].mes)
				{
					otobrdela(delo, i);
				}
			}
		}
	}
	else if (resh2 == "��")
	{
		cout << "\n��� �� ������ �������������?\n1-�� ����������\n2-�� ���� � ������� ����������\n";
		cin >> resh2;
		if (resh2 == "1")
		{
			if (resh == "1")
			{
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "�������")
					{
						otobrdela(delo, i);
					}

				}
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "����������")
					{
						otobrdela(delo, i);
					}

				}
				cout << "\n������ ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "������")
					{
						otobrdela(delo, i);
					}

				}
			}
			else if (resh == "4")
			{
				cout << "\n������� ���� ���������� ����\n";
				cin >> nomer;
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\n������� ���������:";
					if (delo[i].den == nomer && delo[i].prior == "�������")
					{
						otobrdela(delo, i);
					}
				}
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\n ������� ���������:";
					if (delo[i].den == nomer && delo[i].prior == "����������")
					{
						otobrdela(delo, i);
					}
				}
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\n������ ���������:";
					if (delo[i].den == nomer && delo[i].prior == "������")
					{
						otobrdela(delo, i);
					}
				}
			}
			else if (resh == "2")
			{
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "�������")
					{
						nedela(delo,razm);
					}
				}
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "����������")
					{
						nedela(delo,razm);
					}
				}
				cout << "\n������ ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "������")
					{
						nedela(delo,razm);
					}
				}
			}
			else if (resh == "3")
			{
				cout << "\n������� �����:\n1-������\n2-�������\n3-����\n4-������\n5-���\n6-����\n7-����\n8-������\n9-��������\n10-�������\n11-������\n12-�������\n";
				cin >> resh;
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "�������")
					{
						otobrdela(delo, i);
					}
				}
				cout << "\n������� ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "����������")
					{
						otobrdela(delo, i);
					}
				}
				cout << "\n������ ���������\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "������")
					{
						otobrdela(delo, i);
					}
				}
			}
		}
		else if (resh2 == "2")
		{

			for (int i = 0; i < razm - 1; i++)
			{
				if (delo[i].year > delo[i + 1].year)
				{
					tempm[0] = delo[i];
					delo[i] = delo[i + 1];
					delo[i + 1] = tempm[0];
				}
				else if (delo[i].year == delo[i + 1].year && delo[i].mes > delo[i + 1].mes)
				{
					tempm[0] = delo[i];
					delo[i] = delo[i + 1];
					delo[i + 1] = tempm[0];
				}
				else if (delo[i].year == delo[i + 1].year && delo[i].mes == delo[i + 1].mes && delo[i].den > delo[i + 1].den)
				{
					tempm[0] = delo[i];
					delo[i] = delo[i + 1];
					delo[i + 1] = tempm[0];
				}
				else if (delo[i].year == delo[i + 1].year && delo[i].mes == delo[i + 1].mes && delo[i].den == delo[i + 1].den && delo[i].hh > delo[i + 1].hh)
				{
					tempm[0] = delo[i];
					delo[i] = delo[i + 1];
					delo[i + 1] = tempm[0];
				}
				else if (delo[i].year == delo[i + 1].year && delo[i].mes == delo[i + 1].mes && delo[i].den == delo[i + 1].den && delo[i].hh == delo[i + 1].hh && delo[i].mm > delo[i + 1].mm)
				{
					tempm[0] = delo[i];
					delo[i] = delo[i + 1];
					delo[i + 1] = tempm[0];
				}
			}
			if (resh == "1")
			{
				for (int i = 0; i < razm; i++)
				{
					otobrdela(delo, i);
				}
			}
			else if (resh == "4")
			{
				cout << "\n������� ���� ���������� ����\n";
				cin >> nomer;
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].den == nomer)
					{
						otobrdela(delo, i);
					}
				}
			}
			else if (resh == "2")
			{
				nedela(delo,razm);
			}
			else if (resh == "3")
			{
				cout << "\n������� �����(������� ����� ����������):\n1-������\n2-�������\n3-����\n4.������\n5-���\n6-����\n7-����\n8-������\n9-��������\n10-�������\n11-������\n12-�������\n";
				cin >> resh3;
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes)
					{
						otobrdela(delo, i);
					}
				}
			}
		}

	}
}
void udal(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	while (true)
	{
		cout << "\n����� ���� ������ �������?\n";
		cin >> nomer;
		if (nomer > 0 && nomer <= razm+1)
		{
			break;
		}
		else
		{
			cout << "\n������,���������� ��� ���!\n";
		}
	}
	Del* tempdelo2 = new Del[razm];
	for (int i = 0; i < razm; i++)
	{
		if (i != nomer - 1)
		{
			tempdelo2[i] = delo[temp];
			temp++;
		}
		else
		{
			temp++;
			tempdelo2[i] = delo[temp];
			temp++;
		}
	}
	delo = tempdelo2;
	temp = 0;
}
void nesetdelo(Del* delo, int nomer)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "\n������� ����� �������� ����\n";
	cin >> delo[nomer-1].name;
	cout << "\n������� ����� ��������� ����\n1.�������\n2.����������\n3.������\n";
	cin >> delo[nomer-1].prior;
	cout << "\n������� �������� ����(�������,���'_')\n";
	cin >> delo[nomer-1].opis;
	cout << "\n������� ��� ����\n";
	cin >> delo[nomer-1].year;
	cout << "\n������� ����� ����\n";
	cin >> delo[nomer-1].mes;
	cout << "\n������� ���� ��� ����\n";
	cin >> delo[nomer-1].den;
	cout << "\n������� ����\n";
	cin >> delo[nomer-1].hh;
	cout << "\n������� ������\n";
	cin >> delo[nomer-1].mm;
}
void redact(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	resh = "���";
	while (resh == "���")
	{
		while (true)
		{
			cout << "\n����� ���� ������ �������������?\n";
			cin >> nomer;
			if (nomer > 0 && nomer <= razm + 1)
			{
				break;
			}
			else
			{
				cout << "\n������,���������� ��� ���!\n";
			}
		}
		nomer--;
		while (true)
		{
			cout << "\n�� ������ ������������� �� ����,��� ��� �����\n1-���� ��\n2-���� �����\n";
			cin >> resh;
			if (resh == "1")
			{
				setDelo(delo, nomer);
				break;
			}
			else if (resh == "2")
			{
				
				cout << "\n��� ������ �������������?\n1-��������,2-���������,3-��������,4-����,5-�����\n";
				cin >> resh;
				if (resh == "1")
				{
					cout << "\n������� ����� �������� ����\n";
					cin >> delo[nomer ].name;
				}
				else if (resh == "2")
				{
					setprior(delo, nomer);
				}
				else if (resh == "3")
				{
					cout << "\n������� ����� �������� ����(�������,���'_')\n";
					cin >> delo[nomer ].opis;
				}
				else if (resh == "4")
				{
					setdata(delo, nomer);
				}
				else if (resh == "5")
				{
					setvrema(delo, nomer);
				}
				cout << "\n�� ��������� ��������������?\n";
				cin >> resh;
				break;
			}
			else
			{
				cout << "\n������,���������� ��� ���";
			}
		}
	}
}
void poisk(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "\n����� �� ������ ����������� �����?\n1-�� ��������\n2-�� ����������\n3-�� ��������\n4-�� ���� � ������� ����������\n";
	cin >> resh;
	if (resh == "1")
	{
		cout << "\n������� ��������:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].name == resh)
			{
				cout << "\n������� ����������!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "2")
	{
		cout << "\n������� ���������:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].prior == resh)
			{
				cout << "\n������� ����������!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "3")
	{
		cout << "\n������� ��������:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].opis == resh)
			{
				cout << "\n������� ����������!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "4")
	{
		int god, den, hh, mm;
		int mes;
		cout << "\n������� ���:\n";
		cin >> god;
		cout << "\n������� �����:\n";
		cin >> mes;
		cout << "\n������� ����:\n";
		cin >> den;
		cout << "\n������� ����:\n";
		cin >> hh;
		cout << "\n������� ������:\n";
		cin >> mm;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].year == god && delo[i].mes == mes && delo[i].den == den && delo[i].hh == hh && delo[i].mm == mm)
			{
				cout << "\n������� ����������!\n";
				otobrdela(delo, i);
			}
		}
	}
}
void menu3()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                                    ������ ���                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              ��� �� ������ �������:                                               **\n";
	cout << "**��� �� ������ �������?                                                                                             **\n";
	cout << "**1-�������� ����� ����                                                                                              **\n";
	cout << "**2-���������� ��� ����                                                                                              **\n";
	cout << "**3-�������� ���                                                                                                     **\n";
	cout << "**4-��������������                                                                                                   **\n";
	cout << "**5-����������� ����� ���                                                                                            **\n";
	cout << "**6-�����                                                                                                            **\n";
	for (int i = 0; i < 6; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";

}
void menu2()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                                    ������ ���                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              ��� ��������� �����:                                                 **\n";
	cout << "**                                                                                                                   **\n";
	cout << "**                                                                                                                   **\n";
	cout << "**1.��������� ����                                                                                                   **\n";
	cout << "**2.������� ����                                                                                                     **\n";
	cout << "**3.������������� ����                                                                                               **\n";
	cout << "**4.������������ �����                                                                                               **\n";
	cout << "**5.����������� ��� � �� �����������                                                                                 **\n";
	for (int i = 0; i < 6; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	Sleep(5000);
}
void menu1()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                                    ������ ���                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              ������ �����������!                                                  **\n";
	cout << "**��� ��������� ���������� �� ��, ��� �� ������ ������� ��� ���� ������� �������(����� ������� �� ��� ���)           **\n";
	for (int i = 0; i < 8; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                     ����� ��� ������ ��������� �����������!                                       **\n";
	cout << "**                                     ����� ��� ������ ��������� �����������!                                       **\n";
	cout << "**                                     ����� ��� ������ ��������� �����������!                                       **\n";
	cout << "**                                     ����� ��� ������ ��������� �����������!                                       **\n";
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	Sleep(5000);
	system("cls");
}