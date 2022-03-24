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

int is(string s,string t,vector<char> ans,int n,int i,int j)
{
        int l=0,r=0;

        if(j == n) return 1;

        if(i == t.size()) return 0;
        
        if(t[i] == s[j])
        {
          ans.push_back(t[i]);
          l = is(s,t,ans,n,i+1,j+1);
        }
        else
          r = is(s,t,ans,n,i+1,j);
 
 return l+r;    
}

bool isSubsequence(string s, string t) {
        vector<char> ans;
        int n = s.size();
        
        return is(s,t,ans,n,0,0);
}
    

int main()
{
    start();

    string s,t;
    cin>>s>>t;

    cout<<isSubsequence(s,t);

    return 0;
}

 