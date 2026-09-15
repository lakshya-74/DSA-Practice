class Solution {
public:
    // bool ispalindrome(int i ,int j , string& s){
    //     while(i<j){
    //         if(s[i]!=s[j]) return false;
    //         i++;
    //         j--;
    //     }
    //     return true;
    // }
    vector<vector<bool>> palindrome;
    void fill_palindrome(string& s){
        int n = s.size();
        for(int l=1;l<=n;l++){
            for(int i=0;i+l<=n;i++){
                int j = i+l-1;
                if(i==j) palindrome[i][j] = true;
                else if(i+1==j) palindrome[i][j] = (s[i]==s[j]);
                else{
                    palindrome[i][j] = (s[i]==s[j]) && palindrome[i+1][j-1];
                }
            }
        }
    }
    int rec(int i,int j,string& s,int k,vector<vector<int>>& dp){
        int n = s.size();
        if(i>=n || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        if(palindrome[i][j]){
            int ans = 1+rec(j+1,j+k,s,k,dp);
            ans = max(ans,rec(i,j+1,s,k,dp));
            ans = max(ans,rec(i+1,j+1,s,k,dp));
            return dp[i][j] = ans;
        }
        int ans = rec(i+1,j+1,s,k,dp);
        ans = max(ans,rec(i,j+1,s,k,dp));
        return dp[i][j] = ans;
    }
    int maxPalindromes(string s, int k) {
        int n = s.size();
        if(k==1) return n; 
        vector<vector<int>> dp(n,vector<int>(n,-1));
        palindrome.resize(n+1,vector<bool>(n+1,false));
        fill_palindrome(s);
        return rec(0,k-1,s,k,dp);
    }
};