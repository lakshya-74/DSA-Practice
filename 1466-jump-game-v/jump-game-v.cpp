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
        int ans = 1;
        // vector<int> dp(n,-1);

        // recur. + memoisation code ---->

        // for(int i=0;i<n;i++){
        //     if(dp[i]==-1){
        //         ans = max(ans,rec(i,arr,d,dp));
        //     }
        //     else ans = max(ans,dp[i]);
        // }
        // return ans;


        // more optimised...
        // top down approach
        // we can't directly apply that thing b/c for each idx we have to go left and right both at once we can store only left values or right 
        // so ...
        // if we sort the array based on values and then calculate small values first

        vector<int> dp(n,0);
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            v[i] = {arr[i],i};
        }
        sort(v.begin(),v.end());

        // now do what we are doing in our normal top-down approach
        for(int i=0;i<n;i++){
            int idx = v[i].second;
            int val = v[i].first;
            int x = 1;
            for(int j=idx+1;j<=min(n-1,idx+d);j++){
                if(arr[j]>=val) break;
                else x = max(x,1 + dp[j]);
            }
            for(int j=idx-1;j>=max(0,idx-d);j--){
                if(arr[j]>=val) break;
                else x = max(x,1 + dp[j]);
            }
            dp[idx] = x;
            ans = max(ans,x);
        }
        return ans;
    }
};