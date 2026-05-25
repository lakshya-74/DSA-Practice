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
        int count =0;
        for(int i=1;i<n;i++){
            if(i-minJump>=0){
                count += t[i-minJump];
            }
            if(i-maxJump-1>=0){
                count -= t[i-maxJump-1];
            }
            if(count>0 && s[i]=='0') t[i] = 1;
        }
        return t[n-1]>0;
    }
};