#include <iostream>
  int main ()
           {
	    extern int a, b, c, d; //The const qualifier does not allow variables from other files to be used with extern.
            std::cout<<(static_cast<float>(a)*(static_cast<float>(b)+(static_cast<float>(c)/static_cast<float>(d))))<<" - task 1 and task 3\n";// task 1 and task 3
            int r1=44;
            int g=((r1>21)?(r1-21)*2:r1-21);
            std::cout<<g<<" - task 2.1\n";// task 2.1
            r1=17;
            g=((r1>21)?(r1-21)*2:r1-21);
            std::cout<<g<<" - task 2.2\n";// task 2.1
	    int array3[3][3][3] = {{{1,2,3},
				   {4,5,6},
				   {7,8,9}},
				  {{10,11,12},
				   {13,14,15},
				   {16,17,18}},
				  {{19,20,21},
				   {22,23,24},
				   {25,26,27}}};
	    int* ar = &array3[0][0][0];
	    std::cout<<"Result: array3[1][1][1] ="<<array3[1][1][1]<<"; ar = "<<*(ar + 13)<<" - task 4\n";// task 4
           }
        