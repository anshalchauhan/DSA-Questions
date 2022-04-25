#include<bits/stdc++.h>
int fmax(vector<int>& a,int n,vector<int>& hash)
{
	if(n < 0) return 0;
	if(n == 0) return a[n];
	if(n == 1) return a[n] + a[n-1];
	if(hash[n] != -1) return hash[n];
	return hash[n] = max(fmax(a,n-1,hash),
	max(a[n] + fmax(a,n-2,hash), a[n] + a[n-1] + fmax(a,n-3,hash)));
}
int maxSum(vector<int> &a, int n) 
{
	vector<int> hash(n,-1);
	return fmax(a,n-1,hash);
}