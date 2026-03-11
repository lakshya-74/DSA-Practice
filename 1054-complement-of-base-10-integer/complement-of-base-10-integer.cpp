class Solution {
public:
    int bitwiseComplement(int n) {
        if(n==0) return 1;
        int ans = 0;
        int i = 0;
        while(n>0){
            ans += (n%2==1?0:1)*pow(2,i++);
            n /= 2;
        }
        return ans;
    }
};