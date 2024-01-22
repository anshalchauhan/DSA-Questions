class Solution {
  public:
    int canRepresentBST(int arr[], int N) {
        int root = INT_MIN;
        stack<int> st;
        
        for(int i=0;i<N;i++)
        {
            while(!st.empty() && st.top() < arr[i])
                {
                    root = st.top();
                    st.pop();
                }
            
            if(arr[i] < root) return false;
            st.push(arr[i]);
        }
        
        return true;
    }
};