class Solution {
public:
    long long mod = 1e9 + 7;
long long pow(long long x, long long n){
        if(n==0) return 1;
        long long half = pow(x,n/2);
        if(n%2==0) return (half*half)%mod;
        return (half*half*x)%mod;
    }
    int countGoodNumbers(long long n) {
        // if(n==1) return 5;
        long long o = n/2 , e = n/2;
        if(n%2){
            e++;
        }
        long long ans = pow(5,e)*pow(4,o);
        return ans%mod;
    }
};