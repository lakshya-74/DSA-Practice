class Solution {
public:
    int rec(int i, int buy , int k , vector<int>& prices,vector<vector<vector<int>>>& dp){
        if(k==0) return 0;
        if(i>=prices.size()) return 0;
        if(dp[i][buy][k]!=-1) return dp[i][buy][k];
        if(buy){
            return dp[i][buy][k] = max(-prices[i] + rec(i+1,0,k,prices,dp),rec(i+1,1,k,prices,dp));
        }
        return dp[i][buy][k] = max(prices[i] + rec(i+1,1,k-1,prices,dp),rec(i+1,0,k,prices,dp));
    }
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(k+1,-1)));
        return rec(0,1,k,prices,dp);
    }
};