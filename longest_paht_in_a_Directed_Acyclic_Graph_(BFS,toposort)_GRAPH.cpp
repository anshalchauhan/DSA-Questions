class Solution
{
    public:
    vector<int> maximumDistance(vector<vector<int>> edges,int n,int m,int src)
    {
        vector<int> ans(n,INT_MIN), topo, indegree(n,0);
        vector<pair<int,int>> adj[n];
        queue<int> q;
        
        for(int i=0;i<m;i++)
        {
            adj[edges[i][0]].push_back({edges[i][1],edges[i][2]});
            indegree[edges[i][1]]++;
        }
        
        for(int i=0;i<n;i++)
            if(indegree[i] == 0)
                q.push(i);
            
        while(!q.empty())
        {
            int node = q.front();
            topo.push_back(node);
            q.pop();
            
            for(auto a:adj[node])
            {
                indegree[a.first]--;
                if(indegree[a.first] == 0) q.push(a.first);
            }
        }
        
        ans[src] = 0; //putting source node as 0 (given in question)
        for(int i=0;i<n;i++)
        {
            int node = topo[i];
	        if(ans[node] == INT_MIN) continue;	//not taking node which is not connected to source
		
            for(auto a:adj[node])
            {
                int v = a.first;
                int distance = a.second;
                
                if(ans[v] < distance + ans[node])
                    ans[v] = distance + ans[node];
            }
        }
       
        return ans;
    }
};