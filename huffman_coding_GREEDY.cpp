class Node
{
    public:
        int data;
        Node* left;
        Node* right;
        Node(int data)
        {
            this->data = data;
            left = NULL;
            right = NULL;
        }
};

class cmp
{
    public:
        bool operator() (Node* a, Node* b) {
            return a->data > b->data;
        }    
};

class Solution
{
	public:
	    void traverse(Node* root,vector<string>& ans,string temp)
	    {
	        if(!root->left && !root->right)
	        {
	            ans.push_back(temp);
	            return;
	        }
	        
	        traverse(root->left,ans,temp+'0');
	        traverse(root->right,ans,temp+'1');
	    }
	    
		vector<string> huffmanCodes(string S,vector<int> f,int N)
		{
		    vector<string> ans;
		    string temp = "";
		    priority_queue<Node*, vector<Node*>, cmp> pq;
		    
		    for(int i=0;i<N;i++)
		    {
		        Node* node1 = new Node(f[i]);
		        pq.push(node1);
		    }
		    
		    while(pq.size() > 1)
		    {
		        Node* node1 = pq.top();
		        pq.pop();
		        Node* node2 = pq.top();
		        pq.pop();
		        
		        Node* newnode = new Node(node1->data + node2->data);
		        pq.push(newnode);
		        
		        newnode->left = node1;
		        newnode->right = node2;
		    }
		    
		    Node* root = pq.top();
		    pq.pop();
		    
		    traverse(root,ans,temp);
		    
		    return ans;
		}
};