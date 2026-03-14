class Solution {
public:
    #define ll long long
    bool check(ll mid , vector<int>& nums,int k){
        ll h = 0;
        for(int i=0;i<nums.size();i++){
            h += sqrt((2.0*mid/nums[i]) + 0.25) - 0.5;
            if(h>=k) return true;
        }
        return h>=k;
    }
    long long minNumberOfSeconds(int mheight, vector<int>& workerTimes) {
        int maxval = 0;
        int n = workerTimes.size();
        for(int i=0;i<n;i++){
            maxval = max(maxval,workerTimes[i]);
        }
        ll tmax = 1LL*maxval*((1LL)*mheight*((1LL)*mheight+1)/2);
        ll lo = 1;
        ll hi = tmax;
        ll ans =0;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,workerTimes,mheight)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};