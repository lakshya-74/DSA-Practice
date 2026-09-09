class Solution {
public:
    #define ll long long
    long long countCommas(long long n) {
        if(n<1000) return 0;
        ll count = 0;
        ll val = 1000;
        while(n>=val){
            count += n-val+1;
            val *= 1000;
        }
        return count;
    }
};