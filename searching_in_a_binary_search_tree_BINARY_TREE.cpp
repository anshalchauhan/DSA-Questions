bool findnode(Node* root, int x)
{
    if(root == NULL) return false;
    if(root->data == x) return true;
    if(root->data < x) return findnode(root->right,x);
    if(root->data > x) return findnode(root->left,x);
}

bool search(Node* root, int x) {
    return findnode(root,x);
}