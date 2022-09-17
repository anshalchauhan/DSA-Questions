int ancestor(Node* root, int k,int node,int &ans)
{
    if(!root) return 0;
    if(root->data == node) return 1;
    
    int leftans = ancestor(root->left,k,node,ans);
    int rightans = ancestor(root->right,k,node,ans);
    
    int x = leftans + rightans + 1;
    
    if(x-1 == k) ans = root->data;
    
    if(!leftans && !rightans) return 0;
    return x;
}

int kthAncestor(Node *root, int k, int node)
{
    int ans = -1;
    ancestor(root,k,node,ans);
    return ans;
}