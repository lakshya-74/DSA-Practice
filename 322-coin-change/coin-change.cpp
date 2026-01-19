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
        // vector<vector<int>> dp(n+1,vector<int>(amount+1,-1));
        // return rec(n-1,coins,amount,dp)==1e9 ? -1:rec(n-1,coins,amount,dp);

        // tabulation 
        // steps
        // write base case
        // do stuffs in reverse manner as did in memo
        // copy the recurance
        vector<vector<int>> dp(n+1,vector<int>(amount+1,0));
        // work as dp[idx][target]
        // base case
        for(int t=0;t<=amount;t++){ // at base case amount can be anything
            if(t%coins[0]==0) dp[0][t] = t/coins[0];
            else dp[0][t] = 1e9;
        }
        // coins will go from 1 to n-1 
        // amount is from 0 to total
        for(int i=1;i<n;i++){
            for(int t=0;t<=amount;t++){
                // copy the recurrence
                int a = INT_MAX;
                if(t-coins[i]>=0) a = 1 + dp[i][t-coins[i]];
                int b = dp[i-1][t];
                dp[i][t] = min(a,b);
            }
        }
        int ans = dp[n-1][amount];
        if(ans>=1e9) return -1;
        return ans;
    }
};