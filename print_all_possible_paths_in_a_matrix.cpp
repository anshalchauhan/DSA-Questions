#include<bits/stdc++.h>
long long typedef ll;
#define fr(i,x,n) for(int i=x;i<n;i++)
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void printpath(int n,int m,vector<vector<int>>& grid,
	vector<vector<int>>& hash,
	vector<int> b,
	vector<vector<int>>& ans)
{
	if(n == 0 && m == 0)
	{
		b.push_back(grid[n][m]);
		reverse(b.begin(),b.end());
		ans.push_back(b);
		return;
	}

	if(n < 0 || m < 0) return;

	b.push_back(grid[n][m]);
	printpath(n-1,m,grid,hash,b,ans);
	printpath(n,m-1,grid,hash,b,ans);
}

int main()
{
	start();

	int n,m;
	cin>>n>>m;

	vector<vector<int>> grid = {{1,2,3},{4,5,6}};

	vector<vector<int>> hash(n, vector<int> (m,-1));
	vector<int> b;
	vector<vector<int>> ans; 

	printpath(n-1,m-1,grid,hash,b,ans);

	fr(i,0,ans.size())
	{
		fr(j,0,ans[0].size())
			cout<<ans[i][j]<<" ";
		cout<<"\n";
	}

	return 0;
}