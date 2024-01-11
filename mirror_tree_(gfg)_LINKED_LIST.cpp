class Solution {
  public:
    // Function to convert a binary tree into its mirror tree.
    void mirror(Node* node) {
        // code here
        queue<Node*> q;
        Node* left = NULL, *right = NULL, *temp = NULL;
        q.push(node);
        
        while(!q.empty())
        {
            Node* node1 = q.front();
            q.pop();
            //swapping
            temp = node1->left;
            node1->left = node1->right;
            node1->right = temp;
            
            if(node1->left) q.push(node1->left);
            if(node1->right) q.push(node1->right);
        }
    }
};