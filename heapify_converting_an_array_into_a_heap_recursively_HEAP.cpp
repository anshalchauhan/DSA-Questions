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

void heapify(int arr[],int i,int n)
{
	int largest = i;
	int l = 2*i + 1;
	int r = 2*i + 2;

	if(l < n && arr[largest] < arr[l])
		largest = l;

	if(r < n && arr[largest] < arr[r])
		largest = r;

	if(largest != i)
	{
		swap(arr[largest],arr[i]);
		heapify(arr,largest,n);
	}
}

void buildheap(int arr[],int n)
{
	//Index of the last non-leaf node
	int start_index = n/2 - 1;

	for(int i=start_index;i>=0;i--)
		heapify(arr,i,n);
}

int main()
{
	start();

	int n;
	cin>>n;

	int arr[n];

	fr(i,0,n)
		cin>>arr[i];

	buildheap(arr,n);

	fr(i,0,n)
		cout<<arr[i]<<" ";

	return 0;
}