#include<bits/stdc++.h>
int findmin(int i,int j,string &s1,string &s2,vector<vector<int>>& hash)
{
	if(i < 0) return j+1;
	if(j < 0) return i+1;
	if(hash[i][j] != -1) return hash[i][j];
	if(s1[i] == s2[j]) return hash[i][j] = findmin(i-1,j-1,s1,s2,hash);
	return hash[i][j] = 1 + min(findmin(i-1,j,s1,s2,hash),min(findmin(i,j-1,s1,s2,hash)
	,findmin(i-1,j-1,s1,s2,hash)));
}
int editDistance(string s1, string s2)
{
    int i = s1.size();
	int j = s2.size();
	vector<vector<int>> hash(i,vector<int>(j,-1));
	return findmin(i-1,j-1,s1,s2,hash);
}