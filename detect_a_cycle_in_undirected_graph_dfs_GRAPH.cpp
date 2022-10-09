class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(dfs(i,-1,adj,visited))
                    return true;
        
        return false;
    }

    bool dfs(int node,int parent,vector<int> adj[],vector<int>& visited)
    {
        visited[node] = 1;
 
        for(auto i:adj[node])
        {
            if(!visited[i])
            {
                if(dfs(i,node,adj,visited))
                    return true;
            }
            else if(i != parent)
                return true;
        }
        return false;
    }

};