class Solution {
public:
    bool isHappy(int n) {
        int count =0;
        while(count<=20 && n>1){
            int x = 0;
            while(n>0){
                x += (n%10)*(n%10);
                n /= 10;
            }
            n = x;
            count++;
        }
        if(n==1) return true;
        return false;
    }
};