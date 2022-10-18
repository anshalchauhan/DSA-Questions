class Solution{
    public:
        vector<int> minimumTime(int n,vector<vector<int>> &edges,int m)
        {
            vector<int> ans(n,0), indegree(n+1,0), adj[n+1];
            queue<pair<int,int>> q;
            
            //Creating the adjoint graph list and updating indegree of the nodes
            for(int i=0;i<m;i++)
            {
                adj[edges[i][0]].push_back(edges[i][1]);
                indegree[edges[i][1]]++;
            }
            
            for(int i=1;i<n+1;i++)
                if(indegree[i] == 0)
                    q.push({i,1});
            
            while(!q.empty())
            {
                int node = q.front().first;
                int time = q.front().second;
                ans[node-1] = time;
                q.pop();
                
                for(auto a:adj[node])
                {
                    indegree[a]--;
                    if(indegree[a] == 0) q.push({a,time+1});
                }
            }
            
            return ans;
        }
};