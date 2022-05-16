class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* node) {
        
        vector<vector<int>> ans;
        vector<int> level;
        if(node == nullptr) return ans;

        queue<TreeNode*> q;
        q.push(node);

        while(!q.empty())
        {
            int size = q.size();
            for(int i=0;i<size;i++)
            {
                TreeNode* node1 = q.front();
                q.pop();
                level.push_back(node1->val);
                if(node1->right != nullptr) q.push(node1->right);
                if(node1->left != nullptr) q.push(node1->left);
            }
            reverse(level.begin(),level.end());
            ans.push_back(level);
            level.clear();
        }

        reverse(ans.begin(),ans.end());
        return ans;
    }
};