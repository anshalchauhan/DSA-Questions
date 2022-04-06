class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        vector<int> hash(n,-1);
        return not_adjacent(arr,n,0,hash);
    }
    
    int not_adjacent(int arr[], int n,int i,vector<int>& hash)
    {
        if(i >= n) return 0;
        
        if(hash[i] != -1) return hash[i];
        
        int left = arr[i] + not_adjacent(arr,n,i+2,hash);
        int right = not_adjacent(arr,n,i+1,hash);
        return hash[i] = max(left,right);
    }
};