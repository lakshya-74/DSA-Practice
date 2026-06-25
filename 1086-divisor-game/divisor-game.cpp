class Solution {
public:
    bool rec(int i,vector<int>& dp){
        if(i<=1){
            return false;
        }
        if(dp[i]!=-1) return dp[i];
        for(int k=1;k<i;k++){
            if(i%k==0 && !rec(i-k,dp)){
                return dp[i] = true;
            }
        }
        return dp[i] = false;
    }
    bool divisorGame(int n) {
        vector<int> dp(n+1,-1);
        return rec(n,dp);
    }
};