class Solution{
  public:
    int sumK(Node *root,int k)
    {
        int count = 0;
        vector<int> paths;
        solve(root,k,count,paths);
        return count;
    }
    
    void solve(Node* root,int k,int& count,vector<int> paths)
    {
        if(!root) return;
        paths.push_back(root->data);
        
        solve(root->left,k,count,paths);
        solve(root->right,k,count,paths);
        
        int sum = 0;
        for(int i=paths.size()-1;i>=0;i--)
        {
            sum += paths[i];
            if(sum == k) count++;
        }
        
        return;
    }
};