class Solution {
public:
    #define ll long long
    vector<long long> minOperations(vector<int>& nums, vector<int>& queries) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<ll> pre(n+1,0); 
        for(int i=1;i<=n;i++){
            pre[i] = pre[i-1] + nums[i-1];
        }
        int m = queries.size();
        vector<ll> ans(m);
        for(int i=0;i<m;i++){
            int idx = lower_bound(nums.begin(),nums.end(),queries[i]) - nums.begin();
            ll left = idx*(ll)queries[i] - pre[idx];
            ll right = (pre[n]-pre[idx]) - (n-idx)*(ll)queries[i];
            ans[i] = left + (right>0?right:0);
        }
        return ans;
    }
};