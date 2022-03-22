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

bool pal(string s,int i,int j)
{

	if(i >= j)
		return true;

	if(s[i] != s[j])
		return false;

	return pal(s,i+1,j-1);
}

int main()
{
	start();

	string s;

	cin>>s;

	if(pal(s,0,s.size()-1))
		cout<<"The string is a palindrome";
	else
		cout<<"The string is not a palindrome";

	return 0;
}