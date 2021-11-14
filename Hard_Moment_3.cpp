#include <iostream>
#include <list>
#include <array>


void arithmetic_mean(std::list<float>& l)
	{
	std::list<float>::iterator i;
	float sum = 0;
	int cursor = 0;
	i = l.begin();
	while (i != l.end())
		  {
		   sum += *i;
		   cursor++;
		  }
	l.push_back(sum/cursor);
	}


class matrics_3x3
{
private:
	std::array<int, 3> a;
	std::array<int, 3> b;
	std::array<int, 3> c;
	std::array<std::array<int,3>, 3> d;
public:
	matrics_3x3(std::array<int, 3>a,
			std::array<int, 3>b,
			std::array<int, 3>c )
			:a(a),b(b),c(c)
	{
		 
	}
	int matrix_determinant()
	{
		d = { a,
			  b,
			  c };
			return d[0][0] * d[1][1] * d[2][2] + d[0][1] * d[1][2] * d[2][0] + d[1][0] * d[2][1] * d[0][2]-
				  (d[0][2] * d[1][1] * d[2][0] + d[1][0] * d[0][1] * d[2][2] + d[0][0] * d[2][1] * d[1][2]);
	}
};



class Iterator_for_range_based
{
private:
	int* ptr;
	int mass_ptr_now;
	int V;

public:
	Iterator_for_range_based(int m_V) :V(m_V), mass_ptr_now(0)
	{
		ptr = new int[V];
	}

	void Plus_element(int r)
	{
		ptr[mass_ptr_now] = r;
		mass_ptr_now++;
	}

	int* begin()
	{
		return &ptr[0];
	}

	int* end()
	{
		return &ptr[mass_ptr_now];
	}

	~Iterator_for_range_based()
	{
		delete[] ptr;
	}
};