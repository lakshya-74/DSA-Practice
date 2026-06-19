class Solution {
public:
    vector<int> dx = {-1,0,1};
    int dfs(int i , int j , vector<vector<int>>& grid,vector<vector<int>>& dp){
        int n = grid.size();
        int m = grid[0].size();
        if(dp[i][j]!=-1) return dp[i][j];
        int ans = 0;
        for(int k=0;k<3;k++){
            int ni = i + dx[k];
            int nj = j +1;
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]>grid[i][j]){
                ans = max(ans,1 + dfs(ni,nj,grid,dp));
            }
        }
        return dp[i][j] = ans;
    }
    int maxMoves(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        for(int i=0;i<n;i++){
            ans = max(ans ,dfs(i,0,grid,dp));
        }
        return ans;
    }
};