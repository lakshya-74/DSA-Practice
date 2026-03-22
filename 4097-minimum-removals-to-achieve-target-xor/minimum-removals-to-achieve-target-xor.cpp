class Solution {
public:
    int rec(int i , vector<int>& nums, int t,vector<vector<int>>& dp){
        if(i<0){
            if(t==0) return 0;
            return -1e8;
        }
        if(dp[i][t]!=-1) return dp[i][t];
        int a = 1 + rec(i-1,nums,t^nums[i],dp);
        int b = rec(i-1,nums,t,dp);
        return dp[i][t] = max(a,b);
    }
    int minRemovals(vector<int>& nums, int target) {
        int n = nums.size();
        
        vector<vector<int>> dp(n,vector<int>(pow(2,14),-1));
        int x = rec(n-1,nums,target,dp);
        return x<0?-1:n-x;
    }
};