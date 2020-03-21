#include "OrdinaryOrder.h"
#include <fstream>
#include<string>
#include <cstring>
using namespace std;

OrdinaryOrder::OrdinaryOrder(Date date, Time time, Order id)
{
}

OrdinaryOrder::OrdinaryOrder()
{
	id ++;
	date = date;
	time = time;
}

void OrdinaryOrder::toString()
{
	cout << "����� � " << id
		<< "\n������ : " << Date() << Time() <<endl;
}

OrdinaryOrder & OrdinaryOrder::operator=(const Order & obj)
{
	return *this;
}

void OrdinaryOrder::toFile()
{
	ofstream OrderList;
	OrderList.open("OrdinaryOrder.bin", ios::app);
	
	if (OrderList.is_open()) {
		OrderList << id << " " << Date() << Time() << " ";
		OrderList.close();
		cout << "OK\n";
	}
	else {
		cout << "Error\n";
	}
	return;
}

string OrdinaryOrder::fromFile()
{
	string lineId, lineDate, lineTime;
	ifstream OrderList;
	OrderList.open("OrdinaryOrder.bin", ios::in);

	if (OrderList.is_open()) {
		OrderList >> lineId >> lineDate >> lineTime;
		OrderList.close();
		cout << "����� � " << id
			<< "\n������ : " << lineDate <<" "<< lineTime << endl;
	}
	else {
		cout << "Error\n";
	}	
	return string();
}


ostream & operator<<(ostream & out, const OrdinaryOrder & id)
{
	out << id;
	return out;
}

istream & operator>>(istream & in, OrdinaryOrder & id)
{
	cout << "������� id ������: "; in >> id;
	return in;
}
