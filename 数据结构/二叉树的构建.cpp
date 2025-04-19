struct BTNode {
    char val;
    BTNode *left;
    BTNode *right;
    BTNode(char c):val(c), left(NULL), right(NULL);
};

//根据前序遍历序列和中序遍历序列构造二叉树 
void CreateBT1(BTNode* &T, string pre, string in) {
    if(pre.length()==0) {
        T=NULL;
        return; 
    }
    char nodeVal = pre[0];
    int index = in.find(nodeVal);
    string lin = in.substr(0,index);
    string rin = in.substr(index+1);

    int leftChildLength = lin.length();
    string lpre = pre.substr(1,leftChildLength);
    string rpre = pre.substr(leftChildLength+1);

    T = new BTNode(nodeVal);
    CreateBT1(T->left,lpre,lin);
    CreateBT1(T->right,rpre,rin);
}

//根据中序遍历序列和后序遍历序列构造二叉树
void CreateBT2(BTNode* &T, string in, string post) {
    int len = post.length();
    if(len == 0) {
        T = NULL;
        return;
    }
    char nodeVal = post[len-1];
    int index = in.find(nodeVal);
    string lin = in.substr(0,index);
    string rin = in.substr(index+1);

    int leftChildLength = lin.length();
    int rightChildLength = rin.length();
    string lpost = post.substr(0,leftChildLength);
    string rpost = post.substr(leftChildLength,rightChildLength);

    T = new BTNode(nodeVal);
    CreateBT2(T->left,lin,lpost);
    CreateBT2(T->right,rin,rpost);

}

