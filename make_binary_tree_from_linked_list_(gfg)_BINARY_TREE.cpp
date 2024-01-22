void convert(Node *head, TreeNode *&root) {
    if(!head) return;
    
    queue<TreeNode*> q;
    root = new TreeNode(head->data);
    q.push(root);
    
    while(head)
    {
        TreeNode* treeNode = q.front();
        q.pop();
        
        if(head->next) 
        {
            head = head->next;
            treeNode->left = new TreeNode(head->data);
            q.push(treeNode->left);
        }
        
        if(head->next)
        {
            head = head->next;
            treeNode->right = new TreeNode(head->data);
            q.push(treeNode->right);
        }
        
        if(q.empty()) break;
    }
}