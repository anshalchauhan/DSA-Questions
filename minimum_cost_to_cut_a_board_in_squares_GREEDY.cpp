class Solution {
public:
    int minimumCostOfBreaking(vector<int> X, vector<int> Y, int M, int N){
        sort(X.begin(),X.end(),greater<int>());
        sort(Y.begin(),Y.end(),greater<int>());
        
        int h_edge = 0, v_edge = 0;
        int min_cost = 0;
        int v_squares = 1, h_squares = 1;
        
        while(v_edge < M-1 && h_edge < N-1)
        {
            if(X[v_edge] > Y[h_edge])
            {
                min_cost += X[v_edge]*h_squares;
                v_edge++;
                v_squares++;
            }
            else
            {
                min_cost += Y[h_edge]*v_squares;
                h_edge++;
                h_squares++;
            }
        }
        
        while(v_edge < M-1)
        {
            min_cost += X[v_edge]*h_squares;
            v_edge++;
        }
        
        while(h_edge < N-1)
        {
            min_cost += Y[h_edge]*v_squares;
            h_edge++;
        }
        
        return min_cost;
    }
};