class Solution {
public:
    #define ll long long
    long long countSubarrays(vector<int>& nums, long long k) {
        ll n = nums.size();
        ll l=0 ,r = 0 , prod = 1;
        ll ans = 0;
        ll sum = 0;
        while(r<n){
            sum += nums[r];
            while(sum*(r-l+1)>=k){
                sum -= nums[l];
                l++;
            }
            ans += r-l+1;
            r++;
        }
        return ans;
    }
};