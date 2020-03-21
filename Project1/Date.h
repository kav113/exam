#pragma once
#include <iostream>
using namespace std;

class Date
{
	int year;
	int month;
	int day;



public:
	//---------������������ � ����������---------
	Date(); // �� ���������  - ������� ����
	Date(int year, int month, int day); //� ����������� - �������� ����
	Date(const Date& obj); //�����������
	~Date();// ����������

	void showInfo();
	void sv(int y, int m, int d);

	bool isLeapYear(); //�������� �� ���������� ���
	int monthDays(); //���������� ���� �� ������
	void nextDate(); //��������� ����
	void prevDate(); //���������� ����

	void setNowDate();

	//---------���������---------
	void setYear(int year);
	int getYear();
	void setMonth(int month);
	int getMonth();
	void setDay(int day);
	int getDay();

	bool valid(); //�������� ���� �� ������������

				  //--------- ��������� ��������� ---------
	bool operator == (const Date& obj);
	bool operator != (const Date& obj);
	bool operator > (const Date& obj);
	bool operator < (const Date& obj);
	bool operator >= (const Date& obj);
	bool operator <= (const Date& obj);

	//--------- ��������� ���������� ---------
	Date& operator = (const Date& obj);
	Date& operator += (int n);
	Date& operator -= (int n);

	//--------- �������������� ��������� ---------
	Date operator + (int n);
	Date operator - (int n);
	int operator -(const Date & tmp);
	Date operator +(const Date & tmp);

	////incriment/decrement
	Date& operator ++();
	Date& operator ++(int a);
	Date& operator --();
	Date& operator --(int a);


	///friendship

	friend ostream& operator << (ostream& out, const Date& d);
	friend istream& operator >> (istream& in, Date& d);
	friend ofstream& operator << (ofstream& fout, Date& d);
	friend ifstream& operator >> (ifstream& fin, Date& d);

};


