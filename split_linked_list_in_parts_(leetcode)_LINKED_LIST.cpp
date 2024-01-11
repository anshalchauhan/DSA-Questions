class Solution {
public:
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ans;
        ListNode* current = head;
        int count = 0, q = 0, r = 0, t = k;    

        while(current)
        {
            count++;
            current = current->next;
        }

        current = head;
        q = count/k;
        r = count%k;
        cout<<q<<" "<<r<<"\n";

        while(t--)
        {
            int n = q;
            ListNode* part = new ListNode(-1);
            ListNode* temp = part;

            if(r) 
            {
                n += 1;
                r--;
            }

            while(n--)
            {
                ListNode* newNode = new ListNode(current->val);
                current = current->next;
                temp->next = newNode;
                temp = newNode;
            }

            ans.push_back(part->next);
        }

        return ans;
    }
};