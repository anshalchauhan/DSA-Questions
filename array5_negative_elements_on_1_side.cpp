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

	int n;
	cin>>n;

	vector<int> v(n),a,b;

	fr(i,0,n)
	{
		cin>>v[i];

		if(v[i] >= 0)
			a.push_back(v[i]);
		else
			b.push_back(v[i]);
	}

	fr(i,0,b.size())
		v[i] = b[i];


	for(int i=0,j=b.size(); i<a.size(); i++, j++)
		v[j] = a[i];

	fr(i,0,n)
		cout<<v[i]<<" ";

	return 0;
}