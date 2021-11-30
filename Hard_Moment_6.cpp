#include <iostream>
#include <vector>
#include <tuple>
#include <mutex>
#include <chrono>
#include <thread>
#include <algorithm>


void PrintID()
{
	std::this_thread::sleep_for(std::chrono::seconds(3));
	std::cout << std::this_thread::get_id() << std::endl;
}


std::mutex m;

template <typename T>
void pcout(T message) //1 Task
{
	m.lock();
	std::cout << message << "\n";
	m.unlock();
}

int Task2(int i)      //2 Task
{
	int j = 1;
	while (i != 0)
	{
		j++;
		int f=0;
		for (int r = 2; r <= j; r++)
		{
			if ((j % r) == 0)
			{
				f++;
			}
		}
		if (f == 1)
			i--;	 
	}
	return j;
}

class people		   //3 Task
{
private:
	std::vector<std::pair<std::string, int>> Things_thief;
	std::vector<std::pair<std::string, int>> Things_owner;
public:
	people()
	{

	}

	void the_owner_s_things(std::pair<std::string, int> o)
	{
		Things_owner.push_back(o);
	}

	void the_thief_s_things(std::vector<std::pair<std::string, int>>& To)
	{
		std::sort(To.begin(), To.end(), [](std::pair<std::string, int>& o1, std::pair<std::string, int>& o2) 
		{
			return o1.second < o2.second;
		});
		Things_thief.push_back(*(To.end()-1));
		To.pop_back();
	}


	void print_owner()
	{
		m.lock();
		std::cout << "\nItems owner's: ";
		for (auto n : Things_owner)
			std::cout << "\nItem name: " << n.first << "    Item price: " << n.second <<"\n";
		m.unlock();
	}

	void print_thief()
	{
		m.lock();
		std::cout << "\nItems thief's: ";
		for (auto n : Things_thief)
			std::cout << "\nItem name: " << n.first << "    Item price: " << n.second << "\n";
		m.unlock();
	}

	std::vector<std::pair<std::string, int>>& Get_Things_owner()
	{
		return Things_owner;
	}


};


int main()
{
	std::string str = "Message\n";
	int r = 5674687;
	std::thread th1([&]() {pcout(str); });
	std::thread th2([&]() {pcout(r); });
	th1.detach();
	th2.detach();
	std::this_thread::sleep_for(std::chrono::seconds(3));

	int number;
	std::thread th3([&](auto i) {number = Task2(i); },100);
	th3.join();
	std::cout << "\nPrime number = " << number << "\n";

	people Owner;
	people Trief;

	std::thread Owner_th1([&]() {Owner.the_owner_s_things(std::make_pair("Wardrobe", 2000));});
	Owner_th1.detach();
	std::thread Owner_th2([&]() {Owner.the_owner_s_things(std::make_pair("Safe deposit", 5000)); });
	Owner_th2.detach();
	std::thread Owner_th3([&]() {Owner.the_owner_s_things(std::make_pair("Wallet", 300)); });
	Owner_th3.join();

	Owner.print_owner();

	std::thread Trief_th1([&]() {Trief.the_thief_s_things(Owner.Get_Things_owner()); });
	Trief_th1.detach();
	std::thread Owner_th4([&]() {Owner.the_owner_s_things(std::make_pair("Coin", 1)); });
	Owner_th4.join();
	std::thread Owner_th5([&]() {Owner.the_owner_s_things(std::make_pair("gold ingot", 20000)); });
	Owner_th5.join();
	std::thread Trief_th2([&]() {Trief.the_thief_s_things(Owner.Get_Things_owner()); });
	Trief_th2.join();
	Trief.print_thief();
	Owner.print_owner();

}