class Solution {
public:
    int reverseBits(int n) {
        unsigned int x = 1U<<31;
        int ans = 0;
        for(int i=1;i<=32;i++){
            ans += x*(n&1);
            x = x>>1;
            n /= 2;
        }
        return ans;
    }
};