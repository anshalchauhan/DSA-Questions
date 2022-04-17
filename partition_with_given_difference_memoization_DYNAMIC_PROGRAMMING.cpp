int mod = (int)(1e9+7);
int finddif(int n,int sum,vector<int>& arr,vector<vector<int>>& hash)
{
	if(n == 0)
	{
		if(sum == 0 && arr[0] == 0) return 2;
		if(sum == 0 || arr[0] == sum) return 1;
		return 0;
	}
	if(hash[n][sum] != -1) return hash[n][sum];
	int take = 0;
	if(arr[n]<=sum) take = finddif(n-1,sum-arr[n],arr,hash);
	int nottake = finddif(n-1,sum,arr,hash);
	return hash[n][sum] = (take + nottake) % mod;
}
int countPartitions(int n, int d, vector<int> &arr) {
   	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];
	if(sum-d < 0 || (sum-d)%2 ) return 0;
	sum = (sum-d)/2; 
	vector<vector<int>> hash(n,vector<int>(sum+1,-1));
	return finddif(n-1,sum,arr,hash);
}