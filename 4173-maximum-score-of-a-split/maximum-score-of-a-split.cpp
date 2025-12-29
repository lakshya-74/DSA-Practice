class Solution {
public:
    #define ll long long
    long long maximumScore(vector<int>& nums) {
        int n = nums.size();
        vector<ll> pre(n+1);
        pre[0] = nums[0];
        ll ans = LLONG_MIN;
        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }
        ll mn_number = nums[n-1];
        for(int i=n-2;i>=0;i--){
            ans = max(pre[i]-mn_number,ans);
            mn_number = min(mn_number,(ll)nums[i]);
        }
        return ans;

    }
};