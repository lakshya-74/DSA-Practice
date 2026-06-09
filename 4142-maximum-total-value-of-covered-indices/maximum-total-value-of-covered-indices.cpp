class Solution {
public:
    #define ll long long
    ll rec(int idx ,int check ,vector<int>& nums , string& s,vector<vector<ll>>& dp){
        if(idx==0){
            if(s[0]=='1' && !check) return nums[0];
            return 0;
        }
        if(dp[idx][check]!=-1) return dp[idx][check];
        ll a = 0 , b =0;
        if(s[idx]=='1'){
            if(!check) a = nums[idx] + rec(idx-1,0,nums,s,dp);
            b = nums[idx-1] + rec(idx-1,1,nums,s,dp);
        }
        else{
            return dp[idx][check] = rec(idx-1,0,nums,s,dp);
        }
        return dp[idx][check] = max(a,b);
    }
    long long maxTotal(vector<int>& nums, string s) {
        int n = nums.size();
        vector<vector<ll>> dp(n,vector<ll>(2,-1));
        return rec(n-1,0,nums,s,dp);
    }
};