class Solution {
public:
    int n;
    vector<vector<int>> dp;
    int find(int i, int target , vector<int>& nums){
        int idx = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if(idx<i) idx = i;
        if (idx<n && nums[idx]==target) return idx;
        return -1;
    }
    int solve(int i , int inc , vector<int>& nums){
        if(i>=n) return 0;
        if(dp[i][inc]!=-1) return dp[i][inc];
        int curr = nums[i] + inc;
        int ans = 1;
        int j = find(i+1,curr+1,nums);
        if(j!=-1){
            ans = max(ans,1 + solve(j,0,nums));
        }
        j = find(i+1,curr,nums);
        if(j!=-1){
            ans = max(ans,1 + solve(j,1,nums));
        }
        return dp[i][inc] = ans;
    }
    int maxSelectedElements(vector<int>& nums) {
        n = nums.size();
        sort(nums.begin(),nums.end());
        dp.resize(n,vector<int>(2,-1));
        int ans = 0;
        for(int i=0;i<n;i++){
            ans = max({ans,solve(i,0,nums),solve(i,1,nums)});
        }
        return ans;
    }
};