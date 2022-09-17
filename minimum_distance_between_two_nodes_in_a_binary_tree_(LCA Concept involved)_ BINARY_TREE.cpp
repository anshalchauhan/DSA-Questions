class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* lcanode = lca(root,a,b);
        int adistance = distance(lcanode,a);
        int bdistance = distance(lcanode,b);
        return adistance + bdistance - 2;
    }
    
    Node* lca(Node* root, int a,int b)
    {
        if(!root) return NULL;
        if(root->data == a || root->data == b) return root;
        
        Node* leftans = lca(root->left,a,b);
        Node* rightans = lca(root->right,a,b);
        
        if(leftans && rightans) return root;
        else if(leftans && !rightans) return leftans;
        else if(!leftans && rightans) return rightans;
        else return NULL;
    }
    
    int distance(Node* lcanode,int ele)
    {
        if(!lcanode) return 0;
        if(lcanode->data == ele) return 1;
        
        int leftans = distance(lcanode->left,ele);
        int rightans = distance(lcanode->right,ele);
        
        if(!leftans && !rightans) return 0;
        return leftans + rightans + 1;
    }
};