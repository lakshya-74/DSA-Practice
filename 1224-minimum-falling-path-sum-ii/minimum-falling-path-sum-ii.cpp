class Solution {
public:
    int rec(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size();
        if(j>=n || j<0) return 1e8;
        if(i==0){
            return grid[i][j];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 1e8;
        for(int k=0;k<n;k++){
           if(k!=j) ans = min(ans,grid[i][j] + rec(i-1,k,grid,dp));
           
        }
        return dp[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        int ans = INT_MAX;
        int n = grid.size();
        if(n==1) return grid[0][0];
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        for(int i=0;i<n;i++){
            ans = min(ans,rec(n-1,i,grid,dp));
        }
        return ans;
    }
};