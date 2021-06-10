#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define false 1!=1
#define true 1==1
#define SIZE 36
#define T int
typedef int boolean;

const int n = 6;
int matrix[6][6] =
{   {0, 1, 1, 0, 0, 0},
	{0, 0, 0, 1, 1, 1},
	{0, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0},
	{0, 0, 1, 0, 0, 0},
	{0, 0, 0, 0, 1, 0}, };

int visited[6] = { 0 };

void depthTravers(int st)
{
	int r;
	printf("%d", st);
	push(st);
	visited[st] = 1;
	for (r = 0; r < n; ++r) 
	{
		if (matrix[st][r] == 1 && !visited[r])
		{
			depthTravers(r);
		}
	}
}

void resetArr()
{
	for (int i = 0; i < n; ++i)
	{
		visited[i] = 0;
	}
}


T Stack[SIZE];
int cursor = -1;

boolean push(T data)
{
	if (cursor < SIZE)
	{
		Stack[++cursor] = data;
		return true;
	}
	else
	{
		printf("Stack overflow");
		return false;
	}
}


void depthTravers3(int st, int m)
{
	int r;
	printf("%d", st);
	visited[st] = 1;
	for (r = 0; r < n; ++r)
	{
		if (matrix[st][r] == 1 && !visited[r] && st==m)
		{
			depthTravers3(r,m);
		}
	}
}

void depthTravers_Smeg(int st)
{
	int m = st;
	depthTravers3(st, m);
}


int main()
{
	depthTravers(0);
	printf("\n");
	resetArr();
	depthTravers_Smeg(0);
	printf("\n");
	
	return 0;
}