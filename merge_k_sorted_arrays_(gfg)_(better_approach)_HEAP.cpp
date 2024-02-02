class Node {
    public:
        int data;
        int row;
        int col;
        
        Node(int data,int row,int col)
        {
            this->data = data;
            this->row = row;
            this->col = col;
        }
};

class compare
{
    public:
        bool operator() (Node* a,Node* b) {
            return a->data > b->data;
        }
};

class Solution
{
    public:
    //Function to merge k sorted arrays.
    vector<int> mergeKArrays(vector<vector<int>> arr, int K)
    {
        vector<int> ans;
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        for(int i=0;i<K;i++)
        {
            Node* node = new Node(arr[i][0],i,0);
            pq.push(node);
        }
        
        while(!pq.empty())
        {
            Node* node = pq.top();
            pq.pop();
            ans.push_back(node->data);
            
            int i = node->row;
            int j = node->col;
            
            if(j+1 < arr[i].size())
            {
                Node* newNode = new Node(arr[i][j+1],i,j+1);
                pq.push(newNode);
            }
        }
        
        return ans;
    }
};