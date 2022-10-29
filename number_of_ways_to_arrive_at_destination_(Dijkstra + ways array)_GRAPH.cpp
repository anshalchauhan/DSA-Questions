class Solution {
  public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<int> time_array(n,INT_MAX), ways(n,0);
        vector<pair<int,int>> adj[n];
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        int mod = (int)(1e9 + 7);
        
        pq.push({0,0});
        time_array[0] = 0;
        ways[0] = 1;
        
        //creating the adjacency list
        for(auto a:roads)
        {
            adj[a[0]].push_back({a[1],a[2]});
            adj[a[1]].push_back({a[0],a[2]});
        }
        
        while(!pq.empty())
        {
            int total_time = pq.top().first;
            int prevnode = pq.top().second;
            pq.pop();
            
            for(auto a:adj[prevnode])
            {
                int node = a.first;
                int current_time = a.second;
                //First time the node is reached
                if(time_array[node] > current_time + total_time)
                {
                    time_array[node] = current_time + total_time;
                    pq.push({time_array[node],node});
                    ways[node] = ways[prevnode];
                }
                
                //Next time the node is reached
                else if(time_array[node] == current_time + total_time)
                    ways[node] = (ways[node] + ways[prevnode]) % mod;
            }
        }
        
        return ways[n-1] % mod;
    }
};