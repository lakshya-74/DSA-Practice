class Solution {
public:
    #define ll long long
    long long sumAndMultiply(int n) {
        ll num = 0;
        ll sum =0;
        while(n>0){
            int a = n%10;
            if(a!=0){
                num = num*10 + a;
                sum += a;
            }
            
            n /= 10;
        }
        string s = to_string(num);
        reverse(s.begin(),s.end());
        int a = stoi(s);
        return a*sum;
    }
};