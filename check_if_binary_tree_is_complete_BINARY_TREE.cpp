class Solution{
public:    
    bool isCompleteBT(Node* root){
        int count = countNodes(root);
        return solve(root,0,count);
    }
    
    int countNodes(Node* root)
    {
        if(!root) return 0;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }

    bool solve(Node* root,int index,int count)
    {
        if(!root)   return true;
        if(index >= count) return false;

        bool left = solve(root->left,2*index+1,count);
        bool right = solve(root->right,2*index+2,count);

        return left && right;   
    }
};