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

class compare {
    public:
        bool operator() (Node* a,Node* b) {
            return a->data > b->data;
        }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        pair<int,int> ans;
        priority_queue<Node*,vector<Node*>,compare> pq;
        
        int maxi = INT_MIN;
        for(int i=0;i<k;i++)    
        {
            Node* node = new Node(KSortedArray[i][0],i,0);
            pq.push(node);
            maxi = max(maxi,node->data);
        }
        
        int smallest = INT_MAX;
        while(true)
        {
            Node* node = pq.top();
            pq.pop();
            
            int current = maxi - node->data;
            if(current < smallest)
            {
                smallest = current;
                ans = {node->data,maxi};
            }
            
            if(node->col == n-1) break;
            
            Node* newNode = new Node(KSortedArray[node->row][node->col+1],node->row,node->col+1);
            pq.push(newNode);
            
            maxi = max(maxi,newNode->data);
        }
        
        return ans;
    }
};