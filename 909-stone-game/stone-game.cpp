class Solution {
public:
    int rec(int i, int j , vector<vector<int>>&dp , vector<int>& nums){
        if(i==j) return dp[i][j] = nums[i];
        if(dp[i][j]!=-1) return dp[i][j];
        int a = nums[i] - rec(i+1,j,dp,nums);
        int b = nums[j] - rec(i,j-1,dp,nums);
        return dp[i][j] = max(a,b);
    }
    bool stoneGame(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return true;
        vector<vector<int>> dp(n, vector<int>(n,-1));
        return rec(0,n-1,dp,nums)>=0;
    }
};