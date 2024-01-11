class Solution 
{
    public:
    //Function to find if its possible to distribute pages 
    bool ispossible(int A[],int N,int M,int mid)
    {
        int pages = 0;
        int count = 1;
        for(int i=0;i<N;i++)
        {
            if(pages + A[i] <= mid)
                pages += A[i];
            else
            {
                count++;
                if(count > M || A[i] > mid) return false;
                
                pages = A[i];
            }
        }

        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //If there are more students than number of books return -1
        if(M > N) return -1;
        
        int start = 0, end = 0;
        int mid, ans = -1;
        
        for(int i=0;i<N;i++)
            end += A[i];
        
        while(start <= end)
        {
            mid = start + (end-start)/2;
            
            if(ispossible(A,N,M,mid))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        
        return ans;
    }
};