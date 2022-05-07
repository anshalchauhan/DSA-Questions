#include<bits/stdc++.h>
long findmax(long *v,int i,int n,vector<vector<long>> &hash,int buy)
{
	if(i == n) return 0;
	if(hash[i][buy] != -1) return hash[i][buy];
	long profit = 0;
	if(buy)
		profit = max(-v[i] + findmax(v,i+1,n,hash,0), findmax(v,i+1,n,hash,1));
	else
		profit = max(v[i] + findmax(v,i+1,n,hash,1), findmax(v,i+1,n,hash,0));
	return hash[i][buy] = profit;
}

long getMaximumProfit(long *v, int n)
{
    vector<vector<long>> hash(n, vector<long>(2,-1));
	return findmax(v,0,n,hash,1);
}
