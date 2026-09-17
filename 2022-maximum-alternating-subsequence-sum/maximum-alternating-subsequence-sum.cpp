class Solution {
public:
    #define ll long long
    ll rec(int idx , int check , vector<int>& nums , vector<vector<ll>>& dp){
        int n = nums.size();
        if(idx==n) return 0;
        if(dp[idx][check]!=-1) return dp[idx][check];
        ll a = (check==0?nums[idx]:-nums[idx]) + rec(idx+1,!check,nums,dp);
        ll b = rec(idx+1,check,nums,dp);
        return dp[idx][check] = max(a,b);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        // vector<vector<ll>> dp(n,vector<ll>(2,-1));
        // return rec(0,0,nums,dp);
        vector<vector<ll>> dp(n+1,vector<ll>(2,0));
        dp[0][0] = 0;
        dp[0][1] = 0;
        for(int i=1;i<=n;i++){
            dp[i][0] = max(dp[i-1][1] - nums[i-1] , dp[i-1][0]);
            dp[i][1] = max(dp[i-1][0] + nums[i-1] , dp[i-1][1]);
        }
        return max(dp[n][1] , dp[n][0]);
    }
};