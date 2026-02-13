class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int i , int target, int n ,vector<int>& a , vector<int>& b,vector<vector<vector<int>>>& dp){
        if(i<0){
            return target==0;
        }
        if(dp[i][target][n]!=-1) return dp[i][target][n];
        int x = 0;
        if(n>=a[i]) x = rec(i-1,max(0,target-b[i]),n-a[i],a,b,dp);
        int y = rec(i-1,target,n,a,b,dp);
        return dp[i][target][n] = (x+y)%mod;
    }
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int s = group.size();
        vector<vector<vector<int>>> dp(s,vector<vector<int>>(minProfit+1,vector<int>(n+1,-1)));
        return rec(s-1,minProfit,n,group,profit,dp);
    }
};