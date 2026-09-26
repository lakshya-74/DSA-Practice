class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    // int rec(int idx, int k , int n, vector<vector<ll>>& dp){
    //     if(k==0) return 1;
    //     if(idx>=n) return 0;
    //     if(dp[idx][k]!=-1) return dp[idx][k];
    //     ll skip = rec(idx+1,k,n,dp)%mod;
    //     ll take = 0;
    //     for(int i=idx+1;i<n;i++){
    //         take += (rec(i,k-1,n,dp)%mod);
    //     }
    //     return dp[idx][k] = (skip + take)%mod;
    // }
    int numberOfSets(int n, int k) {
    //    vector<vector<ll>> dp(n,vector<ll>(k+1,-1));
    //    return rec(0,k,n,dp)%mod;
        vector<vector<ll>> dp(n+1,vector<ll>(k+1,0));
        for(int i=0;i<n;i++){
            dp[i][0] = 1;
        }
        for(int i=1;i<=k;i++){
            vector<ll> preRowSum(n+1,0);
            for(int j=n-1;j>=0;j--){
                preRowSum[j] = (preRowSum[j+1]+dp[j][i-1])%mod;
                ll skip = dp[j+1][i]%mod;
                ll take = preRowSum[j+1];
                dp[j][i] = (skip + take)%mod;
            }
        }
        return dp[0][k];
    }
};