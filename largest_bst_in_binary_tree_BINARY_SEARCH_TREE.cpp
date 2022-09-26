class nodeinfo{
    public:
    int max1;
    int min1; 
    bool isbst;
    int size;
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        int count;
        solve(root,count);
    	return count;
    }
    
    nodeinfo solve(Node* root,int& count)
    {
        if(!root) return {INT_MIN,INT_MAX,true,0};
        
        nodeinfo left = solve(root->left,count);
        nodeinfo right = solve(root->right,count);
        
        nodeinfo curr;
        curr.size = left.size + right.size + 1;
        curr.max1 = max(root->data,right.max1);
        curr.min1 = min(root->data,left.min1);
        
        if(left.isbst && right.isbst && root->data > left.max1 && root->data < right.min1)
            curr.isbst = true;
        else
            curr.isbst = false;
            
        if(curr.isbst)
            count = max(count,curr.size);
        
        return curr;
    }
};