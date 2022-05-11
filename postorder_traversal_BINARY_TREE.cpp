#include<bits/stdc++.h>
long long typedef ll;
#define fr(i,x,n) for(int i=x;i<n;i++)
using namespace std;

void start()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

struct Node {
	int data;
	struct Node *left, *right;

	Node(int val)
	{
		data = val;
		left = right = NULL;
	}
};

void postorder(Node *root)
{
	if(root == NULL) return;

	postorder(root->left);
	postorder(root->right);
	cout<<root->data<<" ";
}

int main()
{
	start();

	struct Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);

	postorder(root);
	return 0;
}