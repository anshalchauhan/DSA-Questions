class Solution {
public:
    int maxDepth(TreeNode* root) {
        queue<TreeNode*> q;
        int depth = 0;
        
        if(root == nullptr) return depth;
        q.push(root);
        while(!q.empty())
        {
            depth++;
            int size = q.size();
            
            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = q.front();
                q.pop();
                if(node1->left != NULL) q.push(node1->left);
                if(node1->right != NULL) q.push(node1->right);
            }
        }
    return depth;
    }
};