class Solution {
public:
    int rec(int i , vector<int>& dp , vector<int>& cost){
        int n = cost.size();
        if(i==n) return 0;
        if(dp[i]!=-1) return dp[i];
        int a=1e8 , b = 1e8 , c = 1e8;
        if(i<n) a = cost[i] + 1 + rec(i+1,dp,cost);
        if(i<n-1) b = cost[i+1] + 4 + rec(i+2,dp,cost);
        if(i<n-2) c = cost[i+2] + 9 + rec(i+3,dp,cost);
        return dp[i] = min({a,b,c});
    }
    int climbStairs(int n, vector<int>& cost) {
        vector<int> dp(n+1,1e8);
        // return rec(0,dp,costs);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int a=1e8 , b = 1e8 , c = 1e8;
            if(i>0) a = cost[i-1] + 1 + dp[i-1];
            if(i>1) b = cost[i-1] + 4 + dp[i-2];
            if(i>2) c = cost[i-1] + 9 + dp[i-3];
            dp[i] = min({a,b,c});
        }
        return dp[n];
    }
};