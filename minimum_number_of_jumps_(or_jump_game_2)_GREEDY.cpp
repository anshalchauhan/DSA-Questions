class Solution{
  public:
    int minJumps(int arr[], int n){
        if(n == 1) return 0;
        int maxReach = 0;
        int totalJumps = 0;
        int lastJumpIdx = 0;
        
        for(int i=0;i<n;i++)
        {
            maxReach = max(maxReach, i+arr[i]);
            if(i == lastJumpIdx)
            {
                lastJumpIdx = maxReach;
                totalJumps++;
                
                if(maxReach >= n-1) {
                    return totalJumps;
                }
            }
        }
        return -1;
    }
};