#include <stdio.h>
#include <math.h>

void Rec1(unsigned long a)
{
	if (a > 0)
	{
		int i = a % 2;
		a = a / 2;
		Rec1(a);
		printf("%i", i);
	}
}

void Rec2_3(unsigned long a, unsigned long b, unsigned long c, unsigned long d)
{
	if (b > 1)
	{
		if (d % 2 == 1)
		{
			a = a * c;
			b = b - 1;
			Rec2_3(a, b, c, d);
		}
		else
		{
			a = a * a;
			b = b / 2;
			Rec2_3(a, b, c, d);
		}
		
	}
	else
	{
		printf("%i", a);
	}
	
}


int main()
{
	unsigned long a,b,c,d;
	int i,j = 0;
	int mass[8][8]={{0,0,0,0,1,0,1,0},
					{0,0,0,1,0,0,0,0},
					{0,0,0,0,0,0,0,1},
					{0,0,0,0,0,1,0,0},
					{0,0,0,0,1,0,0,0},
					{0,1,0,0,0,0,1,0},
					{1,0,0,0,0,0,0,0},
					{0,0,1,0,0,0,0,0}};
	printf("Enter a number.\n");
	scanf_s("%i", &a);
	printf("Enter the power of this number.\n");
	scanf_s("%i", &b);
	printf("A number in binary form.\n");
	Rec1(a);
	printf("\nA number %i in the power %i of.\n",a,b);
	c = a;
	d = b;
	Rec2_3(a, b, c, d);
	//printf("\nChess king.Route.\n");
	return 0;
}