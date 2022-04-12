class Solution {
  public:
    long long int count(int S[], int m, int n) {
        vector<vector<long long int>> hash(n+1, vector<long long int> (m,-1));
        return coinchange(S,m,n,0,hash);
    }
    
    long long int coinchange(int S[],int m,int n,int i,vector<vector<long long int>>& hash)
    {
        if(n == 0) return 1;
        
        if(i == m || n < 0) return 0;
        
        if(hash[n][i] != -1) return hash[n][i];
        
        long long int left = coinchange(S,m,n-S[i],i,hash);
        long long int right = coinchange(S,m,n,i+1,hash);
        return hash[n][i] = left+right;
    }
};