class Solution {
public:
    #define ll long long
    // int rec(int n , int st,vector<vector<int>>& dp){
    //     if(n<0){
    //         return 1e9;
    //     }
    //     if(n==0) return 0;
    //     if(dp[n][st]!=-1) return dp[n][st];
    //     int a = rec(n-st,st+1,dp);
    //     int b = 1e9;
    //     if(st!=1) b = rec(n,1,dp);
    //     return dp[n][st] = min(1+a,1+b);
    // }
    int minDays(int n) {
        // int mx = (sqrt(8.0*n + 1) - 1)/2;
        // vector<vector<int>> dp(n+1,vector<int>(mx+2,-1));
        // return rec(n,1,dp);

        vector<int> dp(n+1,1e9);
        dp[0] = 0;
        for(int i=1;i<=n;i++){
            int sum =0;
            for(int k=1;k<=i;k++){
                sum += k;
                if(sum>i) break;
                int rem = i - sum;
                if(rem==0) dp[i] = min(dp[i],k);
                else dp[i] = min(dp[i],dp[rem]+1+k);
            }
        }
        return dp[n];
    }
};