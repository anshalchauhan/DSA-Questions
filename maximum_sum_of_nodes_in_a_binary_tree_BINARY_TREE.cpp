class Solution{
  public:
    //Function to return the maximum sum of non-adjacent nodes.
    int getMaxSum(Node *root) 
    {
        if(!root) return 0;
        pair<int,int> ans = solve(root);
        return max(ans.first,ans.second);
    }
    
    pair<int,int> solve(Node* root)
    {
        if(!root) return {0,0};
        
        pair<int,int> left = solve(root->left);
        pair<int,int> right = solve(root->right);
        
        pair<int,int> x;
        x.first = root->data + left.second + right.second;
        x.second = max(left.first,left.second) + max(right.first,right.second);
        
        return x;
    }
};