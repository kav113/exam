#include"Time.h"
#include <cstring>


Time::Time()
{
	time_t tt;
	struct tm *tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->utc = true;
}

Time::Time(int hour, int minutes, int seconds, const char * format)
{
	if ((minutes > 60 || minutes < 1 || seconds > 60 || seconds < 1) ||
		((strcmp(format, "am") == 0 || strcmp(format, "pm") == 0) && (hour > 12 || hour < 1)) ||
		(strcmp(format, "utc") == 0 && (hour > 24 || hour < 1)) ||
		(strcmp(format, "utc") != 0 || strcmp(format, "pm") != 0 || strcmp(format, "am") != 0))
	{
		cout << "Некорректно заданы параметры! Установлено время по умолчанию (utc, 12:00)!" << endl;
		system("pause");
		this->format = new char[strlen("utc")];
		strcpy(this->format, "utc");
		this->hour = 12;
		this->minutes = 0;
		this->seconds = 0;
	}
	else
	{
		this->hour = hour;
		this->minutes = minutes;
		this->seconds = seconds;

		this->format = new char[strlen(format)];
		strcpy(this->format, format);

		if (strcmp(this->format, "utc") == 0)this->utc = true;
		else this->utc = false;
	}

}

Time::Time(const Time & obj)
{
	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;

	if (this->format != NULL)delete[]this->format;

	this->format = new char[strlen(obj.format)];
	strcpy(this->format, obj.format);

	if (strcmp(this->format, "utc") == 0) this->utc = true;
	else this->utc = false;
}


Time::~Time()
{
	//delete[] this->format; выдает ошибку с квадратными скобками и без!
}

void Time::setHour(int hour)
{
	if ((strcmp(this->format, "utc") == 0 && (hour <= 24 && hour >= 1)) || (strcmp(this->format, "am") == 0 || strcmp(this->format, "pm") == 0 && (hour >= 1 && hour <= 12)))
	{
		this->hour = hour;
	}
}

int Time::getHour()
{
	return this->hour;
}

void Time::setMinutes(int minutes)
{
	if (minutes >= 1 && minutes <= 60)
	{
		this->minutes = minutes;
	}
}

int Time::getMinutes()
{
	return this->minutes;
}

void Time::setSeconds(int seconds)
{
	if (seconds <= 60 && seconds >= 1)this->seconds = seconds;
}

int Time::getSeconds()
{
	return this->seconds;
}

void Time::setFormat(const char * format)
{
	if (strcmp(this->format, format) == 0)return;
	if ((strcmp(this->format, "am") == 0 && strcmp(format, "pm") == 0) || (strcmp(this->format, "pm") == 0 && strcmp(format, "am") == 0))
	{
		cout << "Перевод из am в pm и наоборот - невозможен!" << endl;
		return;
	}

	if (strcmp(format, "am") == 0)
	{
		if (this->hour > 12)
		{
			cout << "Перевод невозможен!" << endl;
		}
		else
		{
			//delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
	else if (strcmp(format, "pm") == 0)
	{
		if (this->hour <= 12)
		{
			cout << "Перевод невозможен!" << endl;
		}
		else
		{
			this->hour -= 12;

			//delete[] this->format;  error
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
	}
	else if (strcmp(format, "utc") == 0)
	{
		if (strcmp(this->format, "am") == 0)
		{
			//delete[] this->format;
			this->format = new char[strlen("utc")];
			strcpy(this->format, "utc");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			//delete[] this->format;
			this->format = new char[strlen("utc")];
			strcpy(this->format, "utc");

			this->hour += 12;
		}
	}

	if (strcmp(this->format, "utc") == 0)this->utc = true;
	else this->utc = false;
}

const char * Time::getFormat()
{
	return this->format;
}

void Time::reGetLocalTime()
{
	char form[10];
	strcpy(form, this->format);

	time_t tt;
	struct tm *tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->setFormat(form);

	if (strcmp(form, "utc") == 0)this->utc = true;
}

void Time::reGetLocalTimeInUtc()
{
	time_t tt;
	struct tm *tim = new tm;
	tt = time(NULL);
	localtime_s(tim, &tt);
	this->hour = tim->tm_hour;
	this->minutes = tim->tm_min;
	this->seconds = tim->tm_sec;
	this->format = new char[strlen("utc")];
	strcpy(this->format, "utc");

	this->utc = true;
}

void Time::changeFormat()
{
	if (strcmp(this->format, "am") == 0 || strcmp(format, "pm") == 0)
	{
		this->setFormat("utc");
	}
	else if (strcmp(this->format, "utc") == 0)
	{
		if (this->hour <= 12)this->setFormat("am");
		else if (this->hour >= 12)this->setFormat("pm");
	}

	if (strcmp(this->format, "utc") == 0)this->utc = true;
	else this->utc = false;
}

bool Time::valid()
{
	if (strcmp(this->format, "utc") != 0 && strcmp(this->format, "am") != 0 && strcmp(this->format, "pm") != 0)return false;
	if (this->minutes > 60 || this->minutes < 1 || this->seconds > 60 || this->seconds < 1)return false;
	else if (((strcmp(this->format, "utc") == 0) && (this->hour > 24 || this->hour < 1)) || (((strcmp(this->format, "am") == 0) || (strcmp(this->format, "pm") == 0)) && (this->hour > 12 || this->hour < 1))) return false;
	else return true;
}

void Time::tickTime()
{
	this->seconds++;

	if (this->seconds == 60)
	{
		this->minutes++;
		this->seconds = 0;
	}

	if (this->minutes == 60)
	{
		this->hour++;
		this->minutes = 0;
	}

	if (this->utc && this->hour == 24)
	{
		this->hour = 0;
	}
	else if (!this->utc && this->hour == 13)
	{
		this->hour = 1;

		if (strcmp(this->format, "am") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
}

void Time::tickBack()
{
	this->seconds--;

	if (this->seconds == -1)
	{
		this->minutes--;
		this->seconds = 59;
	}

	if (this->minutes == -1)
	{
		this->hour--;
		this->minutes = 59;
	}

	if (this->utc && this->hour == -1)
	{
		this->hour = 23;
	}
	else if (!this->utc && this->hour == 0)
	{
		this->hour = 12;

		if (strcmp(this->format, "am") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("pm")];
			strcpy(this->format, "pm");
		}
		else if (strcmp(this->format, "pm") == 0)
		{
			delete[] this->format;
			this->format = new char[strlen("am")];
			strcpy(this->format, "am");
		}
	}
}

void Time::showTime()
{
	cout << " " << this->format << " " << this->hour << ":" << this->minutes << ":" << this->seconds << endl;
}

bool Time::operator==(const Time & obj)
{
	char form[10];
	strcpy(form, this->format);

	Time tmp(obj);

	tmp.setFormat(form);

	if ((strcmp(this->format, tmp.format) == 0) && this->hour == tmp.hour && this->minutes == tmp.minutes && this->seconds == tmp.seconds)
		return true;
	else return false;
}

bool Time::operator!=(const Time & obj)
{
	return !(*this == obj);
}

bool Time::operator>(const Time & obj)
{
	char form[10];
	strcpy(form, this->format);

	Time tmp(obj);

	tmp.setFormat(form);

	if (strcmp(this->format, tmp.format) == 0)
	{
		if (this->hour > tmp.hour)return true;
		else if (this->hour == tmp.hour)
		{
			if (this->minutes > tmp.minutes)return true;
			else if (this->minutes == tmp.minutes)
			{
				if (this->seconds > tmp.seconds)return true;
				else return false;
			}
		}
	}
	else if (strcmp(this->format, "pm") == 0 && strcmp(tmp.format, "am")) return true;
	else return false;

}

bool Time::operator<(const Time & obj)
{
	if (!(*this > obj) && *this != obj)return true;
	else return false;
}

bool Time::operator>=(const Time & obj)
{
	if ((*this > obj) || (*this == obj))return true;
	else return false;
}

bool Time::operator<=(const Time & obj)
{
	if ((*this < obj) || (*this == obj))return true;
	else return false;
}

Time & Time::operator=(const Time & obj)
{
	// TODO: вставьте здесь оператор return
	this->format = new char[strlen(obj.format)];
	strcpy(this->format, obj.format);

	this->hour = obj.hour;
	this->minutes = obj.minutes;
	this->seconds = obj.seconds;
	return *this;
}

Time & Time::operator+=(int n)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < n; i++)
	{
		this->tickTime();
	}
	return *this;
}

Time & Time::operator-=(int n)
{
	// TODO: вставьте здесь оператор return
	for (int i = 0; i < n; i++)
	{
		this->tickBack();
	}
	return *this;
}

Time Time::operator+(int n)
{
	Time tmp(*this);

	tmp += n;

	return tmp;
}

Time Time::operator-(int n)
{
	Time tmp(*this);

	tmp -= n;

	return tmp;
}

Time Time::operator++()
{
	this->tickTime();

	return *this;
}

Time Time::operator--()
{
	this->tickBack();
	return *this;
}

Time Time::operator++(int a)
{
	Time tmp(*this);

	this->tickTime();

	return tmp;
}

Time Time::operator--(int a)
{
	Time tmp(*this);

	this->tickBack();

	return tmp;
}

ostream & operator<<(ostream & out, const Time & t)
{
	// TODO: вставьте здесь оператор return
	out << " " << t.hour/10 << t.hour % 10 << ":" << t.minutes/10 << t.minutes % 10 << ":" << t.seconds/10 << t.seconds % 10;
	return out;
}

istream & operator>>(istream & in, Time & t)
{
	// TODO: вставьте здесь оператор return
	cout << "  Введите формат времени: "; char tmp[10]; in.get(); in.getline(tmp, 10);
	//if (t.format != NULL)delete[]t.format;
	t.format = new char[strlen(tmp)];
	strcpy(t.format, tmp);

	cout << "  Введите часы: "; in >> t.hour;
	cout << "  Введите минуты: "; in >> t.minutes;
	cout << "  Введите секунды: "; in >> t.seconds;

	if (!t.valid())
	{
		cout << "Параметры введены не верно! \nУстановлено текущее время!" << endl;
		t.reGetLocalTimeInUtc();
	}

	return in;
}
