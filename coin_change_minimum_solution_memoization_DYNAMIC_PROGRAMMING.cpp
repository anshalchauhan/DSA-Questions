class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> hash(n, vector<int> (amount+1,-1));
        int ans = findmin(n-1,amount,coins,hash);
        if(ans == 1e9) return -1;
        else return ans;
    }
    
    int findmin(int n,int amount,vector<int>& coins,vector<vector<int>>& hash)
    {
        if(amount == 0) return 0;
        if(n == 0)
        {
            if(amount%coins[n] == 0) return amount/coins[n];
            else return 1e9;
        }
        if(hash[n][amount] != -1) return hash[n][amount]; 
        int take = 1e9;
        if(coins[n] <= amount) take = 1 + findmin(n,amount-coins[n],coins,hash);
        int nottake = findmin(n-1,amount,coins,hash);
        return hash[n][amount] =  min(take,nottake);
    }
};