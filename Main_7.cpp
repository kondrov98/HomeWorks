#include <iostream>

class Date
{
private:
	short year;
	short month;
	short day;
public:
	Date()
	{}

	Date(short m_day, short m_month, short m_year): day(m_day),month(m_month),year(m_year)
	{}

	short getDay()
	{
		return day;
	}

	void setDay(short m_day)
	{
		day = m_day;
	}

	short getMonth()
	{
		return month;
	}

	void setMonth(short m_month)
	{
		month = m_month;
	}

	short getYear()
	{
		return year;
	}

	void setYear(short m_year)
	{
		year = m_year;
	}

	friend std::ostream& operator<< (std::ostream & out, const Date & date);
};

std::ostream& operator<< (std::ostream & out, const Date & date)
{
	out <<"Date: "<<date.day<<"."<<date.month<<"."<<date.year<<"\n";
	return out;
}

template <class T>
class today
{
private:
	T* ptr;
	int t;
public:
	today(T* ptr)
	{
		this->ptr = ptr;
	}
	~today()
	{
		
		delete ptr;
		std::cout << "ptr for object today=nullptr\n";
	}
	friend std::ostream& operator<<(std::ostream& out, const today<T>& today);

};

std::ostream& operator<<(std::ostream& out,const today<Date>& today)
{
	out << "Today's date: " << today.ptr->getDay() << "." << today.ptr->getMonth()<< "." << today.ptr->getYear() << "\n";
	return out;
}

template <class T>
class date
{
private:
	T* ptr;
public:
	date(T* ptr)
	{
		this->ptr = ptr;
	}
	~date()
	{
		delete ptr;
		std::cout << "ptr for object date=nullptr\n";
	}
};

template <class Date>
class date1
{
private:
	
public:
	Date* ptr;
	date1(Date* ptr)
	{
		this->ptr = ptr;
	}
	~date1()
	{
		delete ptr;
	}
};

template <class T>
class date2
{
private:
	
public:
	Date* ptr;
	date2(Date* ptr)
	{
		this->ptr = ptr;
	}
	~date2()
	{
		delete ptr;
	}
};

void Late_time(date1<Date>& date1, date2<Date>& date2)
{
	bool i;
	if (date1.ptr->getDay() < date2.ptr->getDay())
	{
		i = true;
	}
	if (date1.ptr->getDay() > date2.ptr->getDay())
	{
		i = false;
	}
	if (date1.ptr->getMonth() < date2.ptr->getMonth())
	{
		i = true;
	}
	if (date1.ptr->getMonth() > date2.ptr->getMonth())
	{
		i = false;
	}
	if (date1.ptr->getYear() < date2.ptr->getYear())
	{
		i = true;
	}
	if (date1.ptr->getYear() > date2.ptr->getYear())
	{
		i = false;
	}

	if (i)
		std::cout << "Late time: " << date2.ptr->getDay() << "." << date2.ptr->getMonth() << "." << date2.ptr->getYear() << ".(date2)\n";
	else
		std::cout << "Late time: " << date1.ptr->getDay() << "." << date1.ptr->getMonth() << "." << date1.ptr->getYear() << ".(date1)\n";
}	


void Sharing_resources(date1<Date>& date1, date2<Date>& date2)
{
	Date* ptr1;
	
	ptr1 = date2.ptr;

	date2.ptr = date1.ptr;
	date1.ptr = ptr1;
}


int main()
{
	{
		today<Date> today = new Date(13, 8, 2021);
		std::cout << today;
		date<Date>date = new Date;
	}
	{
		date1<Date> date1 = new Date(1, 7, 2021);
		date2<Date> date2 = new Date(13, 8, 2020);
		Late_time(date1, date2);

		Sharing_resources(date1, date2);

		Late_time(date1, date2);
	}
	std::cout << "This end!";
	return 0;
}