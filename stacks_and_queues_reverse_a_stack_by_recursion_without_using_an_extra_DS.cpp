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

void push_at_bottom(stack<int>& st,int element)
{
	if(st.empty()) st.push(element);

	else
	{
		int top = st.top();
		st.pop();
		push_at_bottom(st,element);
		st.push(top);
	}
}

void reverse_stack(stack<int>& st)
{	
	if(st.empty()) return;

	int element = st.top();
	st.pop();
	reverse_stack(st);
	push_at_bottom(st,element);
}

int main()
{
	start();

	stack<int> st;

	int n;
	cin>>n;

	fr(i,0,n)
	{
		int ele;
		cin>>ele;
		st.push(ele);
	}
	
	reverse_stack(st);

	while(!st.empty())
	{
		cout<<st.top()<<"\n";
		st.pop();
	}

	return 0;
}