class Solution{
  public:
    // The given root is the root of the Binary Tree
    // Return the root of the generated BST
    Node *binaryTreeToBST (Node *root)
    {
        vector<int> nodes;
        int i = 0;
        inorder(root,nodes,false,i);
        sort(nodes.begin(),nodes.end());
        inorder(root,nodes,true,i);
        return root;
    }
    
    void inorder(Node* root,vector<int>& nodes,bool change,int& i)
    {
        if(!root) return;
        inorder(root->left,nodes,change,i);
        nodes.push_back(root->data);
        if(change) root->data = nodes[i++];
        inorder(root->right,nodes,change,i);
    }
};