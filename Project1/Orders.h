#pragma once
#include<iostream>

using namespace std;

class Orders
	
{
public:
	int info;
	Orders* next;

	Orders() {
		info = 0;
		next = NULL;
	}
	Orders(int a) {
		info = a;
		next = NULL;
	}
};
class List
{
	Orders* head;
	Orders* current;
public:
	List()
	{
		head = current = NULL;
	}
	~List()
	{
		Orders* p = head;
		while (p != NULL)
		{
			Orders* tmp = p;//сохраняем адрес текущего
			p = p->next;//сдвигает на адрес след
			delete tmp;//удаляем текущий

		}
	};

	void add(int a)
	{
		Orders* p = new Orders(a);
		if (head == NULL)
		{
			head = p;
			current = p;
		}
		else
		{
			current->next = p;
			current = p;
		}
	}

	void show()
	{
		Orders* p = head;
		while (p != NULL)
		{
			cout << p->info << " ";
			p = p->next;
		}
		cout << endl;
	}

	int findMax()
	{
		Orders* p = head;
		int max = p->info;
		while (p != NULL)
		{
			if ((p->info) > max)
			{
				max = p->info;
			}
			p = p->next;
		}
		return max;
	}

};