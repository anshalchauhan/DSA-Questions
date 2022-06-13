class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode *current = head, *prev = nullptr, *next = nullptr;
        reverse(head,prev,next);
        return prev;
    }
    
    void reverse(ListNode* &current, ListNode* &prev, ListNode* &next )
    {
        if(current == nullptr) return;
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
        reverse(current,prev,next);
    }
};