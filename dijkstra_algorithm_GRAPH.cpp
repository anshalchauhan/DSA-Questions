class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector<int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> ans(V,INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,S});
        ans[S] = 0;
        
        while(!pq.empty())
        {
            int dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            
            for(auto it:adj[node])
            {
                int edgeweight = it[1];
                int adjnode = it[0];
                
                if(dis + edgeweight < ans[adjnode])
                {
                    ans[adjnode] = dis + edgeweight;
                    pq.push({dis + edgeweight,adjnode});
                }
            }
        }
        
        return ans;
    }
};