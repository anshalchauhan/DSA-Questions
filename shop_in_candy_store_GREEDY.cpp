class Solution
{
public:
    vector<int> candyStore(int candies[], int N, int K)
    {
        vector<int> ans;
        sort(candies,candies + N);
        
        int buy = N/(1 + K);
        if(N%(1 + K) != 0)
            buy += 1;
        
        int minimum_cost = 0, maximum_cost = 0, index = 0;
        int t = buy;
        
        
        while(t--)
        {
            minimum_cost += candies[index];
            index++;
        }
        
        t = buy, index = N-1;
        
        while(t--)
        {
            maximum_cost += candies[index];
            index--;
        }
        
        return {minimum_cost,maximum_cost};
    }
};