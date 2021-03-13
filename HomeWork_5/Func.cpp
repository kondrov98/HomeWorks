#include <iostream>
namespace Func_H_W
{

void func1(bool *mass)
	  {
	   for(int i=0;i<=8;i++)
	      {
 	       std::cout<<*(mass+i);
	      }
	   std::cout<<"\n";
	   for(int i=0;i<=8;i++)
	      {
	       *(mass+i)=*(mass+i)-1;	  
	      }
	  }
void func2(int *mass)
	  {
	   std::cout<<"\n";
	   for(int i=0;i<=7;i++)
	      {
	       if(i==0)
	         {
	          *mass=1;
		     }
	     else
		     {
	          *(mass+i)=*(mass+i-1)+3;
		     }  
	      }	
	  }

bool func3(int *mass)
	      {
	       int r=7;
           int f = 0;
	       int s1=*mass;
	       int s2=*(mass+r);
	       for(int i=1;i<=r-1;i++)
	          {
               if(i!=(r-1))
                 {
                  if(s1<=s2)
                    {
                     s1=s1+*(mass+i);
                     f = 0;
                    }
                else
                    {
                     s2=s2+*(mass+r-1); 
                     if(f==0)
                       {
                        i--;
                        f++;
                       }      
                    }    
                 }
             else
                 {
                  if(s1==s2)
                    {
                     return true;   
                    }   
                else
                    {
                     return false;   
                    }    
                 }       
              }
           return 0;   
          }

void func4(int *mass, int n)
	  {
	   int r=4;
	   int mass_f[5]{};
	   std::cout<<"\n";
	   for(int i=0;i<=r;i++)
	      {
	       if(i+n>r)
		     {
              mass_f[i+n-r-1]=*(mass+i);
 	         }
         else
            {
             mass_f[i+n]=*(mass+i);   
            }     	      
	      }
       for(int i=0;i<=r;i++)
          {
           std::cout<<mass_f[i];   
          }
      }
}