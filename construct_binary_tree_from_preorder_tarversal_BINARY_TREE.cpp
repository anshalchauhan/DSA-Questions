struct Node* solve(int &i,int n,int pre[],char preLN[])
{
    if(i > n-1) return NULL;
    struct Node* root = new struct Node(pre[i]);
    
    if(preLN[i] == 'N')
    {
        i++;
        root->left = solve(i,n,pre,preLN);
        root->right = solve(i,n,pre,preLN);
    }
    else i++;
    
    return root;
}
// function should return the root of the new binary tree formed
struct Node *constructTree(int n, int pre[], char preLN[])
{
    int i=0;
    struct Node* root = solve(i,n,pre,preLN);
    return root;
}