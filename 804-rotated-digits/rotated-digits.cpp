class Solution {
public:
    int rotatedDigits(int n) {
        int count = 0;
        for(int i=1;i<=n;i++){
            int x = i;
            bool check = true;
            bool flag = false;
            while(x>0){
                int a = x%10;
                if(a==3 || a==7 || a==4){
                    check = false;
                    break;
                }
                if(a==2 || a==5 || a==6 || a==9){
                    flag = true;
                }
                x /= 10;
            }
            if(check && flag) count++;
        }
        return count;
    }
};