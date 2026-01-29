class Solution {
public: 
    bool is_perfect(long long n){
        long long x = sqrt(n);
        return (x*x)==n;
    }
    int rec(int idx,int target , vector<int>& v,vector<vector<int>>& dp){
        if(idx==0){
            if(target%v[0]==0) return target/v[0];
            return 1e9;
        }
        if(dp[idx][target]!=-1) return dp[idx][target];
        int a = 1e9;
        if(target>=v[idx]) a = 1 + rec(idx,target-v[idx],v,dp);
        int b = rec(idx-1,target,v,dp);
        return dp[idx][target] = min(a,b);
    }
    int numSquares(int n) {
        vector<int> v;
        for(long long i =1;i<=n;i++){
            if(is_perfect(i)) v.push_back(i);
        }
        int a = v.size();
        vector<vector<int>> dp(a,vector<int>(n+1,-1));
        return rec(a-1,n,v,dp);
    }
};