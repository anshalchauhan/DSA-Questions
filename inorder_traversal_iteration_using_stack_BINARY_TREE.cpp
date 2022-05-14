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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;  
        if(root == nullptr) return ans;
        
        TreeNode* root1 = root;
        stack<TreeNode*> st;
        
        while(true)
        {
            if(root1 != NULL)
            {
                st.push(root1);
                root1 = root1->left;
            }
            
            else
            {
                if(st.empty()) break;
                root1 = st.top();
                st.pop();
                ans.push_back(root1->val);
                root1 = root1->right;
            }
        }
        return ans;
    }
};