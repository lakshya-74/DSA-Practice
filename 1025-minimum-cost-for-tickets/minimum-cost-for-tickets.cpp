class Solution {
public:
    int rec(int idx, vector<int>& v, vector<int>& costs, vector<int>& dp){
        int n = v.size();
        if(idx>=n) return 0;
        if(dp[idx]!=-1) return dp[idx];
        if(v[idx]==0) return dp[idx] = rec(idx+1,v,costs,dp); 
        int a = costs[0] + rec(idx+1,v,costs,dp);
        int b = costs[1] + rec(idx+7,v,costs,dp);
        int c = costs[2] + rec(idx+30,v,costs,dp);
        return dp[idx] = min({a,b,c});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int mx = *max_element(days.begin(),days.end());
        vector<int> v(mx+1,0);
        for(auto x:days){
            v[x] = 1;
        }
        vector<int> dp(mx+1,-1);
        return rec(0,v,costs,dp);
    }
};