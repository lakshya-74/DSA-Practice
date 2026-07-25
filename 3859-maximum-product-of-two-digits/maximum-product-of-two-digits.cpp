class Solution {
public:
    int maxProduct(int n) {
        int mx1 = 0;
        int mx2 = 0;
        while(n>0){
            int x = n%10;
            if(x>mx1){
                mx2 = mx1;
                mx1 = x;
            }
            else if(mx2<x){
                mx2 = x;
            }
            n /= 10;
        }
        return mx1*mx2;
    }
};