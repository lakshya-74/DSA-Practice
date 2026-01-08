class Solution {
public:
    int dp[501][501];
    int rec(int i , int j ,vector<int>& nums1,vector<int>& nums2){
        if(i==nums1.size()){
            if(j==0){ // no element picked
                return INT_MIN;
            }
            else return 0;
        }
        if(j==nums2.size()) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        // not pick i
        int notpick =  rec(i+1,j,nums1,nums2);
        int pick = INT_MIN;
        // pick i
        for(int k=j;k<nums2.size();k++){
            pick = max(pick,nums1[i]*nums2[k] + rec(i+1,k+1,nums1,nums2));
        }
        return dp[i][j] = max(pick,notpick);
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,nums1,nums2);
    }
};