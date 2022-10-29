class Solution {
  public:
    /*  Function to implement Bellman Ford
    *   edges: vector of vectors which represents the graph
    *   S: source vertex to start traversing graph with
    *   V: number of vertices
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V,1e8);
        dist[S] = 0;
        int n = V;
        
        while(n--)
        {
            bool flag = false;
            for(auto a:edges)
                if(dist[a[0]] + a[2] < dist[a[1]])
                {
                    dist[a[1]] = dist[a[0]] + a[2];
                    flag = true;
                }
            
            //running the loop n times (1 extra for checking negative cycle)
            if(n == 0 && flag) return {-1};
        }
        
        return dist;
        
    }
};