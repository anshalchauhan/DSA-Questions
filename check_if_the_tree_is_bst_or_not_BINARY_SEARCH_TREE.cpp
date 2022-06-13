class Solution
{
    public:
    //Function to check whether a Binary Tree is BST or not.
    bool isBST(Node* root) 
    {
        bool ans = true;
        vector<int> ele;
        inorder(root,ele);
        
        for(int i=1;i<ele.size();i++)
                if(ele[i] < ele[i-1]) ans = false;
    
        return ans;
    }
    
    void inorder(Node* root, vector<int>& ele)
    {
        if(root == NULL) return;
        inorder(root->left,ele);
        ele.push_back(root->data);
        inorder(root->right,ele);
    }
};