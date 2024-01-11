class Solution {
public:
    ListNode* oddEvenList(ListNode* head) {
        if(!head) return head;

        ListNode* current = head, *prev = NULL, *end = NULL, *temp = NULL;
        int count = 0;

        // Move at last node of the linked list
        while(current->next)
        {
            current = current->next;
            count++;
        }
        count += 1;

        end = current;
        current = head;
        int num = 0;
        
        while(count--)
        {
            num++;
            if(num%2 == 0 && current->next)
            {
                prev->next = current->next;
                temp = current;
                current = current->next; 
                insertAtEnd(temp, end);
                continue;    
            }

            prev = current;
            current = current->next;
        }

        return head;
    }

    void insertAtEnd(ListNode* temp, ListNode* &end) {
        end->next = temp;
        temp->next = NULL;
        end = temp;
    }
};