class Solution {
public:
    // bool rec(int i , string& s , int minj , int maxj , vector<int>& dp){
    //     if(i==0) return true;
    //     if(dp[i]!=-1) return dp[i];
    //     bool ans = false;
    //     for(int j=max(0,i-maxj);j<=(i-minj);j++){
    //         if(s[j]=='0'){
    //             ans = (ans || rec(j,s,minj,maxj,dp));
    //             if(ans) return dp[i] = true; 
    //         }
    //     }
    //     return dp[i] = ans;
    // }
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        // if(s[n-1]=='1') return false;
        // vector<int> dp(n,-1);
        // return rec(n-1,s,minJump,maxJump,dp);

        vector<int> t(n,0);
        t[0] = 1;
        int max_dist = 0;
        for(int i=0;i<n;i++){
            if(!t[i]) continue;
            int st = max(i+minJump,max_dist+1);
            int end = min(i+maxJump,n-1);
            for(int j=st;j<=end;j++){
                if(s[j]=='0'){
                    t[j] = 1;
                }
            }
            max_dist = max(max_dist,end);
        }
        return t[n-1];
    }
};