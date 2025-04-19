#include <iostream>
#include <queue>
using namespace std;

struct node
{
	int data;
	node * lchild;
	node * rchild;
};

node* newNode(int v) { 
	node*Node = new node; //申请一个node类型变量的地址空间
	Node->data = v; //结点权值为v
	Node->lchild = Node->rchild = NULL; //初始状态下无左右孩子
	return Node; //返回新节点的地址
}

void search(node*root,int x, int newdata){
	if (root == NULL) return; //考虑为空节点的可能性
	if (root->data == x) {
		root->data = newdata; //找到数据域为x的结点，把它修改为newdata
	}
	search(root->lchild, x, newdata);//往左子树搜索
	search(root->rchild, x, newdata);//往右子树搜索
}

void insert(node*& root, int x) {
	if (root == NULL) { //空树，即查找失败，插入结点（递归边界）
		root = newNode(x);
		return;
	}
	if (root->data > x) { //往左子树搜索
		insert(root->lchild, x);
	}
	else insert(root->rchild, x); //往右子树搜索
}

node*create(int data[], int n) {
	node* root = NULL;     //新建空根结点
	for (int i = 0; i < n; i++) {
		insert(root, data[i]); //将data[0]到data[n-1]插入二叉树
	}
	return root; //返回根节点
}

void preorder(node*root) { //先序遍历
	if (root == NULL) return; //到达空树，即递归边界
	cout << root->data << endl;; //访问根节点数据域
	preorder(root->lchild); //访问左子树
	preorder(root->rchild); //访问右子树
}

void inorder(node*root) { //中序遍历
	if (root == NULL) return; //到达空树，即递归边界
	inorder(root->lchild); //访问左子树
	cout << root->data << endl;; //访问根节点数据域
	inorder(root->rchild); //访问右子树
}
void postorder(node* root) { //后序遍历
	if (root == NULL) return; //到达空树，即递归边界
	preorder(root->lchild); //访问左子树
	preorder(root->rchild); //访问右子树
	cout << root->data << endl;; //访问根节点数据域
}

void LayerOrder(node* root) { //层序遍历
	queue<node*> q; //队列里面存的是地址 记得导入头文件<quene>
	q.push(root);  //将根节点入队
	while (!q.empty())  //退出条件为队列为空
	{
		node* now = q.front(); //取出队首元素
		cout << now->data << endl;
		q.pop();        //弹出队首元素
		if (now->lchild != NULL) q.push(now->lchild);//左子树非空则压入队列
		if (now->rchild != NULL) q.push(now->rchild);//右子树非空则压入队列
	}
}
int main() {
	int n = 10;
	int nums[10] = { 5,3,8,2,4,1,6,7,9,0 };
	node* root = create(nums, 10);
	//search(root, 7, 11); //查找替换
	preorder(root);//前序遍历
	//inorder(root);    //中序遍历
	//postorder(root);  //后序遍历
	//LayerOrder(root);  //层序遍历
	system("pause");
	return 0;
}

