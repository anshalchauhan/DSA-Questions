class Solution {
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        return solve(root,targetSum,0);
    }

    bool solve(TreeNode* root, int targetSum, int sum)
    {
        if(!root) return false;

        sum += root->val;
        bool left = solve(root->left,targetSum,sum);
        bool right = solve(root->right,targetSum,sum);

        if(!root->left && !root->right)
            if(sum == targetSum) return true;
        
        return left || right;
    }
};