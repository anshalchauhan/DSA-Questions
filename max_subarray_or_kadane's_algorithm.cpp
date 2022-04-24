class Solution{
    public:
    // arr: input array
    // n: size of array
    //Function to find the sum of contiguous subarray with maximum sum.
    long long maxSubarraySum(int arr[], int n){
        
        long long int sum = 0;
        long long int max1 = arr[0];
        for(int i=0;i<n;i++)
        {
            sum += arr[i];
            if(sum > max1) max1 = sum;
            if(sum < 0) sum = 0;
        }
    return max1;
    }
};