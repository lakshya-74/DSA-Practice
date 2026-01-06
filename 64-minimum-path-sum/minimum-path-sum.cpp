class Solution {
public:
    int dp[201][201];
    int rec(int i, int j,vector<vector<int>>&grid){
        if(i<0 || j<0) return 1e7;
        if(i==0 && j==0){
            return grid[0][0];
        }
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = INT_MAX;
        int up = grid[i][j] + rec(i-1,j,grid);
        int left = grid[i][j] + rec(i,j-1,grid);
        return dp[i][j] =  min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,grid);
    }
};