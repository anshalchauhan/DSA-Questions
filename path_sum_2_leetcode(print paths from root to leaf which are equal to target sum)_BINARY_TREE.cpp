class Solution {
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> ans;
        vector<int> paths;
        solve(root,root,targetSum,paths,ans);
        return ans;
    }
    
    void solve(TreeNode* root,TreeNode* node,int targetSum,vector<int> paths,vector<vector<int>>& ans)
    {
        if(!node) return;
        paths.push_back(node->val);
        
        solve(root,node->left,targetSum,paths,ans);
        solve(root,node->right,targetSum,paths,ans);
  
        if(!node->left && !node->right)
        {
            int sum = 0;
            for(int i=paths.size()-1;i>=0;i--) sum += paths[i];
            if(sum == targetSum) ans.push_back(paths);
        }
        return;
    }
};