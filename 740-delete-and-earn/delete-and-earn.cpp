class Solution {
public: 
    int rec(int idx, vector<int>& nums , vector<int>& dp){
        if(idx==0) return nums[0];
        if(idx==1) return max(nums[0],nums[1]);
        if(dp[idx]!=-1) return dp[idx];
        int a = nums[idx] + rec(idx-2,nums,dp);
        int b = rec(idx-1,nums,dp);
        return dp[idx] = max(a,b);
    }
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<int> arr(mx+1,0);
        for(int i=0;i<n;i++){
            arr[nums[i]] += nums[i];
        }
        vector<int> dp(mx+1,-1);
        return rec(mx,arr,dp);
    }
};