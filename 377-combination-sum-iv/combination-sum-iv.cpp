class Solution {
public:
    int mod = 1e9 + 7;
    int combinationSum4(vector<int>& arr, int x) {
        int n = arr.size();
        sort(arr.begin(),arr.end());
        vector<double> dp(x+1,0);
        dp[0]=1;
        for(int sum = 1;sum<=x;sum++){
            for(int i=0;i<n;i++){
                if(arr[i]<=sum){
                    dp[sum] = (dp[sum]+dp[sum-arr[i]]);
                    // if(dp[sum]>=mod) dp[sum] -= mod;
                    // here we are adding the number of ways 
                    // to make the sum by including the current coin arr[i]
                }
            }
        }
        return dp[x];
    }
};