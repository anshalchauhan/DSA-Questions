#include<bits/stdc++.h>
#define fr(i,x,n) for(int i=x;i<n;i++)
typedef long long int ll;
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int fib(int n)
{
	if(n==1 || n==2)
		return 1;

	return fib(n-1) + fib(n-2);
}


int main()
{
	start();

	int n;
	cin>>n;

	cout<<fib(n);

	return 0;
}