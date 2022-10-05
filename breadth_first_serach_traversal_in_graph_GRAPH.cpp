class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> ans;
        vector<int> visited(V,0);
        queue<int> q;
        q.push(0);
        visited[0] = 1;
        
        while(!q.empty())
        {
            int vertex = q.front();
            q.pop();
            ans.push_back(vertex);
            
            for(auto a:adj[vertex]) 
            {
                if(!visited[a])
                {
                    visited[a] = 1;
                    q.push(a);
                }
            }
        }
        
        return ans;
    }
};