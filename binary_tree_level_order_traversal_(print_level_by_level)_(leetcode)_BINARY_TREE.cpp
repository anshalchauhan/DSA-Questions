/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;

        vector<int> level;
        queue<TreeNode*> q;
        q.push(root);
      
        while(!q.empty())
        {
            int size = q.size();

            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = q.front();
                q.pop();
                level.push_back(node1->val);
                if(node1->left) q.push(node1->left);
                if(node1->right) q.push(node1->right);
            }

            ans.push_back(level);
            level.clear();
        }
      
        return ans;
    }
};