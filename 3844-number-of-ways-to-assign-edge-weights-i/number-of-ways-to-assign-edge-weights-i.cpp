class Solution {
public:
    #define ll long long
    int mod = 1e9 + 7;
    ll rec(int curr , int parity , int h , vector<vector<int>>& dp){
        if(curr==h) return dp[curr][parity] = !parity;
        if(dp[curr][parity]!=-1) return dp[curr][parity];
        ll ans = 0;
        ans += rec(curr+1,!parity,h,dp);
        ans += rec(curr+1,parity,h,dp);
        return dp[curr][parity] = ans%mod;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        vector<vector<int>> adj(n+1);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int> q;
        vector<int> visited(n+1,0);
        q.push(1);
        visited[1] = 1;
        int h = 0;
        while(!q.empty()){
            int sz = q.size();
            h++;
            while(sz--){
                int curr = q.front();
                q.pop();
                for(auto x:adj[curr]){
                    if(!visited[x]){
                        q.push(x);
                        visited[x] = 1;
                    }
                }
            }
        }
        h--;
        cout<<h;
        vector<vector<int>> dp(h+1,vector<int>(2,-1));
        ll ans =0;
        ans += rec(0,0,h-1,dp);
        ans += rec(0,1,h-1,dp);
        return ans%mod;
    }
};