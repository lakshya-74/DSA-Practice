class Solution {
public:
    bool rec(int idx , vector<int>& arr , vector<int>& dp,vector<int>& visited){
        if(arr[idx]==0) return true;
        if(dp[idx]!=-1) return dp[idx];
        visited[idx] = 1; 
        bool a = false;
        int x = idx + arr[idx];
        int y = idx - arr[idx];
        if(x < arr.size() && !visited[x]) a = rec(idx+arr[idx],arr,dp,visited);
        bool b = false;
        if(y>=0 && !visited[y]) b = rec(idx-arr[idx],arr,dp,visited); 
        visited[idx] = 0;
        return dp[idx] = a || b;
    }
    bool canReach(vector<int>& arr, int start) {
        vector<int> dp(arr.size(),-1);
        vector<int> visited(arr.size(),0);
        return rec(start,arr,dp,visited);
    }
};