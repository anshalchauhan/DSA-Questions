class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans, indegree(V,0);
	    queue<int> q;
	    
	    for(int i=0;i<V;i++)
	        for(auto a:adj[i])
	            indegree[a]++;
	    
	    for(int i=0;i<V;i++)
	        if(indegree[i] == 0)
	            q.push(i);
	    
	    while(!q.empty())
	    {
	        int top = q.front();
	        ans.push_back(top);
	        q.pop();
	        
	        for(auto a:adj[top])
	        {
	            indegree[a]--;
	            if(indegree[a] == 0) q.push(a);
	        }
	    }
	    
	    return ans;
	}
};