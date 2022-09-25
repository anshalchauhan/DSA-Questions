void inorder(Node* root,Node*& pre,Node*& suc,int key)
{
    if(!root) return;
    inorder(root->left,pre,suc,key);
    if(root->key < key) pre = root;
    if(!suc && root->key > key) suc = root;
    inorder(root->right,pre,suc,key);
}

void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    pre = NULL;
    suc = NULL;
    inorder(root,pre,suc,key);
}