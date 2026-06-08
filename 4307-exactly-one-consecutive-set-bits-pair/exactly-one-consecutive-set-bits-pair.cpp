class Solution {
public:
    bool consecutiveSetBits(int n) {
        int count = 0;
        int pre = 0;
        while(n>0){
            int num = n%2;
            if(num==1){
                if(pre){
                    count++;
                }
                pre = 1;
            }
            else pre = 0;
            n = n/2;
        }
        return count==1;
    }
};