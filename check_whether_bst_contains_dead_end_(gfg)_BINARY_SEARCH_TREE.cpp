class Solution{
  public:
    bool isDeadEnd(Node *root)
    {
        return checkDeadEnd(root,1,INT_MAX);
    }
    
    bool checkDeadEnd(Node* root,int low,int high)
    {
        if(!root) return false;
        if(low == high) return true;
        return checkDeadEnd(root->left,low,root->data-1) || checkDeadEnd(root->right,root->data+1,high);
    }
};