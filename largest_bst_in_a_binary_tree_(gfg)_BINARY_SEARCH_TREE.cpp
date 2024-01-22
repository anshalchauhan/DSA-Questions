class NodeInfo{
    public:
    int treeSize;
    int minVal;
    int maxVal;
    
    NodeInfo(int treeSize,int minVal,int maxVal)
    {
        this->treeSize = treeSize;
        this->minVal = minVal;
        this->maxVal = maxVal;
    }
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    int largestBst(Node *root)
    {
        NodeInfo ans = solve(root);
        return ans.treeSize;
    }
    
    NodeInfo solve(Node* root)
    {
        if(!root) return NodeInfo(0,INT_MAX,INT_MIN);
        
        NodeInfo left = solve(root->left);
        NodeInfo right = solve(root->right);
        
        if(left.maxVal < root->data && right.minVal > root->data)
            return NodeInfo(1 + left.treeSize + right.treeSize, 
            min(left.minVal,root->data), max(right.maxVal,root->data));
        
        return NodeInfo(max(left.treeSize,right.treeSize),
            INT_MIN,INT_MAX);
    }
};