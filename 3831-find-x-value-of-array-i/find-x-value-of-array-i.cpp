class Solution {
public:
    #define ll long long 
    vector<long long> resultArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<ll> ans(k,0);
        vector<ll> pre(k,0);
        for(int i=0;i<n;i++){
            int currrem = nums[i]%k;
            vector<ll> curr(k,0);
            curr[currrem]++;
            for(ll oldrem=0;oldrem<k;oldrem++){
                ll newrem = (oldrem*(nums[i]%k))%k;
                curr[newrem] += pre[oldrem];
            }
            pre = curr;
            for(int x=0;x<k;x++){
                ans[x] += pre[x];
            }
        } 
        return ans;
    }
};