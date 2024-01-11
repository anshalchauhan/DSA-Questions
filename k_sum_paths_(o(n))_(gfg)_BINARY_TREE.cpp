class Solution{
  public:
    int sumK(Node *root,int k)
    {
        unordered_map<int,int> umap;
        int ans = 0;
        umap[0] = 1;
        solve(root,k,0,ans,umap);
        return ans;
    }
    
    void solve(Node* root,int k,int sum,int& ans,unordered_map<int,int>& umap)
    {
        if(!root) return;
        sum += root->data;
        
        if(umap[sum - k]) ans += umap[sum - k];
        umap[sum]++;
        
        solve(root->left,k,sum,ans,umap);
        solve(root->right,k,sum,ans,umap);
        
        umap[sum]--;
        return;
    }
};