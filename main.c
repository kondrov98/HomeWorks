#include <stdio.h>

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

int mediana(int* arr, int first, int last)
{
	int arr1[] = { *(arr + first),*(arr + (last - first) / 2),*(arr + last) };
	int pos[] = { first ,(last - first) / 2 ,last };
	for (int i = 0; i <= 2; i++)
	{
		for (int j = 0; j <= 1; j++)
		{
			if (arr1[j] > arr1[j + 1])
			{
				int t = arr[j];
				arr1[j] = arr1[j + 1];
				arr1[j + 1] = t;
				t = pos[j];
				pos[j] = pos[j + 1];
				pos[j + 1] = t;
			}
		}
	}
	return pos[1];
}



void qs(int* arr, int first, int last)
{
	int i = first;
	int j = last;
	int x = *(arr + (last - first) / 2);
	do
	{
	 while(*(arr + i) < x)
	 {
		 i++;
	 }
	 while(*(arr + j) > x)
	 {
		 j--;
	 }
	 if (i <= j)
	 {
		 int r = *(arr + i);
		 *(arr + i) = *(arr + j);
		 *(arr + j) = r;
		 i++;
		 j++;
	 }
	} 
	while (i<=j);
	if (i < last)
	{
		qs(*arr, i, last);
	}
	if (first < j)
	{
		qs(*arr, first, j);
	}
}

void Uluch_Sort(int* array, int first, int last)
{
	int i = first;
	int j = last;
	if (j - i <= 10)
	{
		sortInserts(array, j - i);
	}
	else
	{
		int p = mediana(array, first, last);
		int t = *(array+(j-i)/2);
		*(array + (j - i) / 2) = *(array+(j-i)/2);
		*(array + p) = t;
		printf("%i ", *(array + p));
		printf("%i ", p);
		qs(*array, first, last);
	}
}



int main()
{
	int arr[20] = { 3,0,5,14,2,6,1,9,10,7,8,12,14,11,15,18,14,17,13,16 };
	printf("Array = ");
	for (int i = 0; i < 20; i++)
	{
		printf("%i ", arr[i]);
	}
	printf("\n\n");
	Uluch_Sort(arr, 0, 19);
	for (int i = 0; i < 20; i++)
	{
		printf("%i ", arr[i]);
	}
	return 0;
}