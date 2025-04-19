#include <bits/stdc++.h>
//C/C++万能头，不能编译请自行替换
 
using namespace std;
 
//树结构体
typedef struct BiNode{
    char data;
    struct BiNode  *lchild,*rchild;
}BiNode,*Bitree;
 
//先序建立二叉树
void Setupbirtree(Bitree &T){
    char ch;
    cin>>ch;
    if(ch=='#') T=NULL;
    else {
        T=new BiNode;
        T->data=ch;
        Setupbirtree(T->lchild);
        Setupbirtree(T->rchild);
    }
}
//中序遍历
void InorderTraverse(Bitree &T){
    if(T==NULL) return;
    else{
        InorderTraverse(T->lchild);
        cout<<T->data<<" ";
        InorderTraverse(T->rchild);
    }
}
 
int main() {
    Bitree T;
    Setupbirtree(T);
    InorderTraverse(T);
    return 0;
}
