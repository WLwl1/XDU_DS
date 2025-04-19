#include <bits/stdc++.h>
//C/C++����ͷ�����ܱ����������滻
 
using namespace std;
 
//���ṹ��
typedef struct BiNode{
    char data;
    struct BiNode  *lchild,*rchild;
}BiNode,*Bitree;
 
//������������
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
//�������
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
