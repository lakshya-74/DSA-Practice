class Solution {
public:
    int rec(int idx,int buy,int mx , vector<int>& arr,vector<vector<vector<int>>>& dp){
        if(mx==0) return 0;
        if(idx==arr.size()) return 0;
        if(dp[idx][buy][mx]!=-1) return dp[idx][buy][mx];
        if(buy){
            return dp[idx][buy][mx] = max(-arr[idx]+rec(idx+1,0,mx,arr,dp),rec(idx+1,1,mx,arr,dp));
        }
        return dp[idx][buy][mx] = max(arr[idx]+rec(idx+1,1,mx-1,arr,dp),rec(idx+1,0,mx,arr,dp));
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,-1)));
        return rec(0,1,2,prices,dp);
    }
};