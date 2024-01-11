class Solution
{
public:
    vector<pair<int, int>> findPairsWithGivenSum(Node *head, int target)
    {
        // code here
        vector<pair<int, int>> ans;
        
        Node *start = head, *end = head;
        
        while(end->next)
            end = end->next;
        
        while(start != end && start->prev != end)
        {
            if((start->data + end->data) == target)
            {
                ans.push_back({start->data, end->data});
                start = start->next;
                end = end->prev;
            }
            
            else if((start->data + end->data) > target)
                end = end->prev;
            else
                start = start->next;
        }
        
        return ans;
    }
};