class Solution {
public:
    long long mn = -1e18;
    long long rec(int i , int j , int k , vector<int>& nums1 , vector<int>& nums2,vector<vector<vector<long long>>>& dp){
        if(k>i+1 || k>j+1) return -1e18;
        if(i<0 || j<0){
            if(k>0) return -1e18;
            return 0;
        }
        if(dp[i][j][k]!=mn) return dp[i][j][k];
        long long a = -1e18;
        if(k>0){
            a = (long long)nums1[i]*(long long)nums2[j] + rec(i-1,j-1,k-1,nums1,nums2,dp);
        }    
        long long b = rec(i-1,j,k,nums1,nums2,dp);
        long long c = rec(i,j-1,k,nums1,nums2,dp);
        return dp[i][j][k] = max(a,max(b,c));
    }
    long long maxScore(vector<int>& nums1, vector<int>& nums2, int k) {
        int n = nums1.size();
        int m = nums2.size();
        vector<vector<vector<long long>>> dp(n,vector<vector<long long>>(m,vector<long long>(k+1,mn)));
        return rec(n-1,m-1,k,nums1,nums2,dp);
    }
};