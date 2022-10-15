class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> visited(V,0), pathvisited(V,0), ans;
        
        for(int i=0;i<V;i++)
            if(!visited[i])
                dfs(i,visited,pathvisited,adj);
        
        for(int i=0;i<V;i++)
            if(!pathvisited[i])
                ans.push_back(i);
        
        return ans;
    }
    
    bool dfs(int node,vector<int>& visited,vector<int>& pathvisited,vector<int> adj[])
    {
        visited[node] = 1;
        pathvisited[node] = 1;
        
        for(auto a:adj[node])
            {
                if(!visited[a])
                {
                    if(dfs(a,visited,pathvisited,adj)) return true;
                }
                else if(pathvisited[a]) return true;
            }
        
        pathvisited[node] = 0;
        return false;
    }
};