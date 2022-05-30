class Solution {
public:
    int buyMaximumProducts(int n, int k, int price[]){
        int count = 0;
        vector<pair<int,int>> index;
        
        for(int i=0;i<n;i++)
            index.push_back(make_pair(price[i],i+1));
        
        sort(index.begin(),index.end());
        
        for(int i=0;i<n;i++)
        {
            if(k - index[i].first < 0) break;
            if(k - index[i].first*index[i].second >= 0) 
            {
                k -= index[i].first*index[i].second;
                count += index[i].second;
                continue;
            }
            
            int t = 0;
            while(k >=0 && t <= index[i].second)
            {
                k -= index[i].first;
                if(k < 0) break;
                count++;
                t++;
            }
        }
        
    return count;
    }
};