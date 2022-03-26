
class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum = 0;
        
        for(int i=0;i<N;i++)
            sum += arr[i];
            
        if(sum == 0) return 1;
        
        if(sum%2 != 0) return 0;
            
        return equalsubset(N,arr,sum/2,sum/2,0,0);
    }
    
    int equalsubset(int N,int arr[],int sum,int tsum,int i,int l)
    {
        
        if(sum == 0 || l >= 1) return 1;
        
        if(sum < 0 || i == N) return 0;
        
        l += equalsubset(N,arr,sum-arr[i],tsum,i+1,l);
        if(sum != tsum)
        l += equalsubset(N,arr,sum,tsum,i+1,l);
    
    return l;
    }
};