class Solution {
public:
    #define ll long long 
    bool check(ll h,vector<vector<int>>& dung){
        int n = dung.size();
        int m = dung[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        dp[0][0] = h + dung[0][0];
        if(dp[0][0]<=0) return false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                int best = 0;
                if(i-1>=0) best = max(best,dp[i-1][j]);
                if(j-1>=0) best = max(best,dp[i][j-1]);
                if(best>0) dp[i][j] = best + dung[i][j];
            }
        }
        return dp[n-1][m-1]>0;
    }
    int calculateMinimumHP(vector<vector<int>>& dung) {
        ll lo = 1;
        ll hi = 1e6;
        int ans = 0;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,dung)){
                ans = mid;
                hi = mid-1;
            }
            else lo = mid+1;
        }
        return ans;
    }
};