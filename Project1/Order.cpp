#include "Order.h"
#include <iostream>
#include <string>
#include <fstream>

Order::Order()
{
	id;
	Date();
	Time();
}

Order::Order(Date date, Time time, int id)
{
	this->id = id++;
}


