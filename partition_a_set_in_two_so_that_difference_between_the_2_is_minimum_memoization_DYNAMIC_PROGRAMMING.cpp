int findmin(int n,int sum,int rsum,vector<int>& arr,vector<vector<int>>& hash)
{
	if(n == 0)	return abs(rsum - 2*sum);
	if(hash[n][sum] != -1) return hash[n][sum];
	int left = 0;
	if(arr[n] <= sum) left = findmin(n-1,sum-arr[n],rsum,arr,hash);
	int right = findmin(n-1,sum,rsum,arr,hash);
	return hash[n][sum] = min(left,right);
}

int minSubsetSumDifference(vector<int>& arr, int n)
{
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	
	vector<vector<int>> hash(n, vector<int> (sum+1,-1));
	return findmin(n-1,sum,sum,arr,hash);
}
