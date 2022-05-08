#include<bits/stdc++.h>
int longestIncreasingSubsequence(int a[], int n)
{
	vector<int> ans;
	ans.push_back(a[0]);
    for(int i=1;i<n;i++)
	{
		if(a[i] > ans.back())	ans.push_back(a[i]);
		else 
		{
			int ind 
				= lower_bound(ans.begin(),ans.end(), a[i]) - ans.begin();
			ans[ind] = a[i];
		}
	}
    return ans.size();
}
