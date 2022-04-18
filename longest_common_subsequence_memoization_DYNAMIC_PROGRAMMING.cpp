#include<bits/stdc++.h>
int longest(int i,int j,string &s,string &t,vector<vector<int>>& hash)
{
	if(i < 0 || j < 0) return 0;
	if(hash[i][j] != -1) return hash[i][j];
	int match = 0;
	int notmatch = 0;
	if(s[i] == t[j]) match = 1 + longest(i-1,j-1,s,t,hash);
	else notmatch = max(longest(i-1,j,s,t,hash),longest(i,j-1,s,t,hash));
	return hash[i][j] = match + notmatch;
}

int lcs(string s, string t)
{
	int i = s.size();
	int j = t.size();
	vector<vector<int>> hash(i,vector<int>(j,-1));
	return longest(i-1,j-1,s,t,hash);
}