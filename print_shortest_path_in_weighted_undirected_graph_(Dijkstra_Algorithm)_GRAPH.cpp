class Solution {
  public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> dist(n+1,INT_MAX), parent(n+1,-1), ans;
        vector<pair<int,int>> adj[n+1];
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        
        //creating graph adjacency list
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        
        dist[1] = 0;
        parent[1] = 1;
        pq.push({0,1});
        
        while(!pq.empty())
        {
            int prevdistance = pq.top().first;
            int prevnode = pq.top().second;
            pq.pop();
            
            for(auto a:adj[prevnode])
            {
                int node = a.first;
                int distance = a.second;
                if(dist[node] > prevdistance + distance)
                {
                    dist[node] = prevdistance + distance;
                    parent[node] = prevnode;
                    pq.push({dist[node],node});
                }
            }
        }
        
        if(dist[n] == INT_MAX) return {-1};
        int vertex = n;
        
        while(!(parent[vertex] == vertex))
        {
            ans.push_back(vertex);
            vertex = parent[vertex];
        }
        
        ans.push_back(1);
        
        reverse(ans.begin(),ans.end());
        
        return ans;
        }
};