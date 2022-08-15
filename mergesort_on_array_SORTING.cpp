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

void merge(int a[],int b[],int l,int h,int mid)
{
	int i = l, j = mid+1, k = l;
	while(i<=mid && j<=h)
	{
		if(a[i] <= a[j])	b[k++] = a[i++];
		else b[k++] = a[j++];
	}

	while(i<=mid)	b[k++] = a[i++];

	while(j<=h)	b[k++] = a[j++];

	for(int ind = l;ind<=h;ind++)
		a[ind] = b[ind];
}

void mergesort(int a[],int b[],int l,int h)
{
	if(l<h)
	{
		int mid = (l+h)/2;
		mergesort(a,b,l,mid);
		mergesort(a,b,mid+1,h);
		merge(a,b,l,h,mid);
	}
}

int main()
{
	start();
	
	int n;
	cin>>n;

	int a[n],b[n]={0};

	fr(i,0,n)
		cin>>a[i];

	mergesort(a,b,0,n-1);

	fr(i,0,n)
		cout<<a[i]<<" ";

	return 0;
}