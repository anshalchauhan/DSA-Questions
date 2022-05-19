class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        int n = arr.size();
        
        vector<int> left(n,0),right(n,0);
        stack<int> stl,str;
        int max1 = INT_MIN;
        
        //Calculating Left Indices
        for(int i=0;i<n;i++)
        {
            if(stl.empty() || arr[i] > arr[stl.top()]) 
            {
                stl.push(i);
                left[i] = i;
            }
            else
            {
                int index = 0;
                while(!stl.empty() && arr[i] <= arr[stl.top()])
                {
                    index = stl.top();
                    stl.pop();
                }
                stl.push(i);
                left[i] = left[index];
            }
        }

        //Calculating Right Indices
        for(int i=n-1;i>=0;i--)
        {
            if(str.empty() || arr[i] > arr[str.top()]) 
            {
                str.push(i);
                right[i] = i;
            }
            else
            {
                int index = 0;
                while(!str.empty() && arr[i] <= arr[str.top()])
                {
                    index = str.top();
                    str.pop();
                }
                str.push(i);
                right[i] = right[index];
            }
        }
        
        for(int i=0;i<n;i++)
        {
            int area = arr[i]*(right[i] - left[i] + 1);
            max1 = max(max1,area);
        }
        
        return max1;
    }
};