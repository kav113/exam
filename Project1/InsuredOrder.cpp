#include "InsuredOrder.h"
#include <fstream>
#include<string>
#include <cstring>

InsuredOrder::InsuredOrder(Date date, Time time, Order id, string company, double amount)
{
	this->company = company;
	this->amount = amount;
}

InsuredOrder::InsuredOrder()
{
	id++;
	company = "VUSO";
	amount = 2300;
}

void InsuredOrder::toString()
{
	cout << "����� � " << id  
		 << "\n������ : " << Date() << Time() << "\n�������� : " 
		 << company << "\n��������� ��������� : " << amount << endl;
}

InsuredOrder & InsuredOrder::operator=(const Order & obj)
{
	// TODO: insert return statement here
	return *this;
}

void InsuredOrder::toFile()
{
	ofstream OrderList;
	OrderList.open("InsuredOrder.bin", ios::app);

	if (OrderList.is_open()) {
		OrderList << id << " " << Date() << " " << Time() << " " << company << " " << amount << " ";
		OrderList.close();
		cout << "OK\n";
	}
	else {
		cout << "Error\n";
	}
	return;
}

string InsuredOrder::fromFile()
{
	string lineId, lineDate, lineTime;
	ifstream OrderList;
	OrderList.open("InsuredOrder.bin", ios::binary);

	if (OrderList.is_open()) {
		OrderList >> id >> lineDate >> lineTime >> company >> amount;
		OrderList.close();
		cout << "����� � " << id
			<< "\n������ : " << lineDate << lineTime << "\n�������� : "
			<< company << "\n��������� ��������� : " << amount << endl;
	}
	else {
		cout << "Error\n";
	}
	return string();
}

ostream & operator<<(ostream & out, const InsuredOrder & id)
{
	// TODO: insert return statement here
	out << id;
	return out;
}

istream & operator>>(istream & in, InsuredOrder & id)
{
	// TODO: insert return statement here
	cout << "������� id ������: "; in >> id;
	return in;
}
