class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int,int> ans;
        vector<pair<int,int>> store;
        
        for(int i=0;i<k;i++)    store.push_back({i,0});
        
        int smallest = INT_MAX;
        
        while(true)
        {
            int minVal = INT_MAX;
            int maxVal = INT_MIN;
            int row, col;
            
            for(int i=0;i<k;i++)
            {
                int rindex = store[i].first;
                int cindex = store[i].second;
                
                if(KSortedArray[rindex][cindex] < minVal)
                {
                    minVal = KSortedArray[rindex][cindex];
                    row = rindex;
                    col = cindex;
                }
                
                maxVal = max(KSortedArray[rindex][cindex],maxVal);
            }
            
            int current = maxVal - minVal;
            if(current < smallest)
            {
                smallest = current;
                ans = {minVal,maxVal};
                
            }
            
            if(store[row].second == n-1) break;
            
            store[row].second++;
        }
        
        return ans;
    }
};