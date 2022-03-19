#include<bits/stdc++.h>
#define fr(i,x,n) for(int i=x;i<n;i++)
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}


int main()
{
	start();

	int n,m,t;
	cin>>n>>m;

	vector<int> a(n),b(m);
	vector<int> ans;
	map<int,int> map1,map2;

	fr(i,0,n)
	{
		cin>>a[i];
		map1[a[i]]++;
	}

	fr(i,0,m)
	{
		cin>>b[i];
		map2[b[i]]++;
	}

	for (auto x : map1)
	{
		if(map1[x.first] <= map2[x.first])
		{
			t = map1[x.first];
			while(t--)
				ans.push_back(x.first);
		}

		else
		{
			t = map2[x.first];
			while(t--)
				ans.push_back(x.first);
		}
	}

	// for (auto x : map1)
	// 	cout << x.first << " " << x.second << "\n"; 

	fr(i,0,ans.size())
		cout<< ans[i] << " ";

	return 0;
}