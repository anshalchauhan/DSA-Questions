class Solution
{
    public:
    priority_queue<int> maxpq; // Maxheap for smaller elements than median
    priority_queue<int,vector<int>,greater<int>> minpq; // Minheap for larger elements than median
    //Function to insert heap.
    void insertHeap(int &x)
    {
        if(maxpq.size() == minpq.size()) maxpq.push(x);
        else if(maxpq.size() > minpq.size()) minpq.push(x);
        balanceHeaps();
        getMedian();
    }
    
    //Function to balance heaps.
    void balanceHeaps()
    {
        if(!maxpq.empty() && !minpq.empty() && maxpq.top() > minpq.top())
        {
            int temp = maxpq.top();
            maxpq.pop();
            maxpq.push(minpq.top());
            minpq.pop();
            minpq.push(temp);
        }
    }
    
    //Function to return Median.
    double getMedian()
    {
        if(maxpq.size() > minpq.size()) return double(maxpq.top());
        return double((double(maxpq.top()) + double(minpq.top()))/2);
    }
};