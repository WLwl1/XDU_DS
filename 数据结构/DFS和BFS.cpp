void dfs(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    // 依次递归遍历它的左子树和右子树
    dfs(root->left);
    dfs(root->right);
}


void bfs(TreeNode* root) 
{
    // 创建一个队列
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) 
    {
        // 在每次循环中，使用 q.front() 获取队头节点，并将其出队
        TreeNode* node = q.front();
        q.pop();
 
        // 检查这个节点的左右子节点是否为空，如果不为空，就将它们加入队列中
        if (node->left != nullptr) 
        {
            q.push(node->left);
        }
        if (node->right != nullptr)
        {
            q.push(node->right);
        }
    }
}
