#include<bits/stdc++.h>
int mod = (int)(1e9+7);
int	subcount(string &t,string &s,int i,int j,vector<vector<int>>& hash)
{
	if(j < 0) return 1;
	if(i < 0) return 0;
	if(hash[i][j] != -1) return hash[i][j];
	if(t[i] == s[j]) return hash[i][j] = (subcount(t,s,i-1,j-1,hash) + subcount(t,s,i-1,j,hash))%mod;
	return hash[i][j] = subcount(t,s,i-1,j,hash)%mod;
}
int subsequenceCounting(string &t, string &s, int lt, int ls) {
    vector<vector<int>> hash(lt,vector<int>(ls,-1));
	return subcount(t,s,lt-1,ls-1,hash);
} 