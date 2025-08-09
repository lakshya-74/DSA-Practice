class Solution {
public:
    bool check_power(int n){
        int count =0;
        while(n>0){
            count++;
            n = n & (n-1);
        }
        if(count==1) return true;
        return false;
    }
    bool isPowerOfTwo(int n) {
        return check_power(n);
    }
};