class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>& edges){
	    vector<int> dist(n,1e8);
	    dist[0] = 0;
	    
	    int t = n;
	    while(t--)
	    {
	        bool flag = false;
	        for(auto a:edges)
	            if(dist[a[0]] + a[2] < dist[a[1]])
	            {
	                dist[a[1]] = dist[a[0]] + a[2];
	                flag = true;
	            }
	            
	        if(t == 0 && flag) return 1;
	    }
	    
	    return 0;
	}
};