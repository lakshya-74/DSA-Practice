class Solution {
public:
    int mod = 1e9 + 7;
    int rec(int n,vector<int>& dp , vector<int>& pre){
        if(n==0) return 1;
        if(dp[n]!=-1) return dp[n];
        int total = (2*rec(n-1,dp,pre))%mod;
        if(pre[n]){
            int dupli = rec(pre[n]-1,dp,pre);
            total = (total-dupli+mod)%mod;
        }
        return dp[n] = total%mod;
    }
    int distinctSubseqII(string s) {
        int n = s.size();
        vector<int> dp(n+1,-1);
        vector<int> pre(n+1,0);
        vector<int> lastseen(26,0);
        for(int i=1;i<=n;i++){
            int idx = s[i-1] -'a';
            pre[i] = lastseen[idx];
            lastseen[idx] = i;
        }
        return (rec(n,dp,pre) -1+mod)%mod;
    }
};