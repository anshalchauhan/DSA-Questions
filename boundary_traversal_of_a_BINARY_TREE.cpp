class Solution {
public:

    bool isleaf(Node *root)
    {
        return !root->left && !root->right;
    }
    
    void leftboundary(Node *root, vector<int>& ans)
    {
        Node *root1 = root->left;
        while(root1)
        {
            if(!isleaf(root1)) ans.push_back(root1->data);
            if(root1->left) root1 = root1->left;
            else root1 = root1->right;
        }
    }
    
    void leafnodes(Node *root, vector<int>& ans)
    {
        if(isleaf(root)) 
        {
            ans.push_back(root->data);
            return;
        }
        
        if(root->left) leafnodes(root->left,ans);
        if(root->right) leafnodes(root->right,ans);
    }
    
    void rightboundary(Node *root, vector<int>& ans)
    {
        vector<int> temp;
        Node *root1 = root->right;
        while(root1)
        {
            if(!isleaf(root1)) temp.push_back(root1->data);
            if(root1->right) root1 = root1->right;
            else root1 = root1->left;
        }
        
        for(int i=temp.size()-1;i>=0;i--)
            ans.push_back(temp[i]);
    }
    
    vector<int> boundary(Node *root)
    {
        vector<int> ans;
        if(root == NULL) return ans;
        if(!isleaf(root)) ans.push_back(root->data);
        leftboundary(root,ans);
        leafnodes(root,ans);
        rightboundary(root,ans);
        return ans;
    }
};