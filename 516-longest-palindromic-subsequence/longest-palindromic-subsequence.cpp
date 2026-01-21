class Solution {
public:
    int rec(int idx1,int idx2,string& s,vector<vector<int>>& dp){
        int n = s.size();
        if(idx1>idx2) return 0;
        if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
        if(s[idx1]==s[idx2]){
            return dp[idx1][idx2] = (idx1==idx2 ? 1:2) + rec(idx1+1,idx2-1,s,dp);
        }
        return dp[idx1][idx2] = max(rec(idx1+1,idx2,s,dp),rec(idx1,idx2-1,s,dp));
    }
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1 ,vector<int>(n +1 , -1));
        return rec(0,n-1,s,dp);
    }
};