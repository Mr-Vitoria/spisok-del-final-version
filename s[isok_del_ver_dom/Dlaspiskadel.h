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
string vihod = "нет";
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
		cout << "\nВведите часы(сначала часы,потом минуты)\n";
		cin >> delo[razm].hh;
		if (delo[razm].hh >= 24)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\nВведите минуты\n";
		cin >> delo[razm].mm;
		if (delo[razm].mm >= 60)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
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
		cout << "\nВведите год дела\n";
		cin >> delo[razm].year;
		if (delo[razm].year <= 1582)
		{
			cout << "\nПожалуйста введите год от 1583\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\nВведите месяц дела\n(1-Январь,2-Февраль,3-Март,4-Апрель,5-Май,6-Июнь,7-Июль,8-Август,9-Сентябрь,10-Октябрь,11-Ноябрь,12-Декабрь)\n";
		cin >> delo[razm].mes;
		if (delo[razm].mes < 1 || delo[razm].mes > 12)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
		else
		{
			break;
		}
	}
	while (true)
	{
		cout << "\nВведите день для дела\n";
		cin >> delo[razm].den;
		if (delo[razm].mes % 2 != 0 && delo[razm].den > 31)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
		else if (delo[razm].mes % 2 == 0 && delo[razm].den > 30 && delo[razm].mes != 2)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
		else if (delo[razm].mes == 2 && delo[razm].year % 4 == 0 && delo[razm].den > 29)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
		else if (delo[razm].mes == 2 && delo[razm].year % 4 != 0 && delo[razm].den > 28)
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
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
		cout << "\nВведите приоритет дела\n1.высокий\n2.нормальный\n3.низкий\n";
		cin >> delo[razm].prior;
		if (delo[razm].prior == "высокий" || delo[razm].prior == "нормальный" || delo[razm].prior == "низкий")
		{
			break;
		}
		else
		{
			cout << "\nПожалуйста,попробуйте ещё раз\n";
		}
	}
}
void setDelo(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "\nВведите название дела\n";
	cin >> delo[razm].name;
	setprior(delo, razm);
	cout << "\nВведите описание дела(пробелы,как'_')\n";
	cin >> delo[razm].opis;
	setdata(delo, razm);
	setvrema(delo,razm);
}
void otobrdela(Del* delo, int i)
{
	cout << "\nИмя дела: " << delo[i].name;
	cout << "\nОписание дела: " << delo[i].opis;
	cout << "\nПриоритет дела: " << delo[i].prior;
	cout << "\nДата дела: " << delo[i].year;
	cout << "." << delo[i].mes;
	cout << "." << delo[i].den;
	cout << "\nВремя : " << delo[i].hh;
	cout << ":" << delo[i].mm;
	cout << endl;
}
void nedela(Del* delo,const int razm)
{
	cout << "\nВведите дата дня на неделе,которую нужно отобразить\n";
	cout << "\nВведите год дела\n";
	cin >> tdelo[1].year;
	cout << "\nВведите месяц дела\n(1-Январь,2-Февраль,3-Март,4-Апрель,5-Май,6-Июнь,7-Июль,8-Август,9-Сентябрь,10-Октябрь,11-Ноябрь,12-Декабрь)\n";
	cin >> tdelo[1].mes;
	cout << "\nВведите день для дела\n";
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
	cout << "Как вы хотите отобразить\n1-Все дела\n2-Дела на неделю\n3-Дела на месяц\n4-Дела на день\n";
	cin >> resh;
	cout << "Хотите при этом отсортировать?(да или нет)\n";
	cin >> resh2;
	if (resh2 == "нет")
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
			cout << "\nВведите день выполнения дела\n";
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
			cout << "\nВведите месяц:\n1-Январь\n2-Февраль\n3-Март\n4-Апрель\n5-Май\n6-Июнь\n7-Июль\n8-Август\n9-Сентябрь\n10-Октябрь\n11-Ноябрь\n12-Декабрь\n";
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
	else if (resh2 == "да")
	{
		cout << "\nКак вы хотите отсортировать?\n1-по приоритету\n2-по дате и времени исполнения\n";
		cin >> resh2;
		if (resh2 == "1")
		{
			if (resh == "1")
			{
				cout << "\nВысокий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "высокий")
					{
						otobrdela(delo, i);
					}

				}
				cout << "\nСредний приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "нормальный")
					{
						otobrdela(delo, i);
					}

				}
				cout << "\nНизкий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "низкий")
					{
						otobrdela(delo, i);
					}

				}
			}
			else if (resh == "4")
			{
				cout << "\nВведите день выполнения дела\n";
				cin >> nomer;
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\nВысокий приоритет:";
					if (delo[i].den == nomer && delo[i].prior == "высокий")
					{
						otobrdela(delo, i);
					}
				}
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\n Средний приоритет:";
					if (delo[i].den == nomer && delo[i].prior == "нормальный")
					{
						otobrdela(delo, i);
					}
				}
				for (int i = 0; i < razm; i++)
				{
					cout << "\n\n\n\n\n\n\n\nНизкий приоритет:";
					if (delo[i].den == nomer && delo[i].prior == "низкий")
					{
						otobrdela(delo, i);
					}
				}
			}
			else if (resh == "2")
			{
				cout << "\nВысокий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "высокий")
					{
						nedela(delo,razm);
					}
				}
				cout << "\nСредний приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "нормальный")
					{
						nedela(delo,razm);
					}
				}
				cout << "\nНизкий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (delo[i].prior == "низкий")
					{
						nedela(delo,razm);
					}
				}
			}
			else if (resh == "3")
			{
				cout << "\nВведите месяц:\n1-Январь\n2-Февраль\n3-Март\n4-Апрель\n5-Май\n6-Июнь\n7-Июль\n8-Август\n9-Сентябрь\n10-Октябрь\n11-Ноябрь\n12-Декабрь\n";
				cin >> resh;
				cout << "\nВысокий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "высокий")
					{
						otobrdela(delo, i);
					}
				}
				cout << "\nСредний приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "нормальный")
					{
						otobrdela(delo, i);
					}
				}
				cout << "\nНизкий приоритет\n";
				for (int i = 0; i < razm; i++)
				{
					if (resh3 == delo[i].mes && delo[i].prior == "низкий")
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
				cout << "\nВведите день выполнения дела\n";
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
				cout << "\nВведите месяц(который нужно отобразить):\n1-Январь\n2-Февраль\n3-Март\n4.Апрель\n5-Май\n6-Июнь\n7-Июль\n8-Август\n9-Сентябрь\n10-Октябрь\n11-Ноябрь\n12-Декабрь\n";
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
		cout << "\nКакое дело хотите удалить?\n";
		cin >> nomer;
		if (nomer > 0 && nomer <= razm+1)
		{
			break;
		}
		else
		{
			cout << "\nОшибка,попробуйте ещё раз!\n";
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
	cout << "\nВведите новое название дела\n";
	cin >> delo[nomer-1].name;
	cout << "\nВведите новый приоритет дела\n1.Высокий\n2.нормальный\n3.низкий\n";
	cin >> delo[nomer-1].prior;
	cout << "\nВведите описание дела(пробелы,как'_')\n";
	cin >> delo[nomer-1].opis;
	cout << "\nВведите год дела\n";
	cin >> delo[nomer-1].year;
	cout << "\nВведите месяц дела\n";
	cin >> delo[nomer-1].mes;
	cout << "\nВведите день для дела\n";
	cin >> delo[nomer-1].den;
	cout << "\nВведите часы\n";
	cin >> delo[nomer-1].hh;
	cout << "\nВведите минуты\n";
	cin >> delo[nomer-1].mm;
}
void redact(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	resh = "нет";
	while (resh == "нет")
	{
		while (true)
		{
			cout << "\nКакое дело хотите редактировать?\n";
			cin >> nomer;
			if (nomer > 0 && nomer <= razm + 1)
			{
				break;
			}
			else
			{
				cout << "\nОшибка,попробуйте ещё раз!\n";
			}
		}
		nomer--;
		while (true)
		{
			cout << "\nВы хотите редактировать всё дело,или его часть\n1-если всё\n2-если часть\n";
			cin >> resh;
			if (resh == "1")
			{
				setDelo(delo, nomer);
				break;
			}
			else if (resh == "2")
			{
				
				cout << "\nЧто хотите редактировать?\n1-название,2-приоритет,3-описание,4-дату,5-время\n";
				cin >> resh;
				if (resh == "1")
				{
					cout << "\nВведите новое название дела\n";
					cin >> delo[nomer ].name;
				}
				else if (resh == "2")
				{
					setprior(delo, nomer);
				}
				else if (resh == "3")
				{
					cout << "\nВведите новое описание дела(пробелы,как'_')\n";
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
				cout << "\nВы закончили редактирование?\n";
				cin >> resh;
				break;
			}
			else
			{
				cout << "\nОшибка,попробуйте ещё раз";
			}
		}
	}
}
void poisk(Del* delo, const int& razm)
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls");
	cout << "\nКакой вы хотите осуществить поиск?\n1-По названию\n2-По приоритету\n3-По описанию\n4-По дате и времени исполнения\n";
	cin >> resh;
	if (resh == "1")
	{
		cout << "\nВведите название:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].name == resh)
			{
				cout << "\nНайдено совпадение!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "2")
	{
		cout << "\nВведите приоритет:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].prior == resh)
			{
				cout << "\nНайдено совпадение!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "3")
	{
		cout << "\nВведите описание:\n";
		cin >> resh;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].opis == resh)
			{
				cout << "\nНайдено совпадение!\n";
				otobrdela(delo, i);
			}
		}
	}
	else if (resh == "4")
	{
		int god, den, hh, mm;
		int mes;
		cout << "\nВведите год:\n";
		cin >> god;
		cout << "\nВведите месяц:\n";
		cin >> mes;
		cout << "\nВведите день:\n";
		cin >> den;
		cout << "\nВведите часы:\n";
		cin >> hh;
		cout << "\nВведите минуты:\n";
		cin >> mm;
		for (int i = 0; i < razm; i++)
		{
			if (delo[i].year == god && delo[i].mes == mes && delo[i].den == den && delo[i].hh == hh && delo[i].mm == mm)
			{
				cout << "\nНайдено совпадение!\n";
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
	cout << "**                                                    Список дел                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              Что вы хотите сделать:                                               **\n";
	cout << "**Что вы хотите сделать?                                                                                             **\n";
	cout << "**1-Добавить новое дело                                                                                              **\n";
	cout << "**2-Отобразить все дела                                                                                              **\n";
	cout << "**3-Удаление дел                                                                                                     **\n";
	cout << "**4-Редактирование                                                                                                   **\n";
	cout << "**5-Осуществить поиск дел                                                                                            **\n";
	cout << "**6-Выход                                                                                                            **\n";
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
	cout << "**                                                    Список дел                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              Эта программа умеет:                                                 **\n";
	cout << "**                                                                                                                   **\n";
	cout << "**                                                                                                                   **\n";
	cout << "**1.Добавлять дела                                                                                                   **\n";
	cout << "**2.Удалять дела                                                                                                     **\n";
	cout << "**3.Редактировать дела                                                                                               **\n";
	cout << "**4.Осуществлять поиск                                                                                               **\n";
	cout << "**5.Отображение дел с их сортировкой                                                                                 **\n";
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
	cout << "**                                                    Список дел                                                     **\n";
	for (int i = 0; i < 5; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                              Будьте Внимательны!                                                  **\n";
	cout << "**Эта программа рассчитана на то, что вы будите вводить все ваши решения цифрами(кроме ответов да или нет)           **\n";
	for (int i = 0; i < 8; i++)
	{
	cout << "**                                                                                                                   **\n";
	}
	cout << "**                                     ПРОШУ ВАС БУДЬТЕ ПРИДЕЛЬНО ВНИМАТЕЛЬНЫ!                                       **\n";
	cout << "**                                     ПРОШУ ВАС БУДЬТЕ ПРИДЕЛЬНО ВНИМАТЕЛЬНЫ!                                       **\n";
	cout << "**                                     ПРОШУ ВАС БУДЬТЕ ПРИДЕЛЬНО ВНИМАТЕЛЬНЫ!                                       **\n";
	cout << "**                                     ПРОШУ ВАС БУДЬТЕ ПРИДЕЛЬНО ВНИМАТЕЛЬНЫ!                                       **\n";
	cout << "***********************************************************************************************************************\n";
	cout << "***********************************************************************************************************************\n";
	Sleep(5000);
	system("cls");
}