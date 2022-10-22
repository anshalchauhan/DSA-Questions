class Solution {
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        vector<int> ans(N,INT_MAX), adj[N];
        queue<int> q;
        
        //creating undirected graph
        for(int i=0;i<M;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        //assigning source distance to itself as 0
        ans[src] = 0;
        dfs(src,ans,adj);
    
        for(int i=0;i<N;i++)
            if(ans[i] == INT_MAX)
                ans[i] = -1;
        
        return ans;
    }
    
    void dfs(int prevnode,vector<int>& ans,vector<int> adj[])
    {
        int distance = ans[prevnode];
        
        for(auto node:adj[prevnode])
        {
            if(ans[node] > distance + 1)
            {
                ans[node] = distance + 1;
                dfs(node,ans,adj);
            }
        }
    }
        
};