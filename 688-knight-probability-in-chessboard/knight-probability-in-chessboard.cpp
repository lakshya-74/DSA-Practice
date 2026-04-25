class Solution {
public:
    vector<pair<int,int>> dir = {{-2,1},{-2,-1},{-1,2},{-1,-2},{2,1},{2,-1},{1,2},{1,-2}};
    double rec(int i , int j , int k,int n,vector<vector<vector<double>>>& dp){
        if(k==0) return 1;
        if(dp[i][j][k]!=-1) return dp[i][j][k];
        double ans = 0;
        for(int l=0;l<8;l++){
            int ni = i + dir[l].first;
            int nj = j + dir[l].second;
            if(ni>=0 && ni<n && nj>=0 && nj<n){
                ans += rec(ni,nj,k-1,n,dp);
            }
        }
        return dp[i][j][k] = ans/8.0;
    }
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n,vector<vector<double>>(n,vector<double>(k+1,-1)));
        return rec(row,column,k,n,dp);
    }
};