class Solution {
public:
    int minCost(int n) {
        if(n==1) return 0;
        int a = n/2;
        int b = n - n/2;
        return a*b + minCost(a) + minCost(b);
    }
};