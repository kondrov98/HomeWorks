#include <stdio.h>
#define T int
#define SIZE 7
#define SZ 12

#define true 1==1
#define false 1 !=1

T Stack[SIZE];

typedef struct
{
	int pr;
	int dat;
} Node;

Node* arr[SZ];
int head;
int tail;
int items;



void outs(int pr, int dat) 
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->dat = dat;
	node->pr = pr;
	if (items == SZ)
	{
		arr[tail--] = 0;
		items--;
	}
	else
		if (items == 0)
		{
			printf("Queue is empty\n");
		}
		else
		{
			int i = 0;
			int idx = 0;
			for (i = tail; i > head; i--)
			{
			}

		}
}

int cursor = -1;

typedef int bollean;

bollean push(T data)
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

T pop()
{
	if (cursor != -1)
	{
		return Stack[cursor--];
    }
	else
	{
		printf("Stack is empty");
		return -1;
	}
}

void Perevod(int Ci)
{
	while (cursor != 7)
	{
		push(Ci % 2);
		Ci = Ci / 2;
    }
	while (cursor != -1)
	{
		printf("%i", pop());
	}
}





int main()
{
	int Ci = 165;
	Perevod(Ci);
	return 0;
}
