class Solution
{
    public:
    //Function to evaluate a postfix expression.
    int evaluatePostfix(string S)
    {
        stack<int> st;
        for(int i=0;i<S.size();i++)
        {
            if(S[i] == '*' || S[i] == '+' || S[i] == '-' || S[i] == '/')
             {
                int y = st.top();
                st.pop();
                int x = st.top();
                st.pop();
                
                if(S[i] == '+') st.push(x+y);
                
                else if(S[i] == '-') st.push(x-y);
                
                else if(S[i] == '*') st.push(x*y);
                
                else st.push(x/y);
             } 
        
        else st.push(S[i]-48);
    }
    return st.top();
    }
};