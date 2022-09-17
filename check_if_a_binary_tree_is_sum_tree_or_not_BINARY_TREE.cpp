class Solution
{
    public:
    bool isSumTree(Node* root)
    {
        bool ans = true;
        solve(root,ans);
        return ans;
    }
    
    int solve(Node* root, bool& ans)
    {
        if(!root) return 0;
        
        int left = solve(root->left,ans);
        int right = solve(root->right,ans);
        
        if(!left && !right) return root->data;
        else if(!left) 
        {
            if(root->data != right) ans = false;
            return root->data + right;
        }
        else if(!right) 
        {
            if(root->data != left) ans = false;
            return root->data + left;
        }
        
        else 
        {
            if(root->data != left + right) ans = false;
            return root->data + left + right;
        }
    }
};