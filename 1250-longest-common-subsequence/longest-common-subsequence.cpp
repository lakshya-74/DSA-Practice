class Solution {
public:
    int rec(int idx1,int idx2,string s1 ,string s2,vector<vector<int>>& dp){
        if(idx1<0 || idx2<0) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s1[idx1]==s2[idx2]){
            return 1 + rec(idx1-1,idx2-1,s1,s2,dp);
        }
        return dp[idx1][idx2] = max(rec(idx1-1,idx2,s1,s2,dp),rec(idx1,idx2-1,s1,s2,dp));
    }
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.size();
        int m = text2.size();
        // vector<vector<int>> dp(n,vector<int>(m,-1));
        // return rec(n-1,m-1,text1,text2,dp);
        vector<vector<int>> dp(n+1,vector<int>(m+1,-1));
        for(int i=0;i<=n;i++){
            dp[i][0] = 0;
        }
        for(int i=0;i<m;i++){
            dp[0][i] = 0;
        }
        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(text1[i-1]==text2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[n][m];
    }
};