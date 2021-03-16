#include <fstream>
#include <iostream>
#include <string>
using namespace std;


int main(int argc, char**argv)
	{

	 ofstream file_1("file_hw_1.txt");
	 file_1<<"Hellow, Hellow, Hellow, Hellow, Hellow, Hellow, Hellow, Hellow, Hellow, Hellow,Hellow, Hellow, Hellow, Hellow, Hellow!\n";
	 

	 ofstream file_2("file_hw_2.txt");
	 file_2<<"Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye,Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye, Goodbye!\n";
	 file_1.close();	 
	 file_2.close(); 

	 ifstream file_1_f("file_hw_1.txt"); 
	 ifstream file_2_f("file_hw_2.txt");


	 
	 string s;
	 unsigned int num;
	 string* mass1 = new string[num];
	 getline(file_1_f,s,'\n');
	 mass1[0]=s;
	 mass1[1]="\n";
	 getline(file_2_f,s,'\n');
	 mass1[2]=s;
	 ofstream file_3("file_hw_3.txt");
	 for (int i=0;i<num;i++)
	     {
	      file_3<<mass1[i];
             }
	 delete[] mass1;
	
	 return 0;
	}