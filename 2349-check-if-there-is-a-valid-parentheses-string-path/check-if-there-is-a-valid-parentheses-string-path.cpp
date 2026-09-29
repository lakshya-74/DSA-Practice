class Solution {
public:
    int rec(int i , int j ,int count , vector<vector<char>>& grid , vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || count<0) return false;
        if(i==0 && j==0) return count==1;
        if(dp[i][j][count]!=-1) return dp[i][j][count];
        int change = grid[i][j]==')'?1:-1;
        bool a = rec(i-1,j,count+change,grid,dp);
        bool b = rec(i,j-1,count+change,grid,dp);
        return dp[i][j][count] = a || b;
    }
    bool hasValidPath(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0]==')' || grid[n-1][m-1]=='(') return false;
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(m,vector<int>(m+n+2,-1)));
        return rec(n-1,m-1,0,grid,dp);
    }
};