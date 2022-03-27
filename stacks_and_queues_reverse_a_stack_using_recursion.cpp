#include<bits/stdc++.h>
#define fr(i,x,n) for(int i=x;i<n;i++)
long long typedef ll;
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

void reverse_stack(stack<int>& st,stack<int>& stf)
{
	if(st.empty()) return;

	stf.push(st.top());
	st.pop();
	reverse_stack(st,stf);
}

int main()
{
	start();

	stack<int> st,stf;

	int n;
	cin>>n;

	fr(i,0,n)
	{
		int ele;
		cin>>ele;
		st.push(ele);
	}

	reverse_stack(st,stf);

	st = stf;

	while(!st.empty())
	{
		cout<<st.top()<<" ";
		st.pop();
	}

	return 0;
}