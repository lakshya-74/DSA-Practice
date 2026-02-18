class Solution {
public:
    bool hasAlternatingBits(int n) {
        int val = -1;
        while(n>0){
            int x = n&1;
            if(val==x) return false;
            val = x;
            n = n>>1;
        }
        return true;
    }
};