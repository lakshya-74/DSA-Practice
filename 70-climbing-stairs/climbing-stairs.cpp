class Solution {
public:
    vector<int> dp;
    int rec(int level , int n){
        // if(level>n) return 0;
        if(level==n) return 1;
        int ans = 0;
        if(dp[level]!=-1) return dp[level];
        for(int steps=1;steps<=2;steps++){
            if(steps+level<=n){
                int ways = rec(level+steps,n);
                ans += ways;
            }
        }
        dp[level] = ans;
        return ans;
    }
    int climbStairs(int n) {
        dp.resize(n,-1);
        return rec(0,n);
    }
};