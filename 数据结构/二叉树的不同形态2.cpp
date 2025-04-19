#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
typedef struct BiTNode
{
	int data;
	struct BiTNode *lchild, *rchild;
}BiTNode, *LinkTree;
 
void LeafOrderTraverse(BiTNode* T);
void PreOrderTraverse(BiTNode* T);
void PostOrderTraverse(BiTNode* T);
BiTNode* Creat(int* level, int* pre, int n);
 
int main()
{
	int n, level[1024], in[1024];
	int i, j;
	scanf("%d", &n);
	for (i = 0; i < n; i++)
	{
		scanf("%d", &level[i]);
	}
	for (i = 0; i < n; i++)
	{
		scanf("%d", &in[i]);
	}
	BiTNode* T = Creat(level, in, n);
	LeafOrderTraverse(T);
	printf("\n");
	PreOrderTraverse(T);
	printf("\n");
	PostOrderTraverse(T);
	return 0;
}
 
void LeafOrderTraverse(BiTNode* T)
{
	if (T != NULL)
	{
		if(T->lchild == NULL && T->rchild == NULL)
			printf("%d ", T->data);
		LeafOrderTraverse(T->lchild);
		LeafOrderTraverse(T->rchild);
	}
}
 
void PreOrderTraverse(BiTNode* T)
{
	if (T != NULL)
	{
		printf("%d ", T->data);
		PreOrderTraverse(T->lchild);
		PreOrderTraverse(T->rchild);
	}
}
 
void PostOrderTraverse(BiTNode* T)
{
	if (T != NULL)
	{
		PostOrderTraverse(T->lchild);
		PostOrderTraverse(T->rchild);
		printf("%d ", T->data);
	}
}
 
BiTNode* Creat(int* level, int* in, int n)
{
	BiTNode* s;
	int* p;
	int k;
	if (n == 1)
	{
		s = (BiTNode*)malloc(sizeof(BiTNode));
		s->data = *level;
		s->lchild = s->rchild = NULL;
		return s;
	}
	for (p = in; p < in + n; p++)
	{
		if (*p == *level)
			break;
	}
	k = p - in;
	s = (BiTNode*)malloc(sizeof(BiTNode));
	s->data = *level;
	s->lchild = s->rchild = NULL;
	//构造新的层次序列
    //两个h是新层次结点的头结点，不带h是用来改变以存储结点的
	int* level_l_h = (int *)malloc(1024*sizeof(int));
	int* level_l = level_l_h;
	int* level_r_h = (int*)malloc(1024 * sizeof(int));;
	int* level_r = level_r_h;
	int* i;//i和j用来遍历层次和中序
	int* j;
	for (i = level; i < level + n; i++)
	{
		for (j = in; j < in + n; j++)
		{
			if (*i == *j && j - in < k)
			{
				*level_l = *i;
				level_l++;
				break;
			}
			else if (*i == *j && j - in > k)
			{
				*level_r = *i;
				level_r++;
				break;
			}
		}
	}
 
	if (k)
		s->lchild = Creat(level_l_h, in, k);
	if (n - k - 1)
		s->rchild = Creat(level_r_h, in + k + 1, n - k - 1);
	return s;
}
