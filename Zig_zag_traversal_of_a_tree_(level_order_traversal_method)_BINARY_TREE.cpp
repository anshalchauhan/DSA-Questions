class Solution{
    public:
    //Function to store the zig zag order traversal of tree in a list.
    vector <int> zigZagTraversal(Node* root)
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
    	    int lvl = p.second;
    	    nodes[lvl].push_back(root1->data);
    	    
    	    if(root1->left) que.push({root1->left,lvl+1});
    	    if(root1->right) que.push({root1->right,lvl+1});
    	}
    	
    	bool flag = true;
    	for(auto i:nodes)
    	{
    	    if(flag == true)
    	        {
    	            ans.insert(ans.end(),i.second.begin(),i.second.end());
    	            flag = false;
    	        }
    	    else
    	        {
    	            ans.insert(ans.end(),i.second.rbegin(),i.second.rend());
    	            flag = true;
    	        }
    	}
    	
    	return ans;
    }
};