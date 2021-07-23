#include <iostream>
#include <string.h>
#include <stdlib.h>


#define M 1  //men
#define W 2  //women
//for gender

#define Valet 10  //Valet
#define Queen 10  //Queen
#define King 10   //King
#define A 1       //Ace
//for Card

//Task1----------------------------------------------------------------------------------------------------------------------
class  Person
{
private:
	 std::string name="";
	 short age=0;
	 short gender=0;
	 short weight=0;

	public:
		void Reassigning_the_name(std::string a_name, short a_gender)
		{
			name = a_name;
		
			gender= a_gender;
		}

		void Age_changes(short a_age)
		{
			 age = a_age;
		}

		void Weight_changes(short a_weight)
		{
			weight = a_weight;
		}

		friend class Student;
};


class  Student: public Person
{
	static short Counter; 
private:
	short years_of_study = 0;

public:
	Student()
	{
		Counter++;
	}

	void Reassigning_years_of_study(short a_years_of_study)
	{
		years_of_study = a_years_of_study;
	}

	void Print_information()
	{
		std::cout << "Name Student: " << name << "\nGender: " << gender << "\nAge: " << age << "\nWeight: " << weight << "\n";
		std::cout << "Counter Students: " << Counter << "\n";
	}
};
short Student::Counter;
//Task1----------------------------------------------------------------------------------------------------------------------








//Task2----------------------------------------------------------------------------------------------------------------------
class Fruit
{
private:
	std::string name;
	std::string color;
public:
	Fruit()
	{
	
	}


	std::string getName()
		const
	{
	 return name;
	}

	std::string getColor()
		const
	{
	 return color;
	}
	friend class Apple;
	friend class Banana;
	friend class GrannySmith;
};

class Apple: public  Fruit
{
private:
	std::string const color_app ;
public:
	Apple()
	{

	}
	Apple(const char* a_color)
		:color_app(a_color)
	{
		name = "apple";
		color = color_app;
	}

};

class Banana: public Fruit
{
public:
	Banana()
	{
		name = "banana";
		color = "yellow";
	}

};

class GrannySmith: public Apple
{
public:
	GrannySmith()
	{
		name = "Granny Smith apple";
		color = "green";
	}
};
//Task2----------------------------------------------------------------------------------------------------------------------







//Task3----------------------------------------------------------------------------------------------------------------------

class BlackJack
{
 private:
	 short Deck[4][13] ={ { A, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valet, Queen, King }
						 ,{ A, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valet, Queen, King }
						 ,{ A, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valet, Queen, King }
						 ,{ A, 2, 3, 4, 5, 6, 7, 8, 9, 10, Valet, Queen, King } };
public:
	friend class	player_BlackJack;
	friend class    diler_BlackJack;
};

class player_BlackJack: public BlackJack
{
private:
	short bet;
	short card_player[8] = { 0 };
public:

	void Start_game(BlackJack & Deck)
	{
		short c = rand() % 52;
		card_player[0] = *Deck.Deck[c];
		*Deck.Deck[c] = 0;
		while (!*Deck.Deck[c])
		{
		 c = rand() % 52;
		}
		card_player[1] = *Deck.Deck[c];
	}

	void print_cards()
	{

	}

};

class diler_BlackJack:public BlackJack
{
private:
	short card_diler[2]={ 0 };
public:
	void Start_game(BlackJack& Deck)
	{
		short c = rand() % 52;
		while (!*Deck.Deck[c])
		{
			c = rand() % 52;
		}
		card_diler[1] = *Deck.Deck[c];
	}




};
//Task3----------------------------------------------------------------------------------------------------------------------

int main()
{
//Task1
	Student Anton;
	Anton.Reassigning_the_name("Anton", M);
	Anton.Age_changes(18);
	Anton.Weight_changes(89);
	Anton.Reassigning_years_of_study(1);

	Student Maxim;
	Maxim.Reassigning_the_name("Maxim",M);
	Maxim.Age_changes(21);
	Maxim.Weight_changes(76);
	Maxim.Reassigning_years_of_study(3);

	Student Mihail;
	Mihail.Reassigning_the_name("Mihail",M);
	Mihail.Age_changes(19);
	Mihail.Weight_changes(109);
	Mihail.Reassigning_years_of_study(2);

	Student Anna;
	Anna.Reassigning_the_name("Anna",W);
	Anna.Age_changes(23);
	Anna.Weight_changes(60);
	Anna.Reassigning_years_of_study(4);

	Mihail.Print_information();
//Task1
	std::cout << "\n";
//Task2
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";

//Task2
	std::cout << "\n";
//Task3

//Task3
}