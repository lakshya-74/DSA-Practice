class Solution {
public:
    int rec(int idx, int m , vector<int>& nums , vector<vector<int>>& dp , vector<int>& suff){
        int n = nums.size();
        if(idx>=n) return 0;
        int ans =0;
        if(dp[idx][m]!=-1) return dp[idx][m];
        for(int x=1;x<=2*m && idx+x<=n;x++){
            int opp = rec(idx+x,max(m,x),nums,dp,suff);
            int curr = suff[idx] - opp;
            ans = max(ans,curr);
        }
        return dp[idx][m] = ans;
    }
    int stoneGameII(vector<int>& nums) {
        int n = nums.size();
        vector<int> suff(n,0);
        suff[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--){
            suff[i] = nums[i] + suff[i+1];
        }
        vector<vector<int>> dp(n,vector<int>(2*n+1,-1));
        return rec(0,1,nums,dp,suff);
    }
};