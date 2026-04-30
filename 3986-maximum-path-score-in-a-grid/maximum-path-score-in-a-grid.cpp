class Solution {
public:
    int rec(int i , int j , int k , vector<vector<int>>& grid , vector<vector<vector<int>>>& dp){
        if(i<0 || j<0) return -1e8;
        int cost = 1;
        if(grid[i][j]==0) cost = 0;
        if(i==0 && j==0){
           if(k-cost>=0) return grid[i][j];
           return -1e8;
        }
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        int a = -1e8 , b = -1e8;
        if(k-cost>=0){ 
            a = rec(i-1,j,k-cost,grid,dp);
            b = rec(i,j-1,k-cost,grid,dp);
        }
        int ans = max(a,b);
        if(ans<0) dp[i][j][k] = -1e8;
        return dp[i][j][k] = grid[i][j] + ans;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(k+1,-1)));
        int ans = rec(n-1,m-1,k,grid,dp);
        if(ans<0) return -1;
        return ans;
    }
};