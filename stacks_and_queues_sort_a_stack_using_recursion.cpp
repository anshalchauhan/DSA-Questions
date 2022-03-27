void push_at_order(stack<int>& s,int element)
{
    if(s.empty()) s.push(element);
    
    else if(element < s.top())
    {
        int top = s.top();
        s.pop();
        push_at_order(s,element);
        s.push(top);
    }
    else s.push(element);
}

void SortedStack :: sort()
{
    if(s.empty()) return;
    
    int element = s.top();
    s.pop();
    sort();
    push_at_order(s,element);
        
}