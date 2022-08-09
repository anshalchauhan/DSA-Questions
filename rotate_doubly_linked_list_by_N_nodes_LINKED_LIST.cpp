class Solution {
public:
    Node *rotateDLL(Node *start,int p)
    {
        Node *ans = start, *curr = start, *last = NULL;
        
        while(curr->next != NULL)
        {
            curr = curr->next;
            p--;
            if(p == 0)
            {
                last = curr->prev;
                last->next = NULL;
                curr->prev = NULL;
                ans = curr;
            }
        }
        
        curr->next = start;
        start->prev = curr;
        
        return ans;
    }
};