class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max1 = INT_MIN;
        maxsum(root,max1);
        return max1;
    }
    
    int maxsum(TreeNode* root,int &max1)
    {
        if(root == nullptr) return 0;
        int l = maxsum(root->left,max1);
        int r = maxsum(root->right,max1);
        
        int p = max(root->val, max(root->val + l, root->val + r));
        max1 = max(max1,max(root->val +l +r,p));
        return p;
    }
};