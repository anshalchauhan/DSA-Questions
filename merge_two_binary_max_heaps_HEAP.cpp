class Solution{
    public:
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        vector<int> ans;
        priority_queue<int> pq;
        int i = 0;
        int j = 0;
        
        while(i < n && j < m)
            {
                if(a[i] > b[j])
                    pq.push(a[i++]);
                else
                    pq.push(b[j++]);
            }
        
        while(i < n)
            pq.push(a[i++]);
        
        while(j < m)
            pq.push(b[j++]);
        
        while(!pq.empty())
        {
            ans.push_back(pq.top());
            pq.pop();
        }

        return ans;
    }
};