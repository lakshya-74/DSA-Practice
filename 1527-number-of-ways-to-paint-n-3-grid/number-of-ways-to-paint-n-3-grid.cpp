class Solution {
public:
    int mod = 1e9 + 7;
    int dp[5000][4][4][4];
    int rec(int level , int n , int pre1 , int pre2 , int pre3){
        if(level==n) return 1;
        if(dp[level][pre1][pre2][pre3]!=-1) return dp[level][pre1][pre2][pre3];
        int ans = 0;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                for(int k=0;k<3;k++){
                    if(i!=j && j!=k && i!=pre1 && j!=pre2 && k!=pre3){
                        ans = (ans+rec(level+1,n,i,j,k))%mod;
                    }    
                }
            }
        }
        return dp[level][pre1][pre2][pre3] = ans;
    }
    int numOfWays(int n) {
        memset(dp,-1,sizeof(dp));
        return rec(0,n,3,3,3);
    }
};