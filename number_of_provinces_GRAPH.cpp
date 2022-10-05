class Solution {
  public:
    int numProvinces(vector<vector<int>> adj, int V) {
        int ans = 0;
        vector<int> visited(V,0);
        vector<vector<int>> adjlist(V,vector<int> ());
        
        for(int i=0;i<V;i++)
            for(int j=0;j<V;j++)
                if(adj[i][j] == 1 && i != j)
                {
                    adjlist[i].push_back(j);
                    adjlist[j].push_back(i);
                }
        
        for(int i=0;i<V;i++)
            if(!visited[i])
            {
                ans++;
                dfs(adjlist,visited,i);
            }
            
        return ans;
    }
    
    void dfs(vector<vector<int>>& adjlist,vector<int>& visited,int vertex)
    {
        visited[vertex] = 1;
    
        for(auto a:adjlist[vertex])
                if(!visited[a])
                    dfs(adjlist,visited,a);
    }
};