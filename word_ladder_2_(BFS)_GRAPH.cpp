class Solution {
public:
    vector<vector<string>> findSequences(string beginword, string endword, vector<string>& wordlist) {
        vector<vector<string>> ans;
        vector<string> usedonlevel;
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        queue<vector<string>> q;
        q.push({beginword});
        
        while(!q.empty())
        {
            vector<string> currentlist = q.front();
            q.pop();
            string currentword = currentlist.back();

            if(currentword == endword)
            {
                if(!ans.size() || ans[0].size() == currentlist.size()) ans.push_back(currentlist);
                else return ans;
            }
            
            //erase the currentword
            st.erase(currentword);
            
            for(int i=0;i<currentword.size();i++)
            {
                char original = currentword[i];
                
                for(char ch='a';ch<='z';ch++)
                {
                    currentword[i] = ch;
                    if(st.find(currentword) != st.end())
                    {
                        currentlist.push_back(currentword);
                        q.push(currentlist);
                        currentlist.pop_back();
                    }
                }
                currentword[i] = original;
            }
        }
        
        return ans;
    }
};