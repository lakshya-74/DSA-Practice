class Solution {
public:
    // int rec(int idx1 , int idx2 , string s, vector<vector<int>>& dp){
    //     if(idx1>idx2) return 0;
    //     if(dp[idx1][idx2]!=-1) return dp[idx1][idx2];
    //     if(s[idx1]==s[idx2]) return dp[idx1][idx2] = (idx1==idx2?1:2) + rec(idx1+1,idx2-1,s,dp);
    //     return dp[idx1][idx2] = max(rec(idx1+1,idx2,s,dp),rec(idx1,idx2-1,s,dp));
    // }
    int rec(int i,int j , string& s1, string& s2 , vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j]) return dp[i][j] = 1 + rec(i-1,j-1,s1,s2,dp);
        return dp[i][j] = max(rec(i-1,j,s1,s2,dp),rec(i,j-1,s1,s2,dp));
    }
    int minInsertions(string s) {
        int n = s.size();
        vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
        string st = s;
        reverse(st.begin(),st.end());
        return n - rec(n-1,n-1,s,st,dp);
    }
};