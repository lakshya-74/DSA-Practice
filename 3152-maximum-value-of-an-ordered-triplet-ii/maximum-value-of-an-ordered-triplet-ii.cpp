class Solution {
public:
    #define ll long long
    long long maximumTripletValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n);
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = max(nums[i],suff[i+1]);
        }
        ll ans = 0;
        ll maxi = nums[0];
        for(int i=1;i<n-1;i++){
            ll curr = (ll)(maxi-nums[i])*(ll)(suff[i+1]);
            ans = max(ans,curr);
            maxi = max(maxi,(ll)nums[i]);
        }
        return ans;
    }
};