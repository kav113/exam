#pragma once
#include "Order.h"
class ExpressOrder : public Order
{
protected:
	string courier;
	int DaysToDelivery;
public:
	ExpressOrder(Date date, Time time, Order id, string courier, int DaysToDelivery);
	ExpressOrder();
	void toString();

	friend ostream& operator << (ostream& out, const ExpressOrder& id);
	friend istream& operator >> (istream& in, ExpressOrder& id);
	ExpressOrder& operator = (const Order& obj);

	void toFile();
	string fromFile();

};

