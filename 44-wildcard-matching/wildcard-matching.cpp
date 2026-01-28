class Solution {
public:
    bool rec(int i,int j,string& s1 ,string& s2,vector<vector<int>>& dp){
        if(i<0){
            int k = j;
            while(k>=0){
                if(s2[k]!='*') return false;
                k--;
            }
            return true;
        }
        if(j<0){
            return false;
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(s1[i]==s2[j] || s2[j]=='?') return dp[i][j] = rec(i-1,j-1,s1,s2,dp);
        if(s2[j]=='*') return dp[i][j] = (rec(i,j-1,s1,s2,dp) || rec(i-1,j,s1,s2,dp));
        return dp[i][j] = false;
    }
    bool isMatch(string s, string p) {
        int n = s.size();
        int m = p.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,s,p,dp);
    }
};