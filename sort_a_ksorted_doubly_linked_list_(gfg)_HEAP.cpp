class Solution
{
public:
    // function to sort a k sorted doubly linked list
    DLLNode *sortAKSortedDLL(DLLNode *head, int k)
    {
        DLLNode* curr = head;
        DLLNode* temp = head;
        
        priority_queue<int,vector<int>,greater<int>> pq;
        int count = 0;
        while(curr)
        {
            pq.push(curr->data);
            curr = curr->next;
            
            if(count >= k)
            {
                int data = pq.top();
                pq.pop();
            
                temp->data = data;
                temp = temp->next;
            }
            count++;
        }
        
        while(!pq.empty())
        {
            int data = pq.top();
            pq.pop();
            temp->data = data;
            temp = temp->next;
        }
        
        return head;
    }
};