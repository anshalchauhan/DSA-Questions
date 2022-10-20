class Solution {
  public:
    vector<int> shortestPath(int n,int m, vector<vector<int>>& edges){
        vector<int> ans(n,1e9), topo, visited(n,0);
        vector<pair<int,int>> adj[n];
        stack<int> st;
        
        //creating graph, adjoint list
        for(int i=0;i<m;i++)
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs(i,visited,adj,st);
        
        while(!st.empty())
        {
            topo.push_back(st.top());
            st.pop();
        }
        //putting source node as 0 (given in question)
        ans[0] = 0;
        for(int i=0;i<n;i++)
        {
            int prevnode = topo[i];
            int prevdistance = ans[prevnode];
            
            if(prevdistance == 1e9) continue; //not taking node which is not connected to source
            for(auto a:adj[prevnode])
            {
                int node = a.first;
                int distance = a.second;
                if(ans[node] > prevdistance + distance)
                    ans[node] = prevdistance + distance;
            }
        }
        
        for(int i=0;i<n;i++)
            if(ans[i] == 1e9)
                ans[i] = -1;
        
        return ans;
    }
    
    void dfs(int node,vector<int>& visited,vector<pair<int,int>> adj[],stack<int>& st)
    {
        visited[node] = 1;
        
        for(auto a:adj[node])
        {
            int v = a.first;
            if(!visited[v])
                dfs(v,visited,adj,st);
        }
        
        st.push(node);
    }
};