class Solution {
public:
    int dp[201][201];
    int rec(int level , int n ,int idx ,vector<vector<int>>& a){
        if(level==n) return 0;
        if(dp[level][idx]!=-1) return dp[level][idx];
        int curr = a[level][idx] + rec(level+1,n,idx,a);
        int next = a[level][idx] + rec(level+1,n,idx+1,a);
        return dp[level][idx] = min(curr,next);
    }
    int minimumTotal(vector<vector<int>>& a) {
        int n = a.size();
        // int idx = 0;
        // int total = a[0][0];
        // for(int i=1;i<n;i++){
        //     if(a[i][idx]<a[i][idx+1]){
        //         total += a[i][idx];
        //     }
        //     else{
        //         total += a[i][idx+1];
        //         idx++;
        //     }
        // }
        // return total;

        // greedy ..... nhi huaa
        // ab dp dekhte hai
        memset(dp,-1,sizeof(dp));
        // return rec(0,n,0,a);

      // -----> // tabulation


        // for(int j=0;j<n;j++){
        //     dp[n-1][j] = a[n-1][j];
        // }
        // for(int i=n-2;i>=0;i--){
        //     for(int j=i;j>=0;j--){
        //         int x = dp[i+1][j] + a[i][j];
        //         int y = dp[i+1][j+1] + a[i][j];
        //         dp[i][j] = min(x,y);
        //     }
        // }
        // return dp[0][0];

        // try it in O(n) space only
        vector<int> arr(n,-1);
        for(int i=0;i<n;i++){
            arr[i] = a[n-1][i];
        }
        for(int i=n-2;i>=0;i--){
            for(int j=0;j<=i;j++){
                int x = arr[j] + a[i][j];
                int y = arr[j+1] + a[i][j];
                arr[j] = min(x,y);
            }
        }
        return arr[0];
    }
};