class Solution {
public:
    int rec(int idx,vector<vector<int>>& pairs,vector<int>& dp){
        if(idx==pairs.size()) return 0;
        if(dp[idx]!=-1) return dp[idx];
        int ans = 1;
        for(int i=idx+1;i<pairs.size();i++){
            if(pairs[i][0]>pairs[idx][1]) ans = max(ans,1+rec(i,pairs,dp));
        }
        return dp[idx] = ans;
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        int n = pairs.size();
        sort(pairs.begin(),pairs.end(),[](vector<int>& a , vector<int>& b){
            return a[1] < b[1];
        });
        vector<int> dp(n,-1);
        rec(0,pairs,dp);
        int ans= 0;
        for(int i=0;i<n;i++){
            ans = max(ans,dp[i]);
        }
        return ans;
    }
};