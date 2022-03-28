class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        vector<int> ans(n);
        
        for(int i=n-1;i>=0;i--)
            {
                        while(!st.empty() && arr[i] <= st.top())
                            st.pop();
                        
                        if(st.empty()) ans[i] = -1;
                        
                        else ans[i] = st.top();
                        
                        st.push(arr[i]);
            }
    return ans;
    } 
};