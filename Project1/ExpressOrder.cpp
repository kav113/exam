#include "ExpressOrder.h"
#include <fstream>
#include<string>
#include <cstring>

ExpressOrder::ExpressOrder(Date date, Time time, Order id, string courier, int DaysToDelivery)
{
	this->courier = courier;
	this->DaysToDelivery = DaysToDelivery;
}

ExpressOrder::ExpressOrder()
{
	id++;
	courier = "MeestExpress";
	DaysToDelivery = 3;
}

void ExpressOrder::toString()
{
	cout << "Заказ № " << id << "\nСоздан : " << Date() << Time() 
		 << "\nКурьер : " << courier <<  "\nДней до доставки : " << DaysToDelivery<< endl;
}

ExpressOrder & ExpressOrder::operator=(const Order & obj)
{
	return *this;
}

void ExpressOrder::toFile()
{
	ofstream OrderList;
	OrderList.open("ExpressOrder.bin", ios::app);

	if (OrderList.is_open()) {
		OrderList << id << " " << Date() << Time() << " " << courier << " " << DaysToDelivery << " ";
		OrderList.close();
		cout << "OK\n";
	}
	else {
		cout << "Error\n";
	}
	return;
}

string ExpressOrder::fromFile()
{
	string lineId, lineDate, lineTime;
	ifstream OrderList;
	OrderList.open("ExpressOrder.bin", ios::binary);

	if (OrderList.is_open()) {
		for (int i = 0; i < ; i++)
		{
			OrderList >> lineId >> lineDate >> lineTime >> courier >> DaysToDelivery;
			cout << "Заказ № " << lineId << "\nСоздан : " << lineDate << lineTime
				<< "\nКурьер : " << courier << "\nДней до доставки : " << DaysToDelivery << endl;
			cout << "************************\n";
		}
		
		OrderList.close();
		
	}
	else {
		cout << "Error\n";
	}
	return string();
}

ostream & operator<<(ostream & out, const ExpressOrder & id)
{
	out << id;
	return out;
}

istream & operator>>(istream & in, ExpressOrder & id)
{
	cout << "Введите id заказа: "; in >> id;
	return in;
}
