class Solution {
  public:
    int findCity(int n, int m, vector<vector<int>>& edges,int distanceThreshold) {
        vector<int> ans(n,0);
        int city, city_distance = 1e8;
        
        for(int i=0;i<n;i++)
        {
            vector<int> dist(n,1e8);
            int t = n;
            dist[i] = 0;
            
            while(--t)
            {
                for(auto a:edges)
                {
                    int u = a[0];
                    int v = a[1];
                    int wt = a[2];
                    
                    if(dist[u] + wt < dist[v])
                        dist[v] = dist[u] + wt;
                    
                    if(dist[v] + wt < dist[u])
                        dist[u] = dist[v] + wt;
                }
            }
            
            for(int j=0;j<n;j++)
            {
                if(i == j) continue;
                if(dist[j] <= distanceThreshold) ans[i]++;
            }
            
            
            //To check for smallest city
            if(ans[i] < city_distance)
            {
                city_distance = ans[i];
                city = i;
            }
            else if(ans[i] == city_distance)
                city = max(i,city);
        }
        
 
        return city;
    }
};