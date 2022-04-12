class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        int sum=0;
        for(int i=0;i<N;i++)
            sum += arr[i];
        
        if(sum%2 != 0) return 0;
        vector<vector<int>> hash(N,vector<int> (sum/2 + 1,-1));
        return subset(N-1,arr,sum/2,hash);
    }
    
    int subset(int N,int arr[],int sum,vector<vector<int>>& hash)
    {
        if(sum == 0) return 1;
        
        if(N < 0 || sum < 0) return 0;
        
        if(hash[N][sum] != -1) return hash[N][sum];
        
        int left = subset(N-1,arr,sum-arr[N],hash);
        int right = subset(N-1,arr,sum,hash);
        return hash[N][sum] = left+right;
    }
};
