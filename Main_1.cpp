#include <iostream>
#include <math.h>
#include <cstdint>


class Power
{
private:
	short  Variable1=0;
	short  Variable2=0;

public:
	void set(short m_Variable1, short m_Variable2)
	{
		Variable1 = m_Variable1;
		Variable2 = m_Variable2;
	}
	void calculate()
	{
		 std::cout<<"The number "<< Variable1<<" to the power of "<< Variable2<<" = "<<pow(Variable1, Variable2)<<"\n";
	}
};

class RGBA
{
private:
	std::uint8_t  m_red=0;
	std::uint8_t  m_green=0;
	std::uint8_t  m_blue=0;
	std::uint8_t  m_alpha = 255;
public:
	RGBA(std::uint8_t red, std::uint8_t green, std::uint8_t blue, std::uint8_t  alpha)
		:m_red(red), m_green(green), m_blue(blue), m_alpha(alpha)
	{
		
	}
	void print()
	{
		std::cout << "m_red = " << (int)m_red << ";\nm_green = " << (int)m_green << ";\nm_blue = " << (int)m_blue<<"\nalpha = "<< (int)m_alpha<<"\n";
	}
};

class Stack
{
private:
	short mass[10]={0};
	short* m_mass = mass;
	short Counter=0;
	short& m_Counter = Counter;
public:
	void reset()
	{
		for (int i = 0; i < m_Counter; i++)
		{
			m_mass[i] = 0;
	    }
		m_Counter = 0;
	}

	bool push(short Meaning)
	{
		if (m_mass[0]==0)
		{
			m_mass[0] = Meaning;
			m_Counter++;
			return true;
		}
		else
		{
			if (m_Counter == 10)
			{
				return false;
			}
			else
			{	
				m_mass[m_Counter] = Meaning;
				m_Counter++;
				return true;
			}
		}
	}

	void pop()
	{
		if (m_Counter == 0)
		{
			std::cout << "Warning!!! The stack is empty!!!\n";
		}
		else
		{
			m_mass[m_Counter] = 0;
			m_Counter--;
		}
	}

	void print()
	{
		std::cout <<"( ";
		for (int i = 0; i < m_Counter; i++)
		{
			if(mass[i]!=0)
			std::cout << mass[i]<<" ";
		}
		std::cout << ")\n";
	}
};


int main()
{
	//Task1
	std::cout << "Task1:\n\n";
	Power A;      
	A.set(2, 3);
	A.calculate();
	//Task1
	//----------------------------------------------|
	//Task2
	std::cout << "\n\n\nTask2:\n\n";
	RGBA rgba(2,5,8,144);
	rgba.print();
	//Task2
	//----------------------------------------------|
	//Task3
	std::cout << "\n\n\nTask3:\n\n";
	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();

	//Task3
	return 0;
}