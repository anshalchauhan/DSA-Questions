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
    
    static bool compare(vector<int> &a,vector<int> &b) {      
        if(a[2]==b[2] && a[1]==b[1]) {
            return a[0]<b[0];
        }
        else if(a[2]==b[2]) {
            return a[1]<b[1];
        }
        return a[2]<b[2];
    }
    
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        vector<vector<int>> ans;
        vector<vector<int>> store;
        vector<int> level;
        inorder(root,store,0,0);
        sort(store.begin(),store.end(),compare);
        
        level.push_back(store[0][0]);
        
        for(int i=1;i<store.size();i++)
        {
            if(store[i][2] == store[i-1][2])
                level.push_back(store[i][0]);
            else
            {
                ans.push_back(level);
                level.clear();
                level.push_back(store[i][0]);
            }
        }
        
        ans.push_back(level); // for last sub vector
        return ans;
    }
    
    void inorder(TreeNode* root,vector<vector<int>>& store,int x,int y)
    {
        if(root == nullptr) return;
        inorder(root->left,store,x+1,y-1);
        store.push_back({root->val,x,y});
        inorder(root->right,store,x+1,y+1);
    }
};