#include<bits/stdc++.h>
#define fr(i,x,n) for(int i=x;i<n;i++)
using namespace std;
int top=0;

void push(int *stack,int n)
{
	int element;
	cout<<"Enter the element to be added in stack\n";
	cin>>element;
	if(top == n-1)
	    cout<<"stack is full\n";
	else
	    stack[top++] = element;
}

void pop(int *stack)
{
    if(top == 0)
        cout<<"stack is empty"<<"\n";
    else
	    stack[top--] = -10000;
}

void display(int *stack)
{
	int t = top;
	
	if(top == 0)
	    cout<<"stack is empty\n";
	while(t--)
	{
		if(stack[top] != -10000)
		cout<< stack[t] << "\n";
	}
}

int main()
{
    int n;
    cout<<"Enter the size of the stack\n";
    cin>>n;
	int *stack = new int[n];
	char choice;
	do
	{
		cout<<"what operation do you want to perform on stack?"<<"\n";
		cout<<"1. Push Operation"<<"\n";
		cout<<"2. Pop Operation"<<"\n";
		cout<<"3. Display Operation"<<"\n";
		int t;
		cin>>t;
		switch(t)
		{
			case 1: push(stack,n);
					break;

			case 2: pop(stack);
					break;

			case 3: display(stack);
					break;

			default : cout<<"Choose correct option"<<"\n";
		}
		cout<<"If you want to continue, press y|Y"<<"\n";
		cin>>choice;
		}while(choice == 'y' || choice == 'Y');
		
	return 0;
}