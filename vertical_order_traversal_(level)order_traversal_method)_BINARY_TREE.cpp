class Solution
{
    public:
    //Function to find the vertical order traversal of Binary Tree.
    vector<int> verticalOrder(Node *root)
    {
        vector<int> ans;
        map<int,vector<int>> nodes;
        queue<pair<Node*, int>> que;
        
        que.push({root,0});
        
        while(!que.empty())
        {
            auto p = que.front();
            que.pop();
            Node *root = p.first;
            int x = p.second;
            nodes[x].push_back(root->data);
            
            if(root->left) que.push({root->left,x-1});
            if(root->right) que.push({root->right,x+1});
        }

        for(auto i:nodes)
                ans.insert(ans.end(), i.second.begin(), i.second.end());
        
        return ans;
    }
};