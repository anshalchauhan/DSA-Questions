#include<bits/stdc++.h>
long long typedef ll;
#define fr(i,x,n) for(ll i=x;i<n;i++)
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void fib(ll n,vector<ll>& b)
{
	b[0] = 0;
	b[1] = 1;
	for(int i=2;i<=n;i++)
		b[i] = b[i-1] + b[i-2];
}

int main()
{

	start();

	ll n;
	cin>>n;

	vector<ll> b(n,-1);

	fib(n,b);

	fr(i,0,n+1)
	 	cout<<b[i]<<" ";
	return 0;
}