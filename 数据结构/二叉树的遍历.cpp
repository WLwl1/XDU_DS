//二叉树先序遍历算法 - 根 左 右
 
int PreOrderTraverse(BiTree T){
 
    if( T ==   NULL){       //若是空二叉树，则直接返回0
 
        return 1;
 
    }else{
 
        visit(T);       //访问根节点（自定义visit()方法，比如获取该节点的数据域）
 
        PreOrderTraverse(T->lchild);        //遍历递归左子树
 
        PreOrderTraverse(T->rchild);        //遍历递归右子树
 
    }
 
}
 
 
 
 
 
//二叉树中序遍历算法 - 左 根 右
 
int InOrderTraverse(BiTree T){
 
    if( T == NULL ){        //若是空二叉树，则直接返回
 
        return 1;
 
    }else{
 
        InOrderTraverse(T->lchild);     //遍历递归左子树
 
        visit(T);       //访问根节点
 
        InOrderTraverse(T->rchild);     //遍历递归右子树
 
    }
 
}
 
 
 
 
 
//二叉树后序遍历算法 - 左 右 根
 
int PostOrderTraverse(BiTree T){
 
    if( T == NULL ){
 
        return 1;
 
    }else{
 
        PostOrderTraverse(T->lchild);       //遍历递归左子树
 
        PostOrderTraverse(T->rchild);       //遍历递归右子树
 
        visit(T);       //访问根节点
 
    }
 
}

void FloorPrint_QUEUE(pTreeNode &Tree) //层序遍历_队列实现
{
    queue < pTreeNode> q;
    if (Tree != NULL)
    {
        q.push(Tree);   //根节点进队列
    }

    while (q.empty() == false)  //队列不为空判断
    {
        cout << q.front()->data << " → "; 

        if (q.front()->leftPtr != NULL)   //如果有左孩子，leftChild入队列
        {
            q.push(q.front()->leftPtr);   
        }

        if (q.front()->rightPtr != NULL)   //如果有右孩子，rightChild入队列
        {
            q.push(q.front()->rightPtr);
        }
        q.pop();  //已经遍历过的节点出队列
    }
}
