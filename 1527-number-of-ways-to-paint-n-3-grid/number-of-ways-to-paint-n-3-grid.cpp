class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int level , int n , int pre1 , int pre2 , int pre3,vector<vector<vector<vector<int>>>> &dp){
        if(level==n) return 1;
        if(dp[level][pre1+1][pre2+1][pre3+1]!=-1) return dp[level][pre1+1][pre2+1][pre3+1];
        int ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i!=j && j!=k && i!=pre1 && j!=pre2 && k!=pre3){
                        ans = (ans+rec(level+1,n,i,j,k,dp))%mod;
                    }    
                }
            }
        }
        return dp[level][pre1+1][pre2+1][pre3+1] = ans;
    }
    int numOfWays(int n) {
        vector<vector<vector<vector<int>>>> dp(n+1,vector<vector<vector<int>>>(4,vector<vector<int>>(4,vector<int>(4,-1))));
        return rec(0,n,-1,-1,-1,dp);
    }
};