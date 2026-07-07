class Solution {
public:
    #define ll long long
    long long sumAndMultiply(int n) {
        ll num = 0;
        ll sum =0;
        int r = 1;
        while(n>0){
            int a = n%10;
            if(a!=0){
                num = a*r + num;
                sum += a;
                r *= 10;
            }
            n /= 10;
        }
        // string s = to_string(num);
        // reverse(s.begin(),s.end());
        // int a = stoi(s);
        return num*sum;
    }
};