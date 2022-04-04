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

ll stairs(int n,vector<ll>& b)
{
	if(n == 0) return b[n] = 1;

	if(n < 0) return 0;

	if(b[n] != -1) return b[n];

	return b[n] = stairs(n-1,b) + stairs(n-2,b);
}

int main()
{
	start();

	int n;
	cin>>n;

	vector<ll> b(n+1,-1);

	cout<<stairs(n,b);

	return 0;
}