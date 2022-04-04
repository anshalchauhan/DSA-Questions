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
	b[1] = 1;
	b[2] = 2;
	ll prev2 = 1;
	ll prev1 = 2;
	ll curr;

	for(int i=3;i<=n;i++)
	{
		curr = prev1 + prev2;
		prev2 = prev1;
		prev1 = curr;
	}
return curr;
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