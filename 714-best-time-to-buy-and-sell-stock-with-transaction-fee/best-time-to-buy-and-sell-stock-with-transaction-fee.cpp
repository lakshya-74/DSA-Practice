class Solution {
public:
    int rec(int i , int buy , vector<int>& arr , int fee,vector<vector<int>>& dp){
        if(i>=arr.size()) return 0;
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy){
            return dp[i][buy] = max(-arr[i] + rec(i+1,0,arr,fee,dp),rec(i+1,1,arr,fee,dp));
        }
        return dp[i][buy] = max(arr[i]-fee + rec(i+1,1,arr,fee,dp),rec(i+1,0,arr,fee,dp));
    }
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<vector<int>> dp(n+1,vector<int>(2,-1));
        return rec(0,1,prices,fee,dp);
    }
};