class Solution {
  public:
    bool isHeap(struct Node* tree) {
        int n = count_nodes(tree);
        return check_if_cbt(tree,n,0) && check_if_maxheap(tree);
    }
    
    int count_nodes(struct Node* root)
    {
        if(!root) return 0;
        return 1 + count_nodes(root->left) + count_nodes(root->right);
    }
    
    bool check_if_cbt(struct Node* root,int n,int index)
    {
        if(!root) return true;
        if(index >= n) return false;
        
        return check_if_cbt(root->left,n,2*index + 1) && check_if_cbt(root->right,n,2*index + 2);
    }
    
    bool check_if_maxheap(struct Node* root)
    {
        if(!root) return true;
        
        bool left = check_if_maxheap(root->left);
        bool right = check_if_maxheap(root->right);
        
        if(root->left)
            if(root->data < root->left->data)
                left = false;
        
        if(root->right)
            if(root->data < root->right->data)
                right = false;
        
        return left && right;
    }
};