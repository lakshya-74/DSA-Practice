class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n<=0) return false;
        int a = abs(n);
        
        while(a>1){
            if(a%3!=0) return false;
            a = a/3;
        }
        return true;
    }
};