Node* solve(int post[],int start,int end)
{
    if(end < start) return NULL;
    Node* root = new Node(post[end]);
    
    int i;
    for(i=end-1;i>=0;i--)
        if(post[i] < post[end]) break;
        
    root->left = solve(post,start,i);
    root->right = solve(post,i+1,end-1);
    return root;
}

Node *constructTree (int post[], int size)
{
    return solve(post,0,size-1);
}