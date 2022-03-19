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

int main()
{
	start();

	int n, max=INT_MIN, min=INT_MAX;
	cin>>n;

	vector<int> v(n);

	fr(i,0,n)
	{
		cin>>v[i];

		if(v[i] > max)
			max = v[i];

		if(v[i] < min)
			min = v[i];
	}

	cout<<"Minimum element is = "<<min<<"\n";
	cout<<"Maximum element is = "<<max;

	return 0;
}