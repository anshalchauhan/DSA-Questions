class Solution
{
  public:
    //Function to find maximum of each subarray of size k.
    vector<int> max_of_subarrays(int *arr, int n, int k)
    {
        vector<int> ans;
        priority_queue<pair<int,int>> pq;
        
        for(int i=0;i<n;i++)
        {
            pq.push({arr[i],i});
            if(i >= k-1)
            {
                while(pq.top().second < i-k+1)
                    pq.pop();
                
                ans.push_back(pq.top().first);
            }
        }
        
        return ans;
    }
};