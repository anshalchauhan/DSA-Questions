class Solution {
public:
    ListNode* reverseKGroup(ListNode* head, int k) {
        int count = 0;
        ListNode *current = head, *curr1 = head, *prev = NULL, *next = NULL;
        
        while(curr1 != nullptr && count<k)
        {
            curr1 = curr1->next;
            count++;
        }
        
        if(count == k)
        {
            count = 0;
        
            while(current != NULL && count < k)
            {
                next = current->next;
                current->next = prev;
                prev = current;
                current = next;
                count++;
            }
            
            if(current != NULL) head->next = reverseKGroup(current, k);
            
            return prev;
        }
        
        return current;
    }
};