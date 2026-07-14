class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int idx, int f, int s , vector<int>& nums,vector<vector<vector<int>>>& dp){
        if(idx==nums.size()){
            if(f!=0 && s!=0){
                if(f==s) return 1;
            }
            return 0;
        }
        if(dp[idx][f][s]!=-1) return dp[idx][f][s];
        int a = rec(idx+1,f,s,nums,dp);
        int b = rec(idx+1,__gcd(f,nums[idx]),s,nums,dp);
        int c = rec(idx+1,f,__gcd(s,nums[idx]),nums,dp);
        int ans = a;
        ans = (ans+b)%mod;
        ans = (ans+c)%mod;
        return dp[idx][f][s] = ans;
    }
    int subsequencePairCount(vector<int>& nums) {
        int n = nums.size();
        int mx = *max_element(nums.begin(),nums.end());
        vector<vector<vector<int>>> dp(n,vector<vector<int>>(mx+1,vector<int>(mx+1,-1)));
        return rec(0,0,0,nums,dp);
    }
};