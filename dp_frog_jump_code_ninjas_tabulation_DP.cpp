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

int main()
{
	start();
	int n;
	cin>>n;

	vector<int> b(n);
	vector<int> hash(n);

	fr(i,0,n)
		cin>>b[i];
	
	hash[0] = 0;

	for(int i=1;i<n;i++)
	{
		int fs = hash[i-1] + abs(b[i] - b[i-1]);
		
		int ss = INT_MAX;
		if(i > 1)
			ss = hash[i-2] + abs(b[i] - b[i-2]);

	hash[i] = min(fs,ss);
	}

	cout<<hash[n-1];

	return 0;
}