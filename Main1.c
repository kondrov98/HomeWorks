#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define false 1!=1
#define true 1==1
typedef int bollean;

typedef struct Node 
{
	int key;
	struct Node* left;
	struct Node* right;
} TreeNode;


typedef struct Check
{
	bollean condition;
	int Dif;
	struct Check* left;
	struct Check* right;
} Cb;





TreeNode* treeInsert(TreeNode* t, int data)
{
	TreeNode* NewNode;
	NewNode = (TreeNode*)malloc(sizeof(TreeNode));
	NewNode->key = data;
	NewNode->left = NULL;
	NewNode->right = NULL;
	TreeNode* current = t;
	TreeNode* parent = t;
	if (t == NULL)
	{
		t = NewNode;
	}
	else
	{
		while(current->key!=data)
		{
			parent = current;
			if (current->key > data)
			{
				current = parent->left;
				if (current == NULL) 
				{
					parent->left = NewNode;
					return t;
				}
			}
			else
			{
				current = parent->right;
				if (current == NULL)
				{
					parent->left = NewNode;
					return t;
				}
			}
		}
	}
}

Cb* binary_check(TreeNode* t)
{
	Cb* branch = (Cb*)malloc(sizeof(branch));

	if (t == NULL)
	{		
	 return branch;
    }
	else
	{
	 branch->left  = binary_check(t->left)  + 1;
	 branch->right = binary_check(t->right) + 1;
	 branch->Dif = abs(branch->right - branch->left);
	 if (branch->Dif > 2 || binary_check(t->left)==false|| binary_check(t->right)==false)
	 {
		 branch->condition = false;
	 }
	 else
	 {
		 branch->condition = true;
	 }
	 return branch;
	}
}




int main()
{
	
	TreeNode* ArrTree[50] = { 0 };
	Cb* branch = (Cb*)malloc(sizeof(branch));
	int TreeBalance = 0;
	float percent;
	for (int i = 0; i <= 49; i++)
	{
		TreeNode* tree = NULL;
		for (int j = 0; j <= 9999; j++)
		{
			ArrTree[i] = treeInsert(tree, rand());
		}
		TreeBalance = ((branch->condition == true) ? TreeBalance++ : TreeBalance);
	}
	percent = TreeBalance / 10000 * 100;
	return 0;
}