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

void swap(int *a,int *b)
{
	int t = *a;
	*a = *b;
	*b = t;
}


int main()
{
	start();

	int n;
	cin>>n;

	vector<int> v(n);

	fr(i,0,n)
		cin>>v[i];

	for(int i=0,j=n-1;i < n/2 ; i++,j--)
		swap(&v[i],&v[j]);

	fr(i,0,n)
		cout<< v[i] << " ";

	return 0;
}