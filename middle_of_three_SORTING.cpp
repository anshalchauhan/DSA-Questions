class Solution{
  public:
    int middle(int A, int B, int C){
        int sum = A+B+C;
        int max1 = max(A,max(B,C));
        int min1 = min(A,min(C,B));
        return sum - max1 - min1;
    }
};
