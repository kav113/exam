#pragma once
#include "Order.h"
class InsuredOrder : public Order
{protected:
	string company;
	double amount;
public:
	InsuredOrder(Date date, Time time, Order id, string company, double amount);
	InsuredOrder();
	void toString();
	friend ostream& operator << (ostream& out, const InsuredOrder& id);
	friend istream& operator >> (istream& in, InsuredOrder& id);
	InsuredOrder& operator = (const Order& obj);

	void toFile();
	string fromFile();

};

