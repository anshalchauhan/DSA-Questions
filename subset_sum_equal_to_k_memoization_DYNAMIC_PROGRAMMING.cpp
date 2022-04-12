int findsum(int n,int k,vector<int>& arr,vector<vector<int>>& hash)
{
	if(k == 0) return 1;
	if(k < 0 || n < 0) return 0;
	if(hash[n][k] != -1) return hash[n][k];
	int left = findsum(n-1,k-arr[n],arr,hash);
	int right = findsum(n-1,k,arr,hash);
	return hash[n][k] = left+right;
}

bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> hash(n, vector<int> (k+1,-1));
	return findsum(n-1,k,arr,hash);
}