class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        // Your code here
        solve(node);
    }
    
    int solve(Node* node)
    {
        if(!node) return 0;
        int left = solve(node->left);
        int right = solve(node->right);

        int val = node->data + left + right;
        node->data = left + right;
        return val;
    }
};