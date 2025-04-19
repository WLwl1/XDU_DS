//��������������㷨 - �� �� ��
 
int PreOrderTraverse(BiTree T){
 
    if( T ==   NULL){       //���ǿն���������ֱ�ӷ���0
 
        return 1;
 
    }else{
 
        visit(T);       //���ʸ��ڵ㣨�Զ���visit()�����������ȡ�ýڵ��������
 
        PreOrderTraverse(T->lchild);        //�����ݹ�������
 
        PreOrderTraverse(T->rchild);        //�����ݹ�������
 
    }
 
}
 
 
 
 
 
//��������������㷨 - �� �� ��
 
int InOrderTraverse(BiTree T){
 
    if( T == NULL ){        //���ǿն���������ֱ�ӷ���
 
        return 1;
 
    }else{
 
        InOrderTraverse(T->lchild);     //�����ݹ�������
 
        visit(T);       //���ʸ��ڵ�
 
        InOrderTraverse(T->rchild);     //�����ݹ�������
 
    }
 
}
 
 
 
 
 
//��������������㷨 - �� �� ��
 
int PostOrderTraverse(BiTree T){
 
    if( T == NULL ){
 
        return 1;
 
    }else{
 
        PostOrderTraverse(T->lchild);       //�����ݹ�������
 
        PostOrderTraverse(T->rchild);       //�����ݹ�������
 
        visit(T);       //���ʸ��ڵ�
 
    }
 
}

void FloorPrint_QUEUE(pTreeNode &Tree) //�������_����ʵ��
{
    queue < pTreeNode> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //���ڵ������
    }

    while (q.empty() == false)  //���в�Ϊ���ж�
    {
        cout << q.front()->data << " �� "; 

        if (q.front()->leftPtr != NULL)   //��������ӣ�leftChild�����
        {
            q.push(q.front()->leftPtr);   
        }

        if (q.front()->rightPtr != NULL)   //������Һ��ӣ�rightChild�����
        {
            q.push(q.front()->rightPtr);
        }
        q.pop();  //�Ѿ��������Ľڵ������
    }
}
