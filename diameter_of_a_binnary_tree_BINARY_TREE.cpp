class Solution {
  public:
    // Function to return the diameter of a Binary Tree.
    int diameter(Node* root) {
        int max1 = 0;
        diameter(root,max1);
        return max1;
    }
    
    int diameter(Node* root,int& max1)
    {
        if(root == NULL) return 0;
        int l = diameter(root->left,max1);
        int r = diameter(root->right,max1);
        max1 = max(max1,1+l+r);
        return 1 + max(l,r);
    }
};