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

int sorting(int i,int j,vector<int>& a)
{
	int p = i;

	while(i < j)
	{
		while(a[i] <= a[p]) 
			i++;

		while(a[j] > a[p])
			j--;

		if(i < j) 
			swap(a[i],a[j]);
	}

	swap(a[p],a[j]);

	return j;
}

void quicksort(int i,int j,vector<int>& a)
{
	if(i < j)
	{
		int s = sorting(i,j,a);
		quicksort(i,s-1,a);
		quicksort(s+1,j,a);
	}
}


int main()
{
	start();

	int n;
	cin>>n;

	vector<int> a(n);

	fr(i,0,n) 
		cin>>a[i];

	quicksort(0,n-1,a);

	fr(i,0,n)
		cout<<a[i]<<" ";

	return 0;
}