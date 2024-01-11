class Solution
{
  public:
    bool ispossible(int arr[],int n,int k,long long int mid)
    {
        int count = 1;
        long long int sum = 0;
        
        for(int i=0;i<n;i++)
        {
            if(sum + arr[i] <= mid)
                sum += arr[i];
            else
            {
                count++;
                if(count > k || arr[i] > mid)   return false;
                
                sum = arr[i];
            }
        }
        
        return true;    
    }
    
    long long minTime(int arr[], int n, int k)
    {
        long long int start = 0, end = 0, mid, ans = -1;
        long long int mod1 = pow(10,9) + 7;
        
        for(int i=0;i<n;i++)
            end += arr[i];
        
        while(start <= end)
        {
            mid = start + (end - start)/2;
            
            if(ispossible(arr,n,k,mid))
                {
                    ans = mid;
                    end = mid - 1;
                }
            else
                start = mid + 1;
        }
        
        return ans%mod1;
    }
};