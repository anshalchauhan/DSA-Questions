class Solution {
public:
    ListNode* middleNode(ListNode* head) {
        int count = 0;
        int n = 0;
        ListNode *current = head; 
        while(current != NULL)
        {   n++;
            current = current->next;    }
        
        current = head;
        n = n/2 + 1;
        
        while(current != NULL && n > 1)
        {   n--;
            current = current->next;    }
        
        return current;
    }
};