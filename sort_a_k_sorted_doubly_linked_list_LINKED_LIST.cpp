Node *sortedDll(Node *head, int k)
{
    Node* ans = new Node(-1);
    Node* temp = ans;
    Node* curr = head;
    int count = 0;
    priority_queue<int,vector<int>,greater<int>> pq;

    while(curr)
    {
        count++;
        pq.push(curr->data);

        if(count > k)
        {
            Node* p = new Node(pq.top());
            temp->next = p;
            temp = p;

            pq.pop();
        }

        curr = curr->next;
    }

    while(!pq.empty())
    {
        Node* p = new Node(pq.top());
        temp->next = p;
        temp = p;

        pq.pop();
    }

    return ans->next;
}