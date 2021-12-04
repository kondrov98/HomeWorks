#include <iostream>
#include <gtest/gtest.h>
#include <string>
#include <optional>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>

struct Person
{
	std::string Surname;
	std::string Name;
	std::optional<std::string> Patronymic;
	friend std::ostream& operator<< (std::ostream& out, const Person& person);
	friend bool operator< (const Person& p1, const Person& p2);
	friend bool operator== (const Person& p1, const Person& p2);
};

std::ostream& operator<< (std::ostream& out, const Person& person)
{
	person.Surname.length();

	out << person.Surname;
	for (short i = 0; i < 20 - person.Surname.length(); i++)
		out << ' ';
	out << person.Name;
	for (short i = 0; i < 20 - person.Name.length(); i++)
		out << ' ';
	if (person.Patronymic && person.Patronymic != "-")
		out << person.Patronymic.value();
	else
		out << ' ';
	for (short i = 0; i < 20 - person.Patronymic.value().length(); i++)
		out << ' ';

	return out;
}

bool operator< (const Person& p1, const Person& p2)
{
	return std::tie(p1.Surname, p1.Name, p1.Patronymic) < std::tie(p2.Surname, p2.Name, p2.Patronymic);
}

bool operator== (const Person& p1, const Person& p2)
{
	return std::tie(p1.Surname, p1.Name, p1.Patronymic) == std::tie(p2.Surname, p2.Name, p2.Patronymic);
}


struct PhoneNumber
{
	short Country_code;
	short City_code;
	std::string number;
	std::optional<short> Extension_number;
	friend std::ostream& operator<< (std::ostream& out, PhoneNumber& PN);
};

std::ostream& operator<< (std::ostream& out, PhoneNumber& PN)
{
	out << '+' << PN.Country_code << '(' << PN.City_code << ')' << PN.number << ' ';
	if (PN.Extension_number)
		out << PN.Extension_number.value();
	return out;
}


struct PhoneBook
{
private:
	std::pair <Person, PhoneNumber> PP;
	std::vector<std::pair <Person, PhoneNumber>>s_file;
public:
	PhoneBook(std::ifstream& file)
	{
		short i = 0;
		std::string sfile;
		while (!file.eof())
		{
			for (short j = 0; j < 7; j++)
			{

				switch (j)
				{
				case 0:
					std::getline(file, PP.first.Surname, ' ');
					break;
				case 1:
					std::getline(file, PP.first.Name, ' ');
					break;
				case 2:
					std::getline(file, sfile, ' ');
					PP.first.Patronymic = sfile;
					break;
				case 3:
					std::getline(file, sfile, ' ');
					PP.second.Country_code = stoi(sfile);
					break;
				case 4:
					std::getline(file, sfile, ' ');
					PP.second.City_code = stoi(sfile);
					break;
				case 5:
					std::getline(file, PP.second.number, ' ');
					break;
				case 6:
					std::getline(file, sfile, '\n');
					if (sfile != "-")
						PP.second.Extension_number = stoi(sfile);
					else
						PP.second.Extension_number = std::nullopt;
					break;
				default:
					break;
				}

			}
			s_file.push_back(PP);
		}
	}


	void SortByName()
	{
		sort(s_file.begin(), s_file.end(), [](std::pair<Person, PhoneNumber>& lhs, std::pair<Person, PhoneNumber>& rhs) {return lhs.first < rhs.first; });
	}

	void SortByPhone()
	{
		sort(s_file.begin(), s_file.end(), [](std::pair<Person, PhoneNumber>& lhs, std::pair<Person, PhoneNumber>& rhs) {return std::tie(lhs.second.Country_code, lhs.second.City_code, lhs.second.number, lhs.second.Extension_number) < std::tie(rhs.second.Country_code, rhs.second.City_code, rhs.second.number, rhs.second.Extension_number); });
	}

	std::tuple<std::string, PhoneNumber> GetPhoneNumber(std::string Surname)
	{
		unsigned short j = 0;
		PhoneNumber number;
		std::for_each(s_file.begin(), s_file.end(),
			[&Surname, &j, &number](std::pair<Person, PhoneNumber>& lhs)
		{
			if (lhs.first.Surname == Surname)
			{
				number = lhs.second;
				j++;
			}
		});
		if (j == 1)
		{
			return std::tie("", number);
		}
		else
		{
			std::ostringstream os;
			os << "Assertion failed: unique name \""<< Surname<<"\" not detected\n";
			throw std::runtime_error(os.str());
			if (j < 1)
			{
				return std::tie("not found", number);
			}
			else
			{
				return std::tie("found more than 1", number);
			}
		}
	}

	void ChangePhoneNumber(Person p, PhoneNumber newNumber)
	{
		auto res = std::find_if(s_file.begin(), s_file.end(),
			[&p](std::pair<Person, PhoneNumber>& lhs)
		{
			return lhs.first == p;
		});

		if (res != s_file.end())
		{
			std::pair<Person, PhoneNumber> l = { p,newNumber };
			*res = l;
		}
	}

	friend std::ostream& operator<<(std::ostream& out, PhoneBook& PB);
};


std::ostream& operator<<(std::ostream& out, PhoneBook& PB)
{
	for (auto i = PB.s_file.begin(); i != PB.s_file.end(); i++)
	{
		out << i->first << ' ' << i->second << '\n';
	}
	return out;
}

template <typename TestFunc>
void Run_Test(TestFunc func, const std::string& test_name)
{
	try {
		func();
		std::cerr << test_name << " OK" << std::endl;
	}
	catch (std::runtime_error& e) {
		std::cerr << test_name << " FAIL: " << e.what() << std::endl;
	}

}

void func_1()
{
	std::ifstream file("C:\\Users\\kondr\\Desktop\\Programming\\C++\\Hard Moment\\Hard_Moment_1\\Hard_Moment_1\\Hard_Moment_1\\PhoneBook.txt"); // путь к файлу PhoneBook.txt
	PhoneBook book(file);
	auto print_phone_number = [&book](const std::string& surname) {
		std::cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (std::get<0>(answer).empty())
			std::cout << std::get<1>(answer);
		else
			std::cout << std::get<0>(answer);
		std::cout << std::endl;
	};

	// вызовы лямбды
	print_phone_number("Ivanov");
	print_phone_number("Petrov");
	print_phone_number("Solovev");
}

void func_2()
{
	std::ifstream file("C:\\Users\\kondr\\Desktop\\Programming\\C++\\Hard Moment\\Hard_Moment_1\\Hard_Moment_1\\Hard_Moment_1\\PhoneBook.txt"); // путь к файлу PhoneBook.txt
	PhoneBook book(file);
	auto print_phone_number = [&book](const std::string& surname) {
		std::cout << surname << "\t";
		auto answer = book.GetPhoneNumber(surname);
		if (std::get<0>(answer).empty())
			std::cout << std::get<1>(answer);
		else
			std::cout << std::get<0>(answer);
		std::cout << std::endl;
	};

	// вызовы лямбды
	print_phone_number("Solovev");
}


int main()
{
	Run_Test(func_1, "\nPhoneBook.GetPhoneNumber");

	Run_Test(func_2, "\nPhoneBook.GetPhoneNumber");

}