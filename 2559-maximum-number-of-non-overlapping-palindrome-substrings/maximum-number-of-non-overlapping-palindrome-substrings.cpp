class Solution {
public:
    bool ispalindrome(int i ,int j , string& s){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    int rec(int i,int j,string& s,int k,vector<vector<int>>& dp){
        int n = s.size();
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(ispalindrome(i,j,s)){
            int ans = 1+rec(j+1,j+k,s,k,dp);
            ans = max(ans,rec(i,j+1,s,k,dp));
            ans = max(ans,rec(i+1,j+1,s,k,dp));
            return dp[i][j] = ans;
        }
        int ans = rec(i+1,j+1,s,k,dp);
        ans = max(ans,rec(i,j+1,s,k,dp));
        return dp[i][j] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1) return n; 
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return rec(0,k-1,s,k,dp);
    }
};