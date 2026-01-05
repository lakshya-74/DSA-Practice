class Solution {
public:
    int dp[101][101];
    int rec(int n , int m){
        if(n==0 && m==0) return 1;
        if(n<0 || m<0) return 0;
        if(dp[n][m]!=-1) return dp[n][m];
        int ans = 0;
        int up = rec(n-1,m);
        int left = rec(n,m-1);
        ans = up + left;
        return dp[n][m] = ans;
    }
    int uniquePaths(int m, int n) {
        memset(dp,-1,sizeof(dp));
        return rec(m-1,n-1);
    }
};