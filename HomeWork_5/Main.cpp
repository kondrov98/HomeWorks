#include <iostream>
#include <math.h>
#include "Func.hpp"
using namespace Func_H_W;

int main()
	{
	 //task 1
	 bool mass1[]={1,0,0,1,1,1,0,0,0};
	 func1(mass1);
	 for(int i=0;i<=8;i++)
	      {
 	       std::cout<<mass1[i];
	      }
         //task 1
//---------------------------------------------------------
	 //task 2
	 int mass2[8]{};
	 func2(mass2);
	 std::cout<<"\n";
	 for(int i=0;i<=7;i++)
	      {
 	       std::cout<<mass2[i]<<" ";
	      }
	 //task 2
//---------------------------------------------------------
	 //task 3
	 int mass3[8]{4,1,5,3,2,3,5,3};
	 std::cout<<std::boolalpha<<"\n"<<func3(mass3)<<" ";
	 //task 3
//---------------------------------------------------------
	 //task 4
	 int mass4[5]{4,1,5,3,2};
     func4(mass4,2);
	 //task 4
//---------------------------------------------------------
	 //task 5
	 // I didn't understand
	 //task 5

	}