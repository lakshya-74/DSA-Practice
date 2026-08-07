class Solution {
public:
    #define ll long long
    bool check(ll val, vector<ll>& v , vector<int>& mons){
        for(int i=0;i<mons.size();i++){
            ll total = val + v[i];
            if(total>=mons[i]){
                val -= mons[i];
                if(val<0) val = 0;
            }
            else return false;
        }
        return true;
    }
    long long minInitialStrength(vector<int>& mons, vector<vector<int>>& boost) {
        int n = mons.size();
        vector<ll> v(n+1,0);
        for(int i=0;i<boost.size();i++){
            int a = boost[i][0];
            int b = min(n-1,boost[i][1]);
            v[a] += boost[i][2];
            v[b+1] -= boost[i][2];
        }
        for(int i=1;i<=n;i++){
            v[i] += v[i-1];
        }
        ll sum = 0;
        for(int i=0;i<n;i++) sum += mons[i];
        ll lo = 0;
        ll hi = sum;
        ll ans =hi;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,v,mons)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};