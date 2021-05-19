#include <stdio.h>
#include <math.h>

int main()
{
	printf("Enter a number.\n");
	int d;
	int l = 0;
	scanf_s("%d",&d);
	for (int i = 2; i < d; i++)
	{
		if (d % i == 0&&d!=2&&d!=1)
		{
		 printf("The number is not simple.\n");
		 l = 1;
		 break;
		}
	}
	if (l == 0)
	{
		printf("This number is prime.\n");
	}
	else
	{

	}
	return 0;
}

