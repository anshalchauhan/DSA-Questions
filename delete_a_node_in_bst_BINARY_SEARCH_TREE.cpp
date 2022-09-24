class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return update(root);
        
        TreeNode* ans = root;
        
        while(root)
        {
            if(root->val > key)
            {
                if(root->left && root->left->val == key)
                {
                    root->left = update(root->left);
                    break;
                }
                else
                    root = root->left;
            }
            
            else
            {
                if(root->right && root->right->val == key)
                {
                    root->right = update(root->right);
                    break;
                }   
                else
                    root = root->right;
            }
        }
        
        return ans;
    }
    
    TreeNode* update(TreeNode* root)
    {
        if(!root->left) return root->right;
        if(!root->right) return root->left;
        
        TreeNode* lastleft = findnode(root->right);
        lastleft->left = root->left;
        return root->right;
    }
    
    TreeNode* findnode(TreeNode* root)
    {
        if(!root->left) return root;
        return findnode(root->left);
    }
};