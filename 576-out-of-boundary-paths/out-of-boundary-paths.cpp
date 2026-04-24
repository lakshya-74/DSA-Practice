class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int i , int j ,int mx , int n , int m, vector<vector<vector<int>>>& dp){
        if(i<0 || j<0 || i>=n || j>=m) return 1;
        if(mx==0) return 0;
        if(dp[i][j][mx]!=-1) return dp[i][j][mx];
        int a = rec(i+1,j,mx-1,n,m,dp);
        int b = rec(i-1,j,mx-1,n,m,dp);
        int c = rec(i,j+1,mx-1,n,m,dp);
        int d = rec(i,j-1,mx-1,n,m,dp);
        long long sum = 0;
        sum = (sum + a) % mod;
        sum = (sum + b) % mod;
        sum = (sum + c) % mod;
        sum = (sum + d) % mod;
        return dp[i][j][mx] = sum%mod;
    }
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(maxMove+1,-1)));
        return rec(startRow,startColumn,maxMove,m,n,dp);
    }
};