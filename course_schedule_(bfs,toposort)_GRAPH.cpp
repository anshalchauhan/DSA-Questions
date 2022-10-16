class Solution
{
  public:
    vector<int> findOrder(int n, int m, vector<vector<int>> prerequisites) 
    {
        vector<int> ans,priority(n,0);
        vector<int> adj[n];
        queue<int> q;

        for(int i=0;i<m;i++)
        {
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
            priority[prerequisites[i][0]]++;
        }
        
        for(int i=0;i<n;i++)
            if(priority[i] == 0)
                q.push(i);
        
        while(!q.empty())
        {
            int node = q.front();
            ans.push_back(node);
            q.pop();
            
            for(auto a:adj[node])
            {
                priority[a]--;
                if(priority[a] == 0) q.push(a);
            }
        }
        
        if(ans.size() != n) ans.clear();
        
        return ans;
    }
};