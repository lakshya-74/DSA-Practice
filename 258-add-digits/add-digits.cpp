class Solution {
public:
    int addDigits(int num) {
        while(num>9){
            int x = 0;
            while(num>0){
                x += num%10;
                num  /= 10;
            }
            num = x;
        }
        return num;
    }
};