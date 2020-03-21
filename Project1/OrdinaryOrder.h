#pragma once
#include "Order.h"
class OrdinaryOrder : public Order
{
public:
	OrdinaryOrder(Date date, Time time, Order id);
	OrdinaryOrder();
	void toString();

	friend ostream& operator << (ostream& out, const OrdinaryOrder& id);
	friend istream& operator >> (istream& in, OrdinaryOrder& id);
	OrdinaryOrder& operator = (const Order& obj);

	void toFile();
	string fromFile();


};

