class Solution {
public:
    #define ll long long
    #define pp pair<int,int>
    // here we have to make sure that each edge we are traversing have weight >=mid and the total sum till n-1 should be <= k
    // generally if you have to find min weight path we use dijsktra although it is correct in this question also , but here we had given DAG so we can use topo order and calulate the min weight till n-1 edge using dp
    bool check(ll x, vector<vector<pp>>& adj,vector<int>& topo,ll k){
        int n = adj.size();
        vector<ll> dp(n,1e18);
        dp[0] =0;
        for(int i=0;i<topo.size();i++){
            int u = topo[i];
            if(dp[u]==1e18) continue;
            for(auto a:adj[u]){
                int v = a.first;
                int w = a.second;
                if(w>=x) dp[v] = min(dp[v],dp[u]+w);
            }
        }
        return dp[n-1]<=k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pp>> adj(n);
        int mx = 0;
        vector<int> indegree(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            if(!online[u] || !online[v]) continue;
            adj[u].push_back({v,w});
            indegree[v]++;
            mx = max(mx,w);
        }
        vector<int> topo;
        queue<int> q;
        for(int i=0;i<n;i++){
            if(online[i] && indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            topo.push_back(curr);
            for(auto x:adj[curr]){
                int v = x.first;
                indegree[v]--;
                if(indegree[v]==0) q.push(v);
            }
        }
        ll lo = 0;
        ll hi = mx;
        int ans = -1;
        while(lo<=hi){
            ll mid = lo + (hi-lo)/2;
            if(check(mid,adj,topo,k)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};