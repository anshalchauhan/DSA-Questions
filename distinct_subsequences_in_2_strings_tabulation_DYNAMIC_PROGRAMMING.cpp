class Solution {
public:
    int mod = (int)(1e9+7);
    int numDistinct(string s, string t) {
        int ls = s.size();
        int lt = t.size();
        
        if(ls < lt) return 0;
        vector<int> prev(ls+1,0), cur(lt+1,0);
        
        for(int i=1;i<=ls;i++)
        {
            prev[0] = cur[0] = 1;
            for(int j=1;j<=lt;j++)
            {
                if(s[i-1] == t[j-1]) cur[j] = (prev[j-1] + prev[j])%mod;
                else cur[j] = prev[j]%mod;
            }
            prev = cur;
        }
    return prev[lt];
    }
};