class Solution {
public:
    int wordLadderLength(string startword, string targetword, vector<string>& wordlist) {
        unordered_set<string> st(wordlist.begin(),wordlist.end());
        st.erase(startword);
        
        queue<pair<string,int>> q;
        q.push({startword,1});
        
        while(!q.empty())
        {
            string currentword = q.front().first;
            int level = q.front().second;
            q.pop();
            
            if(currentword == targetword) return level;
            
            for(int i=0;i<currentword.size();i++)
            {
                char original = currentword[i];
                for(char ch='a';ch<='z';ch++)
                {
                    currentword[i] = ch;
                    
                    if(st.find(currentword) != st.end()) 
                    {
                        st.erase(currentword);
                        q.push({currentword,level+1});
                    }
                }
                
                currentword[i] = original;
            }
        }
        
        return 0;
    }
};