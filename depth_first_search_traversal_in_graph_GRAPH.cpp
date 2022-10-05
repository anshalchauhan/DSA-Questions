class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        dfs(adj,visited,ans,0);
        return ans;
    }
    
    void dfs(vector<int> adj[],vector<int>& visited,vector<int>& ans,int vertex)
    {
        visited[vertex] = 1;
        ans.push_back(vertex);
        
        for(auto a:adj[vertex])
            if(!visited[a])
                dfs(adj,visited,ans,a);
    }
};