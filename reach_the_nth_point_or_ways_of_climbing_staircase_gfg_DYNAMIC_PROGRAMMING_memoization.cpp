class Solution{
	public:
	int nthPoint(int n){
		    vector<int> ans(n+1,-1);
		    int m = 1000000007;
		    return stairs(n,ans,m);
		}
		
		int stairs(int n,vector<int>& ans,int m)
		{
		    if(n == 0) return ans[n] = 1;
		    if(n < 0) return 0;
		    if(ans[n] != -1) return ans[n];
		    
		    return ans[n] = (stairs(n-1,ans,m) + stairs(n-2,ans,m))%m;
		}
};
