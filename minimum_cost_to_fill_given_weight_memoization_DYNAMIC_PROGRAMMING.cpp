class Solution{
	public:
	int minimumCost(int cost[], int n, int w) 
	{ 
        vector<vector<int>> hash(n+1,vector<int>(w+1,-1));
        int ans = findmin(n,w,cost,hash);
        if(ans == 1e9) return -1;
        else return ans;
	} 
	
	int findmin(int n,int w,int cost[],vector<vector<int>>& hash)
	{
	    if(w == 0) return 0;
	    if(n == 1)
	    {
	        if(n <= w && cost[n-1] != -1) return (w/n)*cost[n-1];
	        else return 1e9;
	    }
	    if(hash[n][w] != -1) return hash[n][w];
	    int take = 1e9;
	    if(n <= w && cost[n-1] != -1) take = cost[n-1] + findmin(n,w-n,cost,hash);
	    int nottake = findmin(n-1,w,cost,hash);
	    return hash[n][w] = min(take,nottake);
	}
};