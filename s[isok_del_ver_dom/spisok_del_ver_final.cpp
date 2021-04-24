#include "Dlaspiskadel.h"
int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	menu1();
	while (true)
	{
		cout << "Добро пожаловать в приложение 'Список дел'\nХотите узнать,на что способна программа?\n";
		cin >> resh;
		if (resh == "да" || resh == "нет")
		{
			break;
		}
		else
		{
			cout << "\nПожалуйста, введите да или нет\n";
		}
	}
	if (resh == "да")
	{
		menu2();
	}
	while (vihod == "нет")
	{
		menu3();
		cin >> resh;
		if (resh == "1")
		{
			delo = Addstr(delo, razm);
			setDelo(delo, razm);
			razm++;
		}
		else if (resh == "2")
		{
			otobr(delo, razm);
			Sleep(5000);
		}
		else if (resh == "3")
		{
			razm--;
			udal(delo, razm);
		}
		else if (resh == "4")
		{
			redact(delo, razm);
		}
		else if (resh == "5")
		{
			poisk(delo, razm);
			Sleep(5000);
		}
		else if (resh == "6")
		{
			while (true)
			{
				cout << "Вы точно хотите выйти?";
				cin >> vihod;
				if (vihod == "да" || vihod == "нет")
				{
					break;
				}
				else
				{
					cout << "\nПожалуйста,введите да или нет\n";
				}
			}
		}
		else 
		{
			cout << "Ошибка,попробуйте ещё раз";
			Sleep(1400);
		}
	}
}
 