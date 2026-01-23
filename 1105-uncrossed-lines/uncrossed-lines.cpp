class Solution {
public:
    int rec(int i,int j,vector<int>& nums1 ,vector<int>& nums2,vector<vector<int>>& dp){
        if(i<0 || j<0) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(nums1[i]==nums2[j]) return dp[i][j] = 1 + rec(i-1,j-1,nums1,nums2,dp);
        return dp[i][j] = max(rec(i-1,j,nums1,nums2,dp),rec(i,j-1,nums1,nums2,dp));
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return rec(n-1,m-1,nums1,nums2,dp);
    }
};