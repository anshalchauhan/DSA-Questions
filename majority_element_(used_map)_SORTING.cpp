class Solution{
  public:
     // Function to find majority element in the array
    // a: input array
    // size: size of input array
    int majorityElement(int a[], int n)
    {
        unordered_map<int,int> m1;
        int max1 = 0;
        int ele;
        for(int i=0;i<n;i++)
        {
            int temp = ++m1[a[i]];
            if(max1 < temp)
            {
                max1 = temp;
                ele = a[i];
            }
        }
        if(max1 > n/2) return ele;
        return -1;
    }
};