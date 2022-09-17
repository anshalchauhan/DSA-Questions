class Solution
{
    public:
    vector<vector<int>> printPaths(Node *root, int sum)
    {
        vector<vector<int>> ans;
        vector<int> paths;
        solve(root,root,sum,paths,ans);
        return ans;
    }
    
    void solve(Node* root,Node* node,int sum,vector<int> paths,vector<vector<int>>& ans)
    {
        if(!node) return;
        paths.push_back(node->key);
        
        solve(root,node->left,sum,paths,ans);
        solve(root,node->right,sum,paths,ans);
  
    
        int sum1 = 0;
        for(int i=paths.size()-1;i>=0;i--) sum1 += paths[i];
        if(sum == sum1) ans.push_back(paths);
        
        return;
    }
    
};