class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k], indegree(k);
        queue<int> q;
        string ans = "$";
        
        for(int i=0;i<n-1;i++)
        {
            string s1 = dict[i];
            string s2 = dict[i+1];
            int len = min(s1.size(),s2.size());
            
            for(int j=0;j<len;j++)
                if(s1[j] != s2[j])
                {
                    adj[s1[j] - 'a'].push_back(s2[j] - 'a');
                    break;
                }
        }
        
        for(int i=0;i<k;i++)
            for(auto a:adj[i])
                indegree[a]++;
        
        for(int i=0;i<k;i++)
            if(indegree[i] == 0)
                q.push(i);
            
        while(!q.empty())
        {
            int node = q.front();
            ans += (node + 'a');
            q.pop();
            
            for(auto a:adj[node])
                {
                    indegree[a]--;
                    if(indegree[a] == 0) q.push(a);
                }
        }
        
        return ans;
    }
};