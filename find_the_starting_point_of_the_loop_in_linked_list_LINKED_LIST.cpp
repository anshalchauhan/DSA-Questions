class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *first = head, *second = head;
        bool flag = false;
        
        if(head == NULL) return head;
        
        while(second->next != NULL && second->next->next != NULL)
        {
            first = first->next;
            second = second->next->next;
            if(first == second) 
            {   flag = true;
                break; }
        }
        
        if(first == head && flag)   return first;
        
        else if(first != head && flag)
        {
            first = head;
            
            while(first != NULL && flag)
            {
                if(first->next == second->next)
                    return first->next;
                first = first->next;
                second = second->next;
            }
        }
        
        return NULL;
    }
};