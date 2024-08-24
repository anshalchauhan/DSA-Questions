class Solution {
  public:
    int canReach(int A[], int N) {
        int reachable = 0;
        
        for(int i=0;i<N;i++)
        {
            if(i > reachable) return false;
            if(i+A[i] > reachable)  reachable = i+A[i];
        }
        
        return true;
    }
};