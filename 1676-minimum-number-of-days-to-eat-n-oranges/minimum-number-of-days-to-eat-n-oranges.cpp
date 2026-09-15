class Solution {
public:
    int rec(int n , unordered_map<int,int>& dp){
        if(n<=0) return 0;
        if(dp.find(n)!=dp.end()) return dp[n];
        int ans = 1e9;
        if(n%2==0) ans = min(ans,1 + rec(n/2,dp));
        if(n%3==0) ans = min(ans,1 + rec(n/3,dp));
        if((n-1)%2==0 || (n-1)%3==0){
            ans = min(ans,1 + rec(n-1,dp));
        }
        if((n-2)%3==0) ans = min(ans,2 + rec(n-2,dp));
        return dp[n] = ans;
    }
    int minDays(int n) {
        // vector<int> dp(n+1,-1);
        unordered_map<int,int> dp;
        return rec(n,dp);
    }
};