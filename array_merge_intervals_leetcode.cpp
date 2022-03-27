class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) { 
        vector<vector<int>> mrg;
        vector<int> a,b,c;
        
        for(int i=0;i<intervals.size();i++)
        {
            a.push_back(intervals[i][0]);
            b.push_back(intervals[i][1]);
        }
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        c.push_back(a[0]);
        
        for(int i=0;i<a.size();i++)
        {
            if(i == a.size()-1)
            {
                c.push_back(b[i]);
                mrg.push_back(c);
                break;
            }
            
            if(a[i+1] > b[i])
            {
                c.push_back(b[i]);
                mrg.push_back(c);
                c.pop_back();
                c.pop_back();
                c.push_back(a[i+1]);    
            }
        }
        return mrg;
    }
};