class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        vector<int> indegree(V,0);
        queue<int> q;
        
        for(int i=0;i<V;i++)
            for(auto a:adj[i])
                indegree[a]++;
        
        for(int i=0;i<V;i++)
            if(indegree[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto a:adj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0) q.push(a);
            }
        }
        
        for(int i=0;i<V;i++)
            if(indegree[i] != 0) return true;
            
        return false;
    }
};