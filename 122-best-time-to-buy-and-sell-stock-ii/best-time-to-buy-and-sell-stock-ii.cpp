class Solution {
public:
    int rec(int idx,int buy,vector<int>& arr,vector<vector<int>>& dp){
        if(idx==arr.size()-1){
            if(buy==0){
                return arr[idx];
            }
            return 0;
        }
        if(dp[idx][buy]!=-1) return dp[idx][buy];
        int profit = 0;
        if(buy){ // can buy
            int take = -arr[idx] + rec(idx+1,0,arr,dp); // next you cannot buy without selling
            int not_take = rec(idx+1,1,arr,dp);
            profit = max(profit,max(take,not_take));
        }
        else{ // only can sell
            int sell = arr[idx] + rec(idx,1,arr,dp);
            int not_sell = rec(idx+1,0,arr,dp);
            profit = max(profit,max(sell,not_sell));
        }
        return dp[idx][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n,vector<int>(2,-1));
        return rec(0,1,prices,dp);
    }
};