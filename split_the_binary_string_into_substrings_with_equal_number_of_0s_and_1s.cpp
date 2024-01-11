class Solution {
public:
    int maxSubStr(string str){
        int count = 0;
        stack<char> st;
        
        for(int i=0;i<str.size();i++)
        {
            if(st.empty())  {
                st.push(str[i]);
                continue;
            }
            
            if(str[i] != st.top())  {
                st.pop();
                if(st.empty()) count++;
            }
            else    st.push(str[i]);
        }
        
        if(!st.empty()) return -1;
        return count;
    }
};