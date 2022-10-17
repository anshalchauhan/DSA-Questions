class Solution {
  public:
    vector<int> eventualSafeNodes(int V, vector<int> adj[]) {
        vector<int> indegree(V,0), ans, revadj[V];
        queue<int> q;
        
        for(int i=0;i<V;i++)
            for(auto a:adj[i])
            {
                revadj[a].push_back(i);
                indegree[i]++;
            }
                
        for(int i=0;i<V;i++)
            if(indegree[i] == 0)
                q.push(i);
            
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(auto a:revadj[node])
            {
                indegree[a]--;
                if(indegree[a] == 0) q.push(a);
            }
        }
        
        for(int i=0;i<V;i++)
            if(indegree[i] == 0)
                ans.push_back(i);
        
        return ans;
    }
};