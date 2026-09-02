class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans =0;
        int mx = max({a,b,c});
        int i = 0;
        while(mx){
            int bit = 1<<i;
            int x = a&bit?1:0;
            int y = b&bit?1:0;
            int z = c&bit?1:0;
            if(z==0){
                if(x==1) ans++;
                if(y==1) ans++;
            }
            else{
                if(x==0 && y==0) ans++;
            }
            i++;
            mx /= 2;
        }
        return ans;
    }
};