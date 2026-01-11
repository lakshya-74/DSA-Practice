class Solution {
public:
    bool rec(int idx,int target , vector<int>& arr,vector<vector<int>>& dp){
        if(target==0) return true;
        if(idx==0) return arr[0]==target;
        if(dp[idx][target]!=-1) return dp[idx][target];
        // pick
        bool a = false;
        if(target>=arr[idx]) a = rec(idx-1,target-arr[idx],arr,dp);
        // not pick
        bool b = rec(idx-1,target,arr,dp);
        return dp[idx][target] = (a || b);
    }
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++) sum += nums[i];
        if(sum&1) return false;
        vector<vector<int>> dp(n,vector<int>(sum/2+1,-1));
        return rec(n-1,sum/2,nums,dp);
    }
};