class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(int V, vector<int> adj[]) {
        vector<int> visited(V,0);
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                if(bfs(i,adj,visited))
                    return true;
        
        return false;
    }
    
    bool bfs(int src, vector<int> adj[],vector<int>& visited)
    {
        queue<pair<int,int>> q;
        q.push({src,-1});
        visited[src] = 1;
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            q.pop();
            
            for(auto i:adj[node])
            {
                if(!visited[i])
                {
                    q.push({i,node});
                    visited[i] = 1;
                }
                
                else if(parent != i)
                    return true;
            }
        }
        
        return false;
    }
};