/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        ListNode *first = head, *second = head, *current = head;
        int count = 0;
        bool ans = true;

        // Find the middle element
        while(second->next)
        {
            count++;
            if(!second->next->next) break;
            first = first->next;
            second = second->next->next;
        }

        // Reversing the 2nd half
        ListNode *reverseHalf = reverse(first->next);

        // Comparing the two halves (2nd half reversed)
        while(count--)
        {
            if(current->val != reverseHalf->val)  
            {
                ans = false;
                break;
            }
            current = current->next;
            reverseHalf = reverseHalf->next;
        }

        // Joining the two halves again (we don't want to change the data given)
        reverseHalf = reverse(reverseHalf);
        first->next = reverseHalf;
        
        return ans;
    }

    ListNode* reverse(ListNode* head) {
        ListNode *current = head, *prev = NULL, *next = NULL;

        while(current)
        {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }

        return prev;
    }
};