class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        int sum = 0;
        vector<int> visited(V,0);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> pq;
        pq.push({0,0});
        
        while(!pq.empty())
        {
            int prevnode = pq.top().second;
            int prevweight = pq.top().first;
            pq.pop();
            
            if(visited[prevnode]) continue;
            visited[prevnode] = 1;
            sum += prevweight;
            
            for(auto a:adj[prevnode])
            {
                int node = a[0];
                int weight = a[1];
                
                if(!visited[node])
                    pq.push({weight,node});
            }
        }
        
        return sum;
    }
};