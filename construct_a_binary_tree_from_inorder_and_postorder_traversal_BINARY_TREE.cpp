Node *solve(int in[],int post[],int pstart,int pend,int istart,int iend,map<int,int>& inorder_pos)
{
    if(0 > pend || istart > iend) return NULL;
    
    Node *root = new Node(post[pend]);
    
    int inroot = inorder_pos[root->data];
    int numsright = iend - inroot;
    
    root->right = solve(in,post,pend-numsright,pend-1,inroot+1,iend,inorder_pos); 
    root->left = solve(in,post,pstart,pend-numsright-1,istart,inroot-1,inorder_pos);
    return root;
}

//Function to return a tree created from postorder and inoreder traversals.
Node *buildTree(int in[], int post[], int n) {
    map<int,int> inorder_pos;
    for(int i=0;i<n;i++) inorder_pos[in[i]] = i;
    Node* root =  solve(in,post,0,n-1,0,n-1,inorder_pos);
    return root;
}