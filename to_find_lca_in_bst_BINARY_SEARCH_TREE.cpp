void solve(Node* root,int n1,int n2,Node* &ans)
{
    if(root->data > n1 && root->data > n2) solve(root->left,n1,n2,ans);
    else if(root->data < n1 && root->data < n2) solve(root->right,n1,n2,ans);
    else ans = root;
    return;
}


//Function to find the lowest common ancestor in a BST. 
Node* LCA(Node *root, int n1, int n2)
{
   if(!root) return NULL;
   Node* ans;
   solve(root,n1,n2,ans);
   return ans;
}