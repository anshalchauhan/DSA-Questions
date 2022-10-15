class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<int> ans, visited(V,0);
	    stack<int> st;
	    
	    for(int i=0;i<V;i++)
	        if(!visited[i])
	            dfs(i,visited,st,adj);
	            
	    while(!st.empty())
	    {
	        ans.push_back(st.top());
	        st.pop();
	    }
	    
	    return ans;
	}
	
	void dfs(int node,vector<int>& visited,stack<int>& st,vector<int> adj[])
	{
	    visited[node] = 1;
	    
	    for(auto a:adj[node])
	        if(!visited[a])
	            dfs(a,visited,st,adj);
	            
	    st.push(node);
	}
};