// Function Solve
Node* solve(Node* root,int X)
{
    if(!root) return NULL;
    else if(root->data > X) root->left = solve(root->left,X);
    else if(root->data < X) root->right = solve(root->right,X);
    else{
        if(!root->left && !root->right) return NULL;
        else if(root->left && !root->right) return root->left;
        else if(!root->left && root->right) return root->right;
        else{
            Node* temp = root->right;
            while(temp->left) temp = temp->left;
            temp->left = root->left;
            return root->right;
        }
    }
    
    return root;
}
// Function to delete a node from BST.
Node *deleteNode(Node *root, int X) {
    return solve(root,X);
}