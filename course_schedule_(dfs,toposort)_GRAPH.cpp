class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> ans, visited(n,0), pathvisited(n,0);
        vector<int> adj[n];

        for(int i=0;i<m;i++)
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            
	    for(int i=0;i<n;i++)
	        if(!visited[i])
	            if(dfs(i,visited,pathvisited,ans,adj)) return {};
	   
	    reverse(ans.begin(),ans.end());
	    
	    return ans;
	}
	
	bool dfs(int node,vector<int>& visited,vector<int>& pathvisited,vector<int>& ans,vector<int> adj[])
	{
	    visited[node] = 1;
	    pathvisited[node] = 1;
	    
	    for(auto a:adj[node])
	    {
	        if(!visited[a])
	            {
	                if(dfs(a,visited,pathvisited,ans,adj)) return true;
	            }
	        else if(pathvisited[a]) return true;
	    }
	    
	    ans.push_back(node);
	    pathvisited[node] = 0;
	    return false;
	}
};