class Solution {
public:
    int rec(int idx,vector<int>& coins , int target,vector<vector<int>>& dp){
        if(target<0) return 0;
        if(target==0) return 1;
        if(idx==0){
            if(target%coins[0]==0) return 1;
            return 0;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int a =0;
        // take
        if(target-coins[idx]>=0) a = rec(idx,coins,target-coins[idx],dp);
        int b = rec(idx-1,coins,target,dp);
        return dp[idx][target] = a+b;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return rec(n-1,coins,amount,dp);
    }
};