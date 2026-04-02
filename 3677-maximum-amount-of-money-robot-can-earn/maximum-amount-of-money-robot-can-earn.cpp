class Solution {
public:
    // int rec(int i , int j , int k , vector<vector<int>>& nums){
    //     if(i<0 || j<0) return -1e8;
    //     if(i==0 && j==0){
    //         if(nums[0][0]>=0) return nums[0][0];
    //         else{
    //             if(k>0){
    //                 return 0;
    //             }
    //             return nums[i][j];
    //         }
    //     }
    //     if(dp[i][j][k]!=-1) return dp[i][j][k];
    //     int x = rec(i-1,j,k,nums);
    //     int y = rec(i,j-1,k,nums);
    //     int z = max(x,y);
    //     int a = -1e8;
    //     if(nums[i][j]>=0){
    //         a = nums[i][j] + z;
    //     }
    //     else{
    //         int l = -1e8;
    //         if(k>0){
    //             int p = rec(i,j-1,k-1,nums);
    //             int q = rec(i-1,j,k-1,nums);
    //             l = max(p,q);
    //         }
    //         int m = nums[i][j] +z;
    //         a = max(l,m);
    //     }
    //     return dp[i][j][k] = a;
    // }

    int maximumAmount(vector<vector<int>>& nums) {
        int n = nums.size();
        int m = nums[0].size();
        int dp[n][m][3];
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                for(int k=0;k<3;k++){
                    dp[i][j][k] = 0;
                }
            }
        }
        // return rec(n-1,m-1,2,coins);
        for(int k=0;k<3;k++){
            if(nums[0][0]>=0){
                dp[0][0][k] = nums[0][0];
            }
            else{
                if(k>0) dp[0][0][k] = 0;
                else dp[0][0][k] = nums[0][0];
            }
        }

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 && j==0) continue;
                for(int k=0;k<3;k++){
                    int x = -1e8;
                    if(i>0) x = max(x,dp[i-1][j][k]);
                    if(j>0) x = max(x,dp[i][j-1][k]);
                    int ans = -1e8;
                    if(nums[i][j]>=0){
                        ans = nums[i][j] + x;
                    }
                    else{
                        int l = -1e8;
                        if(k>0){
                            if(i>0) l = max(dp[i-1][j][k-1],l);
                            if(j>0) l = max(dp[i][j-1][k-1],l); 
                        }
                        int m = nums[i][j] + x;
                        ans = max(l,m);
                    }
                    dp[i][j][k] = ans;
                }
            }
        }
        return dp[n-1][m-1][2];
    }
};