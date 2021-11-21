#include <iostream>
#include <vector>
#include <array>
#include <algorithm>
#include <math.h>
#include <numeric>



template <typename T, typename container>
void insert_sorted(container& con, T& c)
{
	con.push_back(c);
	if (con.front() > con.back())
	{	
		std::sort(con.begin(), con.end(), [](T& l, T& r)
		{
			return l >= r;
		});
		
	}
	else
	{
		std::sort(con.begin(), con.end());
	}

}



void sign()
{
	std::vector<float> analog(100);
	std::generate(analog.begin(), analog.end(), []() {return (rand() % 101) / 10.0; });
	std::vector<int> figure(100);
	std::copy(analog.begin(), analog.end(), figure.begin());

	std::copy(analog.begin(), analog.end(), std::ostream_iterator<float>{std::cout, " "});
	std::cout << "\n\n";

	std::copy(figure.begin(), figure.end(), std::ostream_iterator<int>{std::cout, " "});
	std::cout << "\n\n";
	std::cout << "Minus:";
	std::vector<float> itog;
	std::transform(analog.begin(), analog.end(), figure.begin(), back_inserter(itog), std::minus<float>());
	std::copy(itog.begin(), itog.end(), std::ostream_iterator<float>{std::cout, " "});
	std::cout << "\n\n";
	std::cout << "Sqrt:";
	std::transform(itog.begin(), itog.end(), itog.begin(), [](float& i) {return i * i; });
	std::copy(itog.begin(), itog.end(), std::ostream_iterator<float>{std::cout, " "});
	std::cout << "\n\n";

	float summ = std::accumulate(itog.begin(), itog.end(), 0.0);
	std::cout << "Summ:"<<summ;


}


int main()
{
	std::vector<int> vec{1, 4, 6, 9, 11, 25};
	int c = 8;
	insert_sorted(vec, c);
	for (auto r : vec)
		std::cout << r << ' ';
	std::cout << '\n';
	std::vector<int> vec1{ 25, 11, 9, 6, 4, 1};
	insert_sorted(vec1, c);
	for (auto p : vec1)
		std::cout << p << ' ';
	std::cout << '\n';
	std::cout << '\n';
	sign();
}