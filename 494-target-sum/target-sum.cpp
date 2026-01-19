class Solution {
public:
    int sum = 0;
    int rec(int idx,int target,vector<int>&nums,vector<vector<int>>& dp){
        if(target>sum || target<-sum) return 0;
        if(idx==0){
            if(target==nums[0] && target==-nums[0]) return 2;
            return (nums[idx]==abs(target));
        }
        if(dp[idx][target+sum]!=-1) return dp[idx][target+sum];
        // take -ve
        int a = rec(idx-1,target-nums[idx],nums,dp);
        // take +ve
        int b = rec(idx-1,target+nums[idx],nums,dp);
        return dp[idx][target+sum] = a+b;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        for(int i=0;i<n;i++) sum += nums[i];
        vector<vector<int>> dp(n,vector<int>(2*sum+1,-1));
        return rec(n-1,target,nums,dp);
    }
};