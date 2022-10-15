class Solution {
public:
	bool isBipartite(int V, vector<int> adj[]){
	    vector<int> color(V,-1);
	    
	    for(int i=0;i<V;i++)
	        if(color[i] == -1)
	            if(!(bfs(i,color,adj))) return false;
	   
	    return true;
	}
	
	bool bfs(int node,vector<int>& color,vector<int> adj[])
	{
	    queue<int> q;
	    q.push(node);
	    color[node] = 0;
	    
	    while(!q.empty())
	    {
	        node = q.front();
	        q.pop();
	        
	        for(auto a:adj[node])
	        {
	            if(color[a] == -1)
	            {
	                q.push(a);
	                color[a] = !color[node];
	            }
	            else
	                if(color[a] == color[node]) return false;
	        }
	    }
	    
	    return true;
	}

};