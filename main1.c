#include <stdio.h>
#include <stdlib.h>
#include <math.h>

typedef char K;
typedef int SumCode;
#define false 1!=1
#define true 1==1
typedef int bollean;
#define T char*
#define SIZE 7
#define SZ 12

int htSize;






typedef struct OneLinkNode {
	char* dat;
	struct OneLinkNode* next;
} OneLinkNode;

void sortInserts(int* arr, int len)
{
	int pos, temp;
	for (int i = 1; i < len; i++)
	{
		temp = *(arr + i);
		pos = i - 1;
		while (pos >= 0 && *(arr + pos) > temp)
		{
			*(arr + pos + 1) = *(arr + pos);
			pos--;
		}
		*(arr + pos + 1) = temp;
	}
}


SumCode hash(T data)
{
	int i = 0;
	int r = 0;//сумма кодов символов
	while (data[i]!='\0')
	{
		r += data[i];
		i++;
	}	
	return r;
}

int GreedyAlg(int* mass, int Sum, int len)
{
	int i = len-1;
	int j = 0;
	sortInserts(mass, len);
	while (Sum != 0)
	{
		if (Sum >= mass[i])
		{
			Sum -= mass[i];
			j++;
		}
		else
		{
			i--;
		}
	}
	return j;
}



int main()
{
	char* arr;
	const int SIZ = 100;
	arr = (char*)malloc(sizeof(char)*SIZ);
	const int c = 5;
	int nominals[5] = { 10, 5, 50, 2, 1 };
	printf("Enter a string! \n");
	fgets(arr, 100, stdin);
	printf("Result Hesh-function: %d\n", hash(arr));
	printf("Minimum number of coins = %d ", GreedyAlg(nominals,98, c));
	


	return 0;
}