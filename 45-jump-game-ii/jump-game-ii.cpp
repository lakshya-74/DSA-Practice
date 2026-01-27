class Solution {
public:
    int rec(int idx, vector<int>& nums,vector<int>& dp){
        if(idx==nums.size()-1) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int a = 1e9;
        for(int i=1;i<=nums[idx];i++){
            if(idx+i<nums.size()) a = min(a,1+rec(idx+i,nums,dp));
        }
        return dp[idx] = a;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(),-1);
        return rec(0,nums,dp);
    }
};