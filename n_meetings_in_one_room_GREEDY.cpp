class Solution
{
    public:
    //Function to find the maximum number of meetings that can
    //be performed in a meeting room.
    int maxMeetings(int start[], int end[], int n)
    {
        vector<pair<int,int>> v;
        
        for(int i=0;i<n;i++)
            v.push_back(make_pair(end[i],start[i]));
            
        sort(v.begin(),v.end());
            
        int k = 0;
        int count = 1;
        for(int i=1;i<n;i++)
                if(v[k].first < v[i].second)
                {
                    count++;
                    k = i;
                }
            
        return count;
    }
};