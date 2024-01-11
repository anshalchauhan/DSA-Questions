class Solution{
public:
    int minimumDays(int S, int N, int M){
        if(N < M) return -1;
        
        int sundays = S/7;
        int buying_days = S - sundays;
        int total_food = S*M;
        int ans = 0;
        
        if(total_food%N == 0)
            ans = total_food/N;
        else
            ans = total_food/N + 1;
        
        if(ans > buying_days) return -1;
        return ans;
    }
};