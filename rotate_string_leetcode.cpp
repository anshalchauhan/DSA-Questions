#include<bits/stdc++.h>
#define fr(i,x,n) for(int i=x;i<n;i++)
typedef long long int ll;
using namespace std;

void start()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
}

bool rotateString(string s, string goal) {

        if(s.size() != goal.size())
            return false;
        
        vector<int> a;
        
        for(int i=0;i<goal.size();i++)
            if(goal[i] == s[0])
                a.push_back(i);
        
        
        string s1 = s;

        for(int j=0;j<a.size();j++)
        {

        string s1 = s;

        for(int i=s.size()-a[j],j=0 ; j<s.size() ;i++,j++)
        {
            if(i==s.size())
                i = 0;
            
            s1[j] = s[i];
        }
        
        for(int i=0;i<s.size();i++)
        {
            if(s1[i] != goal[i])
                break;

            if(i == s.size()-1)
                return true;
        }
        }
        
        return false;
}


int main()
{
    start();

    string s,goal;
    cin>>s>>goal;

    cout<<rotateString(s,goal);

    return 0;
}


