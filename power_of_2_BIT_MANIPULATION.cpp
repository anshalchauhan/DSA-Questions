class Solution{
    public:
    // Function to check if given number n is a power of two.
    bool isPowerofTwo(long long n){
        
        if(n == 0) return 0;
        
        while(n>1)
        {
            if(n%2 == 0) n /= 2;
            else return 0;
        }
        
        return 1;
    }
};