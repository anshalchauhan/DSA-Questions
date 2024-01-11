class meet
{
    public:
    int start;
    int end;
    int index;
    meet(int start,int end,int index)
    {
        this->start = start;
        this->end = end;
        this->index = index;
    }
};

class Solution{
public:

    static int compare(meet*& a, meet*& b)
    {
        if(a->start == b->start && a->end == b->end)
            return a->index < b->index;
        else if(a->end == b->end)
            return a->start < b->start;
        else
            return a->end < b->end; 
    }
    
    vector<int> maxMeetings(int N,vector<int> &S,vector<int> &F){
        vector<int> ans;
        vector<meet*> meetings;
        
        for(int i=0;i<N;i++)
        {
            meet* m = new meet(S[i],F[i],i+1);
            meetings.push_back(m);
        }
        
        sort(meetings.begin(),meetings.end(),compare);
        
        int last = meetings[0]->end;
        ans.push_back(meetings[0]->index);
        
        for(int i=1;i<N;i++)
            if(meetings[i]->start > last)
            {
                ans.push_back(meetings[i]->index);
                last = meetings[i]->end;
            }
        
        sort(ans.begin(),ans.end());
        
        return ans;
    }
};