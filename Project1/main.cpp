#include<iostream>
#include <windows.h>
#include<string>
#include"ExpressOrder.h"
#include"InsuredOrder.h"
#include"Order.h"
#include"OrdinaryOrder.h"
using namespace std;

void menu1();
void menu();


int main()
{
	setlocale(LC_ALL, "");
	string fileName, str; int n = 0, a = 9, m = 9;
	int id = 0;
	
	
	do
	{
		menu1();
		cin >> a;
		switch (a) {
		case 1:
		{
			do
			{
				menu();
				cin >> m;
				OrdinaryOrder order1;
				switch (m) {
				case 1:
					system("cls");
					order1.toString();
					order1.toFile();
					cout << "Заказ сохранен...\n";
					system("pause"); break;
				
				case 2:
					system("cls");
					order1.toFile();
					cout << "Заказ сохранен: ";
					system("pause"); break;
				
				case 3:
					system("cls");
					cout << order1.fromFile();
					system("pause"); break;
				}
			} while (m);
			break;
		}
		case 2:
		{
			do
			{
				menu();
				cin >> m;
				ExpressOrder orderExp;
				switch (m) {
				case 1:
					system("cls");
					orderExp.toString();
					orderExp.toFile();
					cout << "Заказ сохранен...\n";
					system("pause"); break;
				case 2:
					system("cls");
					orderExp.toFile();
					cout << "Сохранить заказ: ";
					system("pause"); break;
				case 3:
					system("cls");
					orderExp.fromFile();
					system("pause"); break;
				}
			} while (m);
			break;
		}
		case 3:
			do
			{
				menu();
				cin >> m;
				InsuredOrder orderIns;
				switch (m) {
				case 1:
					system("cls");
					orderIns.toString();
					orderIns.toFile();
					cout << "Заказ сохранен...\n";
					system("pause"); break;
				case 2:
					system("cls");
					orderIns.toFile();
					cout << "Сохранить заказ: ";
					system("pause"); break;
				case 3:
					system("cls");
					orderIns.fromFile();
					system("pause"); break;
				}
			} while (m);
			break;
		}
	} 
	while (a);
	system("cls");
	cout << "Спасибо что воспользовались нашими услугами доставки...\n\tДо новых встречь...\n\n";
	system("pause");
	return 0;
}

void menu()
{
	system("cls");
	cout << "**********************************\n";
	cout << "1 - Создать заказ\n";
	//cout << "2 - Сохранить заказ\n";
	cout << "3 - Просмотреть список заказов\n";
	cout << "0 - Выход...\n";
	cout << "**********************************\n";
	
}

void menu1()
{
	cout << "**********************************\n";
	cout << "Добро пожаловать в стол заказов...\n";
	cout << "**********************************\n";
	//Sleep(1500);
	system("cls");
	cout << "**********************************\n";
	cout << "Выберите желаемый тип заказа...   \n";
	cout << "**********************************\n";
	cout << "1 - Обычный заказ\n";
	cout << "2 - Срочный заказ\n";
	cout << "3 - Застрахованный заказ\n";
	cout << "0 - Выход...\n";
	cout << "**********************************\n";
}
