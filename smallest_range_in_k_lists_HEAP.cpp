class Element
{
    public:
    int element;
    int row;
    int col;
    
    Element(int element,int row,int col)
    {
        this->element = element;
        this->row = row;
        this->col = col;
    }
};

class Maxcompare
{
    public:
    bool operator()(Element* a,Element* b)  {
        return a->element < b->element;
    }
};

class Mincompare
{
    public:
    bool operator()(Element* a,Element* b) {
        return a->element > b->element;
    }
};

class Solution{
    public:
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        int smallest_diff = -1;
        pair<int,int> ans;
        priority_queue<Element*, vector<Element*>, Maxcompare> kelements_max;
        priority_queue<Element*, vector<Element*>, Mincompare> kelements_min;
    
        for(int i=0;i<k;i++)
        {
            Element *temp = new Element(KSortedArray[i][0],i,0);
            kelements_max.push(temp);
            kelements_min.push(temp);
            //delete temp;
        }
            

        while(true)
        {
            Element* maxtemp = kelements_max.top();
            Element* mintemp = kelements_min.top();
            
            int diff = maxtemp->element - mintemp->element;
            
            if(smallest_diff == -1 || smallest_diff > diff)
                {
                    ans = {mintemp->element,maxtemp->element};
                    smallest_diff = diff;
                }
            
            kelements_min.pop();
            
            if(mintemp->col < n-1)
            {
                int row = mintemp->row;
                int col = mintemp->col + 1;
                int data = KSortedArray[row][col];
                
                Element* temp = new Element(data,row,col);
                kelements_min.push(temp);
                kelements_max.push(temp);
            }
            else
                break;
        }
        
        return ans;
    }
};