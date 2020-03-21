#pragma once

#include <iostream>
#include <ctime>
using namespace std;

class Time
{
	int hour;
	int minutes;
	int seconds;
	char* format;// am/pm (12-hours), utc (24-hours)

	bool utc;

public:
	Time(); // Current local time
	Time(int hour, int minutes, int seconds, const char*format = "utc");
	Time(const Time& obj);
	~Time();

	void setHour(int hour);
	int getHour();
	void setMinutes(int minutes);
	int getMinutes();
	void setSeconds(int seconds);
	int getSeconds();
	void setFormat(const char* format); // !!! to update time by the new format
	const char* getFormat();
	void reGetLocalTime();
	void reGetLocalTimeInUtc();

	void changeFormat();   //London is the capital of Greate Brittan

	bool valid(); //time check
	void tickTime(); //every tick add one second
	void tickBack(); //delete second
	void showTime(); //show time by the format

	//--------- Comparison operators ---------
	bool operator == (const Time& obj);
	bool operator != (const Time& obj);
	bool operator > (const Time& obj);
	bool operator < (const Time& obj);
	bool operator >= (const Time& obj);
	bool operator <= (const Time& obj);

	//--------- Assignment operators ---------
	Time& operator = (const Time& obj);
	Time& operator += (int n);
	Time& operator -= (int n);

	//--------- Arithmetic operators ---------
	Time operator + (int n);
	Time operator - (int n);

	////ÈÍÊÐÅÌÅÍÒ È ÄÅÊÐÅÌÅÍÒ
	Time operator++();
	Time operator--();

	Time operator ++(int a);
	Time operator --(int a);

	friend ostream& operator << (ostream& out, const Time& d);
	friend istream& operator >> (istream& in, Time& d);
	//friend ostream& operator << (ostream& out, Time& t);
	//friend istream& operator >> (istream& in, Time& t);

};
