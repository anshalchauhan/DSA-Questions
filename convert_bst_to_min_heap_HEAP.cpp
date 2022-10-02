void inorder(BinaryTreeNode* root,vector<int>& nodes)
{
    if(!root) return;
    inorder(root->left,nodes);
    nodes.push_back(root->data);
    inorder(root->right,nodes);
}

void preorder(BinaryTreeNode*& root,vector<int>& nodes,int &i)
{
    if(!root) return;
    root->data = nodes[i++];
    preorder(root->left,nodes,i);
    preorder(root->right,nodes,i);
}
    
BinaryTreeNode* convertBST(BinaryTreeNode* root)
{
    if(!root) return NULL;
    vector<int> nodes;
    inorder(root,nodes);
    queue<BinaryTreeNode*> q;
    q.push(root);
    int i = 0;
    preorder(root,nodes,i);
   
    return root;
}