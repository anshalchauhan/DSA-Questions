class Solution {
public:

    bool ispossible(int n,int k,vector<int>& stalls,int mid)
    {
        int count = 1;
        
        for(int i=1,j=0;i<n;i++)
        {
            if(abs(stalls[j] - stalls[i]) >= mid)
            {
                count++;
                j = i;
            }
            
            if(count == k) return true;
        }
        
        return false;
    }
    
    int solve(int n, int k, vector<int> &stalls) {
        
        //sort the array
        sort(stalls.begin(),stalls.end());
        int start = 0, end = stalls[n-1];
        int mid, ans = -1;
        
        while(start <= end)
        {
            mid = start + (end - start)/2;
            
            if(ispossible(n,k,stalls,mid))
            {
                ans = mid;
                start = mid + 1;
            }
            else
                end = mid - 1;
        }
        
        return ans;
    }
};