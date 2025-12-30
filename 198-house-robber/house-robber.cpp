class Solution {
public:
    vector<int> dp;
    int n;
    vector<int> v;
    // int rec(int level){
    //     if(level>=n) return 0;
    //     if(dp[level]!=-1) return dp[level];
    //     int ans = v[level];
    //     for(int j=2;j<n;j++){
    //         int check = rec(level+j) + v[level];
    //         ans = max(ans,check);
    //     }
    //     return dp[level] = ans;
    // }
    int rec(int level){
        if(level==0) return v[0];
        if(level<0) return 0;
        if(dp[level]!=-1) return dp[level];
        int pick = v[level] + rec(level-2);
        int not_pick = rec(level-1);
        return dp[level] = max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        n = nums.size();
        v = nums;
        dp.resize(n,-1);
        if(n==1) return nums[0];
        // int ans = 0;
        // for(int i=0;i<n;i++){
        //     ans = max(ans,rec(i));
        //     dp.resize(n,-1);
        // }

        // above one is correct but difficult
        return rec(n-1);
        // return ans;
    }
};