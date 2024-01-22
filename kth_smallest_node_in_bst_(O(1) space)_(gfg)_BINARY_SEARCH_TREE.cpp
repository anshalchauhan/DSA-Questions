class Solution {
  public:
    // Return the Kth smallest element in the given BST
    int KthSmallestElement(Node *root, int K) {
        int count = K;
        return inorder(root,count);
    }
    
    int inorder(Node* root,int& count)
    {
        if(!root) return -1;
        int left = inorder(root->left,count);
        count--;
        if(count == 0) return root->data;
        int right = inorder(root->right,count);
        return max(left,right);
    }
};