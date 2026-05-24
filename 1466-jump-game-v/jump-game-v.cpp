class Solution {
public:
    int rec(int idx, vector<int>& arr , int d , vector<int>& dp){
        int n = arr.size();
        if(dp[idx]!=-1) return dp[idx];
        int ans = 1;
        for(int i=idx+1;i<=min(n-1,idx+d);i++){
            if(arr[i]>=arr[idx]){
                break;
            }
            else ans = max(ans,1 + rec(i,arr,d,dp));
        }
        for(int i=idx-1;i>=max(0,idx-d);i--){
            if(arr[i]>=arr[idx]){
                break;
            }
            else ans = max(ans,1 + rec(i,arr,d,dp));
        }
        return dp[idx] = ans;
    }
    int maxJumps(vector<int>& arr, int d) {
        int n = arr.size();
        vector<int> dp(n,-1);
        int ans = 1;
        for(int i=0;i<n;i++){
            if(dp[i]==-1){
                ans = max(ans,rec(i,arr,d,dp));
            }
            else ans = max(ans,dp[i]);
        }
        return ans;
    }
};