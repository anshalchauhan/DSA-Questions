#include<bits/stdc++.h>
int frog_stairs(int i,vector<int>& b,vector<int>& hash)
{
	if(i == 0) return 0;
	if(hash[i] != -1) return hash[i];
	int left = frog_stairs(i-1,b,hash) + abs(b[i] - b[i-1]);
	int right = INT_MAX;
	if(i > 1) 
		right = frog_stairs(i-2,b,hash) + abs(b[i] - b[i-2]);
	
	return hash[i] = min(left,right);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> hash(n,-1);
 	return frog_stairs(n-1,heights,hash); 
}
