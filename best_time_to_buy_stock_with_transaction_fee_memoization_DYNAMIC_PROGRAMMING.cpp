int findmax(int n,int fee,vector<int>&p,int i,int buy,vector<vector<int>>& hash)
{
	if(i == n) return 0;
	if(hash[i][buy] != -1) return hash[i][buy];
	int profit = 0;
	if(buy) profit = max(-p[i] + findmax(n,fee,p,i+1,0,hash),findmax(n,fee,p,i+1,1,hash));
	else profit = max(p[i] -fee +findmax(n,fee,p,i+1,1,hash),findmax(n,fee,p,i+1,0,hash));
	return hash[i][buy] = profit;
}
int maximumProfit(int n, int fee, vector<int> &p) {
    vector<vector<int>> hash(n,vector<int>(2,-1));
	return findmax(n,fee,p,0,1,hash);
}
