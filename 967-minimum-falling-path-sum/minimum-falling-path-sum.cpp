class Solution {
public:
    int dp[101][101];
    int rec(int i , int j ,vector<vector<int>>& matrix){
        int n = matrix.size();
        if(i<0 || j<0 || j>=n) return 1e5;
        if(i>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int x = matrix[i][j] + rec(i+1,j,matrix);
        int y = matrix[i][j] + rec(i+1,j+1,matrix);
        int z = matrix[i][j] + rec(i+1,j-1,matrix);
        return dp[i][j] = min(x,min(y,z));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int ans = INT_MAX;
        int n = matrix.size();
        // memset(dp,-1,sizeof(dp));
        // for(int i=0;i<n;i++){
        //     ans = min(ans,rec(0,i,matrix));
        // }
        // return ans;

        vector<int> check(n);
        for(int i=0;i<n;i++){
            check[i] = matrix[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            vector<int> temp(n);
            for(int j=0;j<n;j++){
                int a = check[j];
                int b = INT_MAX;
                int c = INT_MAX;
                if(j+1<n) b = check[j+1];
                if(j-1>=0) c = check[j-1];
                int x = min(a,min(b,c));
                temp[j] = matrix[i][j] + x;
            }
            check = temp;
        }
        int ans = INT_MAX;
        for(int i=0;i<n;i++){
            ans = min(ans,check[i]);
        }
        return ans;
    }
};