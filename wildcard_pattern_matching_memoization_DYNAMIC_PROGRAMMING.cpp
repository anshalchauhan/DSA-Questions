#include<bits/stdc++.h>
bool match(int i,int j,string &p,string &t,vector<vector<int>>& hash)
{
	if(i < 0 && j < 0) return true;
	if(i < 0 && j >= 0) return false;
	if(j < 0 && i >= 0)
	{
		for(int k=i;k>=0;k--) if(p[k] != '*') return false;
		return true;
	}
	if(hash[i][j] != -1) return hash[i][j];
	if(p[i] == t[j] || p[i] == '?') return hash[i][j] = match(i-1,j-1,p,t,hash);
	if(p[i] == '*') return hash[i][j] = match(i-1,j,p,t,hash) | match(i,j-1,p,t,hash);
	return false;
}
bool wildcardMatching(string p, string t)
{
   	int i = p.size();
   	int j = t.size();
	vector<vector<int>> hash(i,vector<int>(j,-1));
	return match(i-1,j-1,p,t,hash);
}
