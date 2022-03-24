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


bool isSubsequence(string s, string t) {

       if(s.empty() && t.empty()) return true;
        
        if(s.empty()) return true;
        
        if(t.empty()) return false;

        for(int i=0;i<s.size();)
            for(int j=0;j<t.size();)
            {
                if(s[i] == t[j])
                {
                    i++;
                    j++;
                }
                else
                    j++;

                if(i == s.size())
                    return true;

                if(j == t.size())
                    return false;
            }
            return false;
}
    

int main()
{
    start();

    string s,t;
    cin>>s>>t;

    cout<<isSubsequence(s,t);

    return 0;
}
