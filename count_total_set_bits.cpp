
class Solution{
    public:

    int largestPowerOf2(int n) {
        int x = 0;
        while((1 << x) <= n) 
            x++;
        
        return x - 1;
    }

    int countSetBits(int n) {
        // edge case
        if(n == 0)
            return 0;

        int x = largestPowerOf2(n);
        int bitsInGroup = x * (1 << (x - 1));
        int msb_rem = n - (1 << x) + 1;
        int smaller_prob = n - (1 << x);

        return bitsInGroup + msb_rem + countSetBits(smaller_prob);
    }
};