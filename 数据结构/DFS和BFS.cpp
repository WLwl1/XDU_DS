void dfs(TreeNode* root) 
{
    if (root == nullptr) 
    {
        return;
    }
    // ���εݹ����������������������
    dfs(root->left);
    dfs(root->right);
}


void bfs(TreeNode* root) 
{
    // ����һ������
    queue<TreeNode*> q;
    q.push(root);
    while (!q.empty()) 
    {
        // ��ÿ��ѭ���У�ʹ�� q.front() ��ȡ��ͷ�ڵ㣬���������
        TreeNode* node = q.front();
        q.pop();
 
        // �������ڵ�������ӽڵ��Ƿ�Ϊ�գ������Ϊ�գ��ͽ����Ǽ��������
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
