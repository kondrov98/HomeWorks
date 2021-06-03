#include <stdio.h>

typedef struct Node {
	int dat;
	struct Node *next;
} Node;

typedef struct {
	Node *head;
	int size;
} List;

void init(List* lst)
{
	lst->head = NULL;
	lst->size = 0;
}

void ins(List *lst, int data)
{
	Node *new = (Node*)malloc(sizeof(Node));
	new->dat = data;
	new->next = NULL;

	Node *current = lst->head;
	if (current == NULL)
	{
		lst->head = new;
		lst->size++;
		return;
	}
	else
	{
		while (current->next != NULL)
		{
			current = current->next;
			lst->size++;
		}
	}
}



Node* rm(List* lst, int data)
{
	Node* current = lst->head;
	Node* parent = NULL;
	if (current == NULL)
		return NULL;
	while (current->next != NULL && current->dat != data)
	{
		parent = current;
		current = current->next;
	}
	if (current->dat != data)
	{
		return NULL;
	}
	if (current == lst->head)
	{
		lst->head = current->next;
		lst->size--;
		return current;
	}
	parent->next = current->next;
	lst->size--;
	return current;
}

void printNode(Node *n)
{
	if (n == NULL)
	{
		printf("[]");
		return;
	}
	printf("[%d]", n->dat);
}

void printList(List *lst)
{
	Node *current = lst->head;
	if (current == NULL)
	{
		printNode(current);
	}
	else
	{
		do 
		{
			printNode(current);
			current = current->next;
		} 
		while (current != NULL);
	}
	printf("Size: %d \n", lst->size);
}

void copyList(List* lst,int* mass)
{
	Node* current = lst->head;
	
	
	for (int i = lst->size; i > 0 ; i--)
	{
		mass[i] = current->next->dat; 
    }
}






int main()
{
	List *lst = (List*) malloc(sizeof(List));
	init(lst);
	printList(lst);
	ins(lst, 6);
	printList(lst);
	ins(lst, 3);
	printList(lst);
	ins(lst, 76);
	printList(lst);
	ins(lst, 32);
	printList(lst);
	return 0;
}