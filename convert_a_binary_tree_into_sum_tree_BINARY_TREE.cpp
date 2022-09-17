class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        solve(node);
    }
    
    int solve(Node* root)
    {
        if(!root) return 0;
        
        int left = solve(root->left);
        int right = solve(root->right);
        
        if(left == 0 && right == 0)
        {
            int x = root->data;
            root->data = 0;
            return x;
        }
        
        else if(!left) 
        {
            int x = root->data;
            root->data = right;
            return x + right;
        }
        
        else if(!right) 
        {
            int x = root->data;
            root->data = left;
            return x + left;
        }
        
        else 
        {
            int x = root->data;
            root->data = left + right;
            return x + left + right;
        }
    }
};