class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> visited(V,0), pathvisited(V,0);
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(dfs(i,visited,pathvisited,adj)) return true;
        
        return false;
    }
    
    bool dfs(int node,vector<int>& visited,vector<int>& pathvisited,vector<int> adj[]) 
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        
        for(auto a:adj[node])
        {
            if(!visited[a])
            {
                if(dfs(a,visited,pathvisited,adj) == true) return true;
            }
            else if(pathvisited[a]) return true;
        }
        
        pathvisited[node] = 0;
        return false;
    }
};