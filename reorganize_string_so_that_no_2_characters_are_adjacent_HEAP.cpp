class node
{
public:
    char element;
    int count;
    
    node(char element,int count)
    {
        this->element = element;
        this->count = count;
    }
};

class compare
{
    public:
    bool operator()(node* a,node* b)    {
        return a->count < b->count;
    }
};

class Solution {
public:
    string reorganizeString(string s) {
        string ans = "";
        
        priority_queue<node*, vector<node*>, compare> maxheap;
        map<char,int> map1;
        
        for(int i=0;i<s.size();i++)
            map1[s[i]]++;
        
        for(auto it:map1)
        {
            node* temp = new node(it.first,it.second);
            maxheap.push(temp);
        }
        
        node* blocked,*curr;
        
        while(!maxheap.empty())
        {
            curr = maxheap.top();
            maxheap.pop();
            
            if(ans.size() != 0 && blocked->count != 0)
                maxheap.push(blocked);
            
            ans += curr->element;
            curr->count--;
            
            blocked = curr;
        }
        
        if(ans.size() == s.size()) return ans;
        else return "";
    }
};