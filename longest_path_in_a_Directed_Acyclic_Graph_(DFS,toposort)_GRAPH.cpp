class Solution
{
    public:
    vector<int> maximumDistance(vector<vector<int>> edges,int n,int m,int src)
    {
        vector<int> ans(n,INT_MIN), topo, visited(n,0);
        vector<pair<int,int>> adj[n];
        stack<int> st;
        
        //creating graph, adjoint list
        for(int i=0;i<m;i++)
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
        
        for(int i=0;i<n;i++)
            if(!visited[i])
                dfs(i,visited,adj,st);
        
        
        ans[src] = 0;
        while(!st.empty())
        {
            int prevnode = st.top();
            st.pop();
            int prevdistance = ans[prevnode];
            
            if(prevdistance == INT_MIN) continue;
            
            for(auto a:adj[prevnode])
            {
                int node = a.first;
                int distance = a.second;
                if(ans[node] < prevdistance + distance)
                    ans[node] = prevdistance + distance;
            }
        }
    
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