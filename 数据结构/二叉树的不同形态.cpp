#include <stdlib.h>
#include <stdio.h>

#define OK 1
#define ERROR -1

typedef struct TreeNode
{
    int data;
    struct TreeNode *lchild,*rchild;
}TreeNode,*Tree;

TreeNode* CreatTree(int level[],int in[],int left1,int right1,int left2,int right2)
{
    if (left2 > right2)
        return NULL;
    else
    {
        TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));

        int i=0, j=0;

        int flag = 0;
        for (i = left1; i <= right1; ++i) {
            for (j = left2; j <= right2; ++j) {
                if (level[i] == in[j]) {
                    flag = 1;
                    break;
                }
            }
            if (flag == 1)
                break;
        }


        root->data = level[i];
        root->lchild = CreatTree(level, in, left1 + 1, right1, left2, j - 1);
        root->rchild = CreatTree(level, in, left1 + 1, right1, j + 1, right2);
        return root;
    }
}

void postorder(Tree t)
{
    if(t)
    {
        postorder(t->lchild);
        postorder(t->rchild);
        printf("%d ",t->data);
    }
}

void preorder(Tree t)
{
    if(t)
    {
        printf("%d ",t->data);
        preorder(t->lchild);
        preorder(t->rchild);
    }
}

void printleaf(Tree t)
{
    if (t == NULL)
        return;
    else
    {
        if (t->lchild == NULL && t->rchild == NULL)
        {
            printf("%d ",t->data);
        }
        printleaf(t->lchild);
        printleaf(t->rchild);
    }
}

int main()
{
    int n;
    scanf("%d",&n);

    int level[n];
    int in[n];

    for (int i = 0; i < n; i++)
    {
        scanf("%d",&level[i]);
        if (i != n-1)
            scanf(" ");
    }
    for (int j = 0; j < n; j++)
    {
        scanf("%d",&in[j]);
        if (j != n-1)
            scanf(" ");
    }

    TreeNode* t = NULL;
    t = CreatTree(level,in,0,n-1,0,n-1);
    
    printleaf(t);
	printf("\n");
	preorder(t);
    printf("\n");
    postorder(t);
    
    return 0;
}


