class NodeInfo {
public:
    int sum;
    int minVal;
    int maxVal;

    NodeInfo(int sum,int minVal,int maxVal)
    {
        this->sum = sum;
        this->minVal = minVal;
        this->maxVal = maxVal; 
    }
};

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        NodeInfo info = solve(root,ans);
        return max(ans,info.sum);       
    }

    NodeInfo solve(TreeNode* root,int& ans)
    {
        if(!root) return NodeInfo(0,INT_MAX,INT_MIN);

        NodeInfo left = solve(root->left,ans);
        NodeInfo right = solve(root->right,ans);

        ans = max(ans,max(left.sum,right.sum));

        if(left.maxVal < root->val && right.minVal > root->val)
            return NodeInfo(root->val + left.sum + right.sum, min(left.minVal,      root->val), max(right.maxVal,root->val));

        return NodeInfo(max(left.sum,right.sum),INT_MIN,INT_MAX);
    }
};