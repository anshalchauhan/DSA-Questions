class Solution
{
public:
    
    int sumOfLongRootToLeafPath(Node *root)
    {
        int maxlen = 0, maxsum = INT_MIN;
        solve(root,0,maxlen,0,maxsum);
        return maxsum;
    }
    
    void solve(Node* root, int len, int& maxlen, int sum, int &maxsum)
    {
        if(!root)
        {
            if(len > maxlen)    
            {
                maxlen = len;
                maxsum = sum;
            }
            
            else if(len == maxlen) maxsum = max(maxsum,sum);
            return;
        }
        
        sum += root->data;
        
        solve(root->left,len+1,maxlen,sum,maxsum);
        solve(root->right,len+1,maxlen,sum,maxsum);
    }
};