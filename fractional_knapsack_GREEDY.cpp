class Solution
{
    public:
    //comparator function
    static double cmp(pair<double,int> a,pair<double,int> b)
    {
        return a.first > b.first;
    }
    
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> ratios(n);
        
        for(int i=0;i<n;i++)
            ratios[i] = {(double)arr[i].value/arr[i].weight,i};
        
        sort(ratios.begin(),ratios.end(),cmp);
        
        double ans = 0;
        int index = 0;
        
        while(W > 0 && index < n)
        {
            int weight_index = ratios[index].second;
            
            if(W >= arr[weight_index].weight)
            {
                ans += (double)arr[weight_index].value;
                W -= arr[weight_index].weight;
            }
            else
            {
                ans += (double)W*ratios[index].first;
                W -= W;
            }
            index++;
        }
        
        return ans;
    }
        
};