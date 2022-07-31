class Solution{   
public:
    string smallestNumber(int s, int d){
        string ans = "-1";
        int smallest = pow(10,d-1);
        int largest = pow(10,d) - 1;
        
        for(int i=smallest;i<=largest;i++)
        {
            int sum = 0, n = i;
            while(n > 0)
            {
                sum += n%10;
                n = n/10;
            }
            if(sum == s)
            {
                ans = to_string(i);
                break;
            }
        }
        return ans;
    }
};