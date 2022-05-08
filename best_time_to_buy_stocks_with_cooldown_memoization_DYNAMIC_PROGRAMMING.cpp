int findmax(vector<int>& p,int n,int i,int buy,vector<vector<int>>& hash) 
{
	if(i >= n) return 0;
	if(hash[i][buy] != -1) return hash[i][buy];
	int profit = 0;
	if(buy) profit = max(-p[i] + findmax(p,n,i+1,0,hash),findmax(p,n,i+1,1,hash));
	else profit = max(p[i]+findmax(p,n,i+2,1,hash),findmax(p,n,i+1,0,hash));
	return hash[i][buy] = profit; 
}
int stockProfit(vector<int> &p){
	int n = p.size();
    vector<vector<int>> hash(n,vector<int>(2,-1));
	return findmax(p,n,0,1,hash);
}