class Solution{
    public:
    // Function to find number of bits needed to be flipped to convert A to B
    int countBitsFlip(int a, int b){
        int ans = 0;
        int xor1 = a ^ b;
        
        while(xor1)
        {
            if(xor1&1) ans++;
            xor1 = xor1 >> 1;
        }
        
        return ans;
        
    }
};