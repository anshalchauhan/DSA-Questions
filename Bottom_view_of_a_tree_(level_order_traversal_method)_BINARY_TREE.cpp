class Solution {
  public:
            
    vector<int> bottomView(Node *root)
    {
        vector<int> ans;
        map<int,vector<int>> nodes;
        queue<pair<Node*,int>> que;
        que.push({root,0});
        
        while(!que.empty())
        {
            auto p = que.front();
            que.pop();
            Node* root1 = p.first;
            int x = p.second;
            nodes[x].push_back(root1->data);
            
            if(root1->left) que.push({root1->left,x-1});
            if(root1->right) que.push({root1->right,x+1});
        }
        
        for(auto i:nodes)
        {
            int size = i.second.size();
            ans.push_back(i.second[size-1]);
        }
        return ans;    
    }
};