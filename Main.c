#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void sortirovka_puzirkom(int* array1, int len)
{
	int le = len;
	for (int i = 0; i < len; i++)
	{
		for (int j = 0; j < le; j++)
		{
			if (*(array1 +  j) > *(array1 + (j + 1)))
			{
				int b = *(array1 + (j + 1));
				*(array1 + (j + 1)) = *(array1 + j);
				*(array1 + j) = b;
			}
		}
		le = le - 1;
	}
}

void Trabb_Prado_Knut(int* array2)
{
	int i = 0;
	while (i <= 10)
	{
		printf("\nEnter a number. After entering, press Enter.\n");
		scanf_s("%i",(array2 + i));
		i = i + 1;
	}
	while (i >= 6)
	{
		i = i - 1;
		int b = *(array2 + i);
		*(array2 + i) = *(array2 - i + 10);
		*(array2 - i + 10) = b;
	}
	i = 0;
	while (i <= 10)
	{
		double d = sqrt(fabs(*(array2 + i))) + 5 * pow(*(array2 + i), 3);
		if (d > 400)
		{
			printf("%i - th element of the sequence is greater than 400.",i);
		}
		i = i + 1;
	}
}


int main()
{
	int array1[11] = {0};

	int len = 8;

	int array2[3][3] = { {2,5,8},
						 {1,9,3},
						 {6,4,7} };

	for (int i = 0; i <= 2; i++)
	{
		printf("\n");
		for (int j = 0; j <= 2; j++)
		{
			printf("%i",array2[i][j]);
		}
	}
	printf("\n");
	sortirovka_puzirkom(array2, len);
	for (int i = 0; i <= 2; i++)
	{
		printf("\n");
		for (int j = 0; j <= 2; j++)
		{
			printf("%i", array2[i][j]);
		}
	}

	Trabb_Prado_Knut(array1);

	return 0;
}


