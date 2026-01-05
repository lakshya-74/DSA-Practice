class Solution {
public:
    int dp[101][101];
    int rec(int i , int j , vector<vector<int>>& arr){
        if(i<0 || j<0 || arr[i][j]==1) return 0;
        if(i==0 && j==0) return 1;
        if(dp[i][j]!=-1) return dp[i][j];
        int up = rec(i-1,j,arr);
        int left = rec(i,j-1,arr);
        return dp[i][j] = up+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& arr) {
        int n = arr.size();
        int m = arr[0].size();
        memset(dp,-1,sizeof(dp));
        return rec(n-1,m-1,arr);
    }
};