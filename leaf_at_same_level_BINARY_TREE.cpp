class Solution{
  public:
    /*You are required to complete this method*/
    bool check(Node *root)
    {
        bool ans = true;
        int maxlen = -1;
        solve(root,ans,0,maxlen);
        return ans;
    }
    
    void solve(Node* root,bool& ans,int len,int& maxlen)
    {
        if(!root) return;
        
        solve(root->left,ans,len+1,maxlen);
        solve(root->right,ans,len+1,maxlen);
        
        if(!root->left && !root->right)
            {
                if(maxlen == -1)    maxlen = len;
                else if(len != maxlen) ans = false;
            }
        return;
    }
};