class Solution{
public:
    ListNode *moveToFront(ListNode *head){
        if(!head || !head->next)   return head;
        ListNode* curr = head;
        
        while(curr->next->next)   curr = curr->next;
        
        ListNode* temp = curr->next;
        curr->next = NULL;
        temp->next = head;
        head = temp;
        
        return head;
    }
};