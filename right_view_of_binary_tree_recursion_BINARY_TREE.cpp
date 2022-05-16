class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        findright(root,ans,0);
        return ans;
    }
    
    void findright(Node* root,vector<int>& ans,int level)
    {
        if(root == NULL) return;
        if(level == ans.size()) ans.push_back(root->data);
        findright(root->right,ans,level+1);
        findright(root->left,ans,level+1);
    }
};