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

int main()
{
	start();

	int n,k;
	cin>>n>>k;

	vector<int> nums(n);

	fr(i,0,n)
	 	cin>>nums[i];

	 	  for(int i = nums.size() - k, j = 0; j < k+1 ;j++, i++ )
         {
            if(i == nums.size())
            {
                int t;
                t = nums[j];
                nums[j].popback();
                
                nums.push_back(t);
            }
            
                int t;
                t = nums[j];
                nums[j] = nums [i];
                nums[i] = t;
         }

	return 0;
}