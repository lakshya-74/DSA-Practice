class Solution {
public:
    int rec(int i , int buy , int fact , vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(i==arr.size()) return 0;
        if(dp[i][buy][fact]!=-1) return dp[i][buy][fact];
        if(buy){
            if(fact==0) return dp[i][buy][fact] = max(-arr[i] + rec(i+1,0,fact,arr,dp),rec(i+1,1,fact,arr,dp));
            return dp[i][buy][fact] = rec(i+1,1,0,arr,dp);
        }
        return dp[i][buy][fact] = max(arr[i]+rec(i+1,1,1,arr,dp),rec(i+1,0,fact,arr,dp));   
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1,vector<vector<int>>(2,vector<int>(2,-1)));
        return rec(0,1,0,prices,dp);
    }
};