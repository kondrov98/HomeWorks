
#include <iostream>
#include <set>
#include <algorithm>
#include <map>
#include <vector>
#include <fstream>
#include "Timer.h"


template<typename T>
void function_1(typename std::multiset<T>::iterator begin, typename std::multiset<T>::iterator end)
{
	std::set<T> s;
	for (auto iter = begin; iter != end; iter++)
	{
		s.insert(*iter);
	}
	for (auto it : s)
		std::cout << it << ' ';
		std::cout << '\n';
}


void function_2( )
{
	std::multiset<std::string>  ms{""};
	std::string inp;
	std::string text;
	while (std::cin.peek() != '\n')
	{
		std::cin >> inp;
		text.append(" ");
		text.append(inp);	
	}
	inp = "";

	for (auto x : text)
	{
		if (x != '.' && x != '!' && x != '?')
		{
			inp += x;
		}
		else
		{
			inp += x;
			ms.insert(inp);
			inp = "";
		}
	}
	
	for (auto x : ms)
	{
	
	}
}


int main()
{
	std::multiset<std::string> ms1{" ", "fgyhjbf0", "gggg", "aaaa", "a", "qqqqq", "aaaa"};
	std::multiset<int> ms2{2, 5, 4, 7, 88,5, 1, 6, 3};
	
	function_1<std::string>(ms1.begin(), ms1.end());
	std::cout << '\n';
	function_1<int>(ms2.begin(), ms2.end());
	std::cout << '\n';

	function_2();
    return 0;
}