class Solution{   
public:
    int getPairsCount(int arr[], int n, int k) {
        return pairsum(arr,n,k,0,0);
    }
    
    int pairsum(int arr[],int n,int k,int i,int j)
    {
        if(k == 0 && j == 2) return 1;
        
        if(j == 2) return 0;
        
        if(i == n || k < 0) return 0;
        
        return pairsum(arr,n,k-arr[i],i+1,j+1) + pairsum(arr,n,k,i+1,j);
    }
};