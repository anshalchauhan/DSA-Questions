class Solution
{
    public:
    int x1;
    priority_queue<int> maxheap;
    priority_queue<int, vector<int>, greater<int>> minheap; 
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxheap.size() == minheap.size())
            {
                if(maxheap.size() == 0 || minheap.top() >= x)
                    maxheap.push(x);
                else
                {
                    x1 = x;
                    balanceHeaps();
                }
            }
        else
            {
                if(maxheap.top() >= x)
                {
                    x1 = x;
                    balanceHeaps();
                }
                else
                    minheap.push(x);
            }
            
            getMedian();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(maxheap.size() == minheap.size())
            {
                int temp = minheap.top();
                minheap.pop();
                maxheap.push(temp);
                minheap.push(x1);
            }
        else
            {
                int temp = maxheap.top();
                maxheap.pop();
                minheap.push(temp);
                maxheap.push(x1);
            }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxheap.size() == minheap.size()) return double((maxheap.top() + minheap.top())/2);
        else return double(maxheap.top());
    }
};