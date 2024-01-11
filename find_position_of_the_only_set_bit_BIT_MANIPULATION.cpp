class Solution {
  public:
    int findPosition(int N) {
        int count = 0;
        int ans = 0;
        
        while(N)
        {
            if(!(N&1)) count++;
            
            if(N&1)
            {
                if(ans != 0) return -1;
                ans = count + 1;
            }
            
            N = N >> 1;
        }
        
        if(ans == 0) return -1;
        return ans;
    }
};