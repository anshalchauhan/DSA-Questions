class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        vector<int> adj[k], visited(k,0);
        stack<int> st;
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
            if(!visited[i])
                dfs(i,visited,adj,st);
                
        while(!st.empty())
        {
            ans += st.top() + 'a';
            st.pop();
        }
        
        return ans;
    }
    
    void dfs(int node,vector<int>& visited,vector<int> adj[],stack<int>& st)
    {
        visited[node] = 1;
        
        for(auto a:adj[node])
            if(!visited[a])
                dfs(a,visited,adj,st);
    
        st.push(node);
    }
};