class Solution{
    public:
    Node* buildTree(int in[],int pre[], int n)
    {
        map<int,int> inorder_pos;
        for(int i=0;i<n;i++) inorder_pos[in[i]] = i;
        
        Node* root = solve(in,pre,0,n-1,0,n-1,inorder_pos);
        return root;
    }
    
    Node* solve(int in[],int pre[],int pstart,int pend,int istart,int iend,map<int,int>& inorder_pos)
    {
        if(pstart > pend || istart > iend) return NULL;
        
        Node* root = new Node(pre[pstart]);
        
        int inroot = inorder_pos[root->data];
        int numsleft = inroot - istart;
        
        root->left = solve(in,pre,pstart+1,pstart+numsleft,istart,inroot-1,inorder_pos);
        root->right = solve(in,pre,pstart+numsleft+1,pend,inroot+1,iend,inorder_pos);
        
        return root;
    }
};