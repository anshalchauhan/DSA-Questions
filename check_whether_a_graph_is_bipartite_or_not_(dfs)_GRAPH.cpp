class Solution {
public:
	bool isBipartite(int V, vector<int> adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	        if(color[i] == -1)
	        {
	            color[i] = 0;
	            if(!(dfs(i,color,adj))) return false;
	        }
	   
	    return true;
	}
	
	bool dfs(int node,vector<int>& color,vector<int> adj[])
	{
	    int color1 = !color[node];
	    
	    for(auto a:adj[node])
	    {
	        if(color[a] == -1)
	        {
	            color[a] = color1;
	            if(!(dfs(a,color,adj))) return false;
	        }
	        
	        else    if(color[a] == color[node]) return false;
	    }
	    
	    return true;
	}

};