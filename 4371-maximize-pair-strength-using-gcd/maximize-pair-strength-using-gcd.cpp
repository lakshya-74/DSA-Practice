class Solution {
public:
    #define ll long long 
    long long maxPairStrength(vector<int>& nums) {
        int n = nums.size();
        ll ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                ll a = 1LL*nums[i]*nums[j];
                ll b = gcd(nums[i],nums[j]);
                ll c = b*b;
                ans = max(ans,a/c);
            }
        }
        return ans;
    }
};