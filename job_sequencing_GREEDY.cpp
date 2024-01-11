class Solution 
{
    public:
    //Comparator to sort the array
    static int cmp(Job a,Job b)
    {
        return a.profit > b.profit;
    }
    
    //Function to find the maximum profit and the number of jobs done.
    vector<int> JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,cmp);
        
        int count = 0, maxProfit = 0;
        int maxDeadline = -1; 
        
        for(int i=0;i<n;i++)
            maxDeadline = max(maxDeadline,arr[i].dead);
        
        vector<int> schedule(maxDeadline + 1,-1);
        
        for(int i=0;i<n;i++)
        {
            int currId = arr[i].id;
            int currDead = arr[i].dead;
            int currProfit = arr[i].profit;
            
            for(int k=currDead;k>0;k--)
            {
                if(schedule[k] == -1)
                {
                    count++;
                    maxProfit += currProfit;
                    schedule[k] = currId;
                    break;
                }
            }
        }
        
        return {count,maxProfit};
    } 
};