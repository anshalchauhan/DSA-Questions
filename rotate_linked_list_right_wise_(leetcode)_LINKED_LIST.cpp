class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || k == 0) return head;

        ListNode* current = head;
        int count = 0, rot = 0;

        while(current)
        {
            count++;
            current = current->next;
        }

        rot = count - k%count;
        current = head;

        while(current && --rot)
            current = current->next;
        
        if(current->next)
        {
            ListNode* newHead = current->next;
            current->next = NULL;

            ListNode* newCurrent = newHead;

            while(newCurrent->next)
                newCurrent = newCurrent->next;
            
            newCurrent->next = head;
            return newHead;
        }

        return head;
    }
};