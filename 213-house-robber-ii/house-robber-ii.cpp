class Solution {
public:
    vector<int> dp;
    int n;
    int rec1(vector<int>&nums , int level){
        if(level==0) return nums[0];
        if(level<0) return 0;
        if(dp[level]!=-1) return dp[level];
        int pick = nums[level] + rec1(nums,level-2);
        int not_pick = rec1(nums,level-1);
        return dp[level] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        if(n==1) return nums[0];
        vector<int> temp1 ,temp2;
        for(int i=0;i<n;i++){
            if(i!=0) temp1.push_back(nums[i]);
            if(i!=n-1) temp2.push_back(nums[i]);
        }
        dp.resize(n-1,-1);
        int x = rec1(temp1,n-2);
        dp.assign(n-1,-1);
        int y = rec1(temp2,n-2);
        return max(x,y);
    }
};