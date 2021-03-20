#include <iostream>
#define Task_1(number, iskl) ((((number)>=0)&&((number)<iskl))||(((number)<=0)&&((number)>iskl)))
#define Task_2(array, string, column) *(*((array)+(column))+(string))
#define Task_3(array) (sizeof(array)/sizeof(array[0])) 
int main()
	{
	 if(Task_1(-7,-8)==true)
	   {
	    std::cout<<std::boolalpha<<Task_1(-7,-8)<<"\n";
	   }
	else
	   {
	    std::cout<<"false\n";
	   }

	if(Task_1(-9,-8)==true)
	   {
	    std::cout<<std::boolalpha<<Task_1(-7,-8)<<"\n";
	   }
	else
	   {
	    std::cout<<"false\n";
	   }

	int** mass=new int*[3];
	mass[0]=new int[3];
	mass[1]=new int[3];
	mass[2]=new int[3]; 
	mass[1][1]=654;
	std::cout<<Task_2(mass,1,1)<<"\n"; 

	delete[] mass[0];
	delete[] mass[1];
	delete[] mass[1]; 
	delete[] *mass;
	int ARR_T3[9];
	std::cout<<Task_3(ARR_T3);  
	}