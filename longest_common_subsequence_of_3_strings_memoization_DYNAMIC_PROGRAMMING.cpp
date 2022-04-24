int lcs3(string &s1,string &s2,string &s3,int i,int j,int k,vector<vector<vector<int>>>& hash)
{
    if(i < 0 || j < 0 || k < 0) return 0;
    if(hash[i][j][k] != -1) return hash[i][j][k];
    if(s1[i] == s2[j] && s1[i] == s3[k]) return hash[i][j][k] = 1 + lcs3(s1,s2,s3,i-1,j-1,k-1,hash);
    return hash[i][j][k] = max(lcs3(s1,s2,s3,i-1,j,k,hash),max(lcs3(s1,s2,s3,i,j-1,k,hash),lcs3(s1,s2,s3,i,j,k-1,hash)));
}

int LCSof3 (string s1, string s2, string s3, int n1, int n2, int n3)
{
    vector<vector<vector<int>>> hash(n1,vector<vector<int>> (n2,vector<int> (n3,-1)));
    return lcs3(s1,s2,s3,n1-1,n2-1,n3-1,hash);
}
