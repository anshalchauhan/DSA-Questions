void inorder(TreeNode<int>* root,TreeNode<int>*& prev,TreeNode<int>*& head)
{
    if(!root) return;
    TreeNode<int>* left = root->left;
    TreeNode<int>* right = root->right;

    inorder(left,prev,head);
    if(!prev) head = root;
    else
    {
        prev->left = NULL;
        prev->right = root;
    }
    prev = root;
    inorder(right,prev,head);
}

TreeNode<int>* flatten(TreeNode<int>* root)
{
    TreeNode<int>* prev = NULL, *head = NULL;
    inorder(root,prev,head);
    prev->left = NULL;
    prev->right = NULL;
    return head;
}
