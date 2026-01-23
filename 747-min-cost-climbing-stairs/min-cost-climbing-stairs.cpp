class Solution {
public:
    int rec(int idx,vector<int>& cost,vector<int>& dp){
        if(idx>=cost.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int a = cost[idx] + rec(idx+1,cost,dp);
        int b = cost[idx] + rec(idx+2,cost,dp);
        return dp[idx] = min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> dp(cost.size(),-1);
        int a = rec(0,cost,dp);
        dp.assign(cost.size(),-1);
        int b = rec(1,cost,dp);
        return min(a,b);
    }
};