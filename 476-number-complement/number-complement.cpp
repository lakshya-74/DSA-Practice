class Solution {
public:
    int findComplement(int num) {
        if(num==0) return 1;
        long long ans = 0;
        long long i = 0;
        while(num>0){
            ans += (num%2==1?0:1)*pow(2,i++);
            num /= 2;
        }
        return ans;
    }
};