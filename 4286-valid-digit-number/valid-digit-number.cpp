class Solution {
public:
    bool validDigit(int n, int x) {
        bool flag = false;
        while(n>9){
            if(n%10==x){
                flag = true;
            }
            n /=10;
        }
        if(n==x) return false;
        return flag;
    }
};