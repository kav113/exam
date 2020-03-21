#pragma once
#include"Date.h"
#include"Time.h"
class Order : public Date, public Time
{
protected:
	int date;
	int time;
	int id;
public:
	Order();
	Order(Date date, Time time, int id);

	//void save(ofstream&file);
	//void load(ifstream&file);
};

