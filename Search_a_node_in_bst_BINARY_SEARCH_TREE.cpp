class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        TreeNode* ans = NULL;
        solve(root,ans,val);
        return ans;
    }
    
    void solve(TreeNode* root,TreeNode* &ans,int val)
    {
        if(!root) return;
        solve(root->left,ans,val);
        solve(root->right,ans,val);
        
        if(root->val == val) ans = root;
        return;
    }
};