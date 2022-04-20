class Solution{
  public:
    // arr[] : the input array
    // N : size of the array arr[]
    
    //Function to return length of longest subsequence of consecutive integers.
    int findLongestConseqSubseq(int a[], int N)
    {
      sort(a,a+N);
      int ans = 1;
      int max1 = INT_MIN;
      for(int i=0;i<N-1;i++)
      {
          if(a[i] == a[i+1]) continue;
          if(a[i] == a[i+1] - 1) 
          {
              ans++;
              continue;
          }
          if(a[i] != a[i+1] - 1)
          {
              max1 = max(ans,max1);
              ans = 1;
          }
      }
    max1 = max(ans,max1);
    return max1;
    }
};
