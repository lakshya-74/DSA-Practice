class Solution {
public:
    bool rec(int idx, vector<int>& nums,vector<int>& dp){
        if(idx==nums.size()-1) return true;
        if(nums[idx]==0) return false;
        if(dp[idx]!=-1) return dp[idx];
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<nums.size()  && rec(idx+i,nums,dp)) return dp[idx] =true;
        }
        return dp[idx] = false;
    }
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n+1,-1);
        return rec(0,nums,dp);
    }
};