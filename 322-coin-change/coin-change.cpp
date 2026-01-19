class Solution {
public:
    int rec(int idx,vector<int>& coins ,int target,vector<vector<int>>& dp){
        if(idx==0){
            if(target%coins[idx]==0) return target/coins[idx];
            return 1e9; // return max value
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int a = INT_MAX;
        if(target-coins[idx]>=0) a = 1 + rec(idx,coins,target-coins[idx],dp);
        int b = rec(idx-1,coins,target,dp);
        return dp[idx][target] = min(a,b);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        return rec(n-1,coins,amount,dp)==1e9 ? -1:rec(n-1,coins,amount,dp);
    }
};