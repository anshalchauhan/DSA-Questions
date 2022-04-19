class Solution{
  public:
    int longestPalinSubseq(string a) {
        int n = a.size();
        string b = string(a.rbegin(),a.rend());
        vector<vector<int>> hash(n, vector<int>(n,-1));
        return findmax(n-1,n-1,a,b,hash);
    }
    
    int findmax(int i,int j,string& a,string& b,vector<vector<int>>& hash)
    {
        if(i < 0 || j < 0) return 0;
        if(hash[i][j] != -1) return hash[i][j];
        if(a[i] == b[j]) return hash[i][j] = 1 + findmax(i-1,j-1,a,b,hash);
        return hash[i][j] = max(findmax(i-1,j,a,b,hash),findmax(i,j-1,a,b,hash));
    }
};