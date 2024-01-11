class Solution {
  public:
    int setBits(int N) {
        int count = 0;
        int remainder = 0;
        
        while(N > 0)
        {
            remainder = N%2;
            N = N/2;
            if(remainder == 1)
                count++;
        }
        
        return count;
    }
};