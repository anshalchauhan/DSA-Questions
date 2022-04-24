int findcount(vector<int>& a, int n, int p,int last,vector<vector<int>>& hash)
{
	if(n < 0 && p >= last) return 1;
	if(n < 0 || p < last) return 0;
	if(hash[n][last] != -1) return hash[n][last];
	int left =  findcount(a,n-1,p,a[n]*last,hash);
	int right = findcount(a,n-1,p,last,hash);
	return hash[n][last] = left + right;
}
int countSubsequences(vector<int>& a, int n, int p) {
    vector<vector<int>> hash(n, vector<int> (p+1,-1));
	return findcount(a,n-1,p,1,hash)-1;
}