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

void sub(vector<int>& a,vector<int>& b,int i,int n)
{
	if(i >= n)
	{
		for(auto it : b)
			cout<<it<<" ";

		cout<<"\n";
		return;
	}

	b.push_back(a[i]);
	sub(a,b,i+1,n);
	b.pop_back();
	sub(a,b,i+1,n);
}


int main()
{
	start();

	int n;
	cin>>n;

	vector<int> a(n),b;

	fr(i,0,n)
		cin>>a[i];

	sub(a,b,0,n);

	return 0;
}