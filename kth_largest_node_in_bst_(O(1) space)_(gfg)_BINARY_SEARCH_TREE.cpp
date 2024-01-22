class Solution
{
    public:
    int kthLargest(Node *root, int K)
    {
        int count = inorderCount(root);
        count -= K-1;
        return inorderSolve(root,count);
    }
    
    int inorderCount(Node* root)
    {
        if(!root) return 0;
        return 1 + inorderCount(root->left) + inorderCount(root->right);
    }
    
    int inorderSolve(Node* root,int& count)
    {
        if(!root) return -1;
        int left = inorderSolve(root->left,count);
        count--;
        if(count == 0) return root->data;
        int right = inorderSolve(root->right,count);
        return max(left,right);
    }
};