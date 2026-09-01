class Solution {
public:
    #define ll long long 
    int mod = 1e9 +7;
    ll power(ll& x,ll& n){
        ll ans = 1;
        while(n>0){
            if(n&1){
                ans = (ans*x)%mod;
            }
            x = (x*x)%mod;
            n = n>>1;
        }
        return ans%mod;
    }
    int sumDecoded(vector<long long>& nums) {
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            ll num = nums[i];
            ll w = num%10;
            ll d = num/10;
            string s = to_string(d);
            ll x = stoll(s.substr(0, w));
            ll y = stoll(s.substr(w));
            cout<<x<<" "<<y<<" ";
            ll curr = power(x,y)%mod;
            ans = (ans+curr)%mod;
        }
        return ans%mod;
    }
};