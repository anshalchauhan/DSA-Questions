class Solution
{
    public:
    //Function to return the lowest common ancestor in a Binary Tree.
    Node* lca(Node* root ,int n1 ,int n2 )
    {
        return solve(root,n1,n2);
    }
    
    Node* solve(Node* root,int n1,int n2)
    {
        if(!root) return NULL;
        if(root->data == n1 || root->data == n2) return root;
        
        Node* leftans = solve(root->left,n1,n2);
        Node* rightans = solve(root->right,n1,n2);
        
        if(leftans && rightans) return root;
        else if(leftans && !rightans) return leftans;
        else if(!leftans && rightans) return rightans;
        else return NULL;
    }
};