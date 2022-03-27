class Solution
{
    public:
    //Function to check if brackets are balanced or not.
    bool ispar(string x)
    {
        stack<char> st;
        
        for(int i=0;i<x.size();i++)
        {
            if(st.empty()) st.push(x[i]);
            
            else if(x[i] == '}' && st.top() == '{') st.pop();
            
            else if(x[i] == ']' && st.top() == '[') st.pop();
            
            else if(x[i] == ')' && st.top() == '(') st.pop();
            
            else st.push(x[i]);
        }
        
        if(st.empty()) return true;
        else return false;
    }

};