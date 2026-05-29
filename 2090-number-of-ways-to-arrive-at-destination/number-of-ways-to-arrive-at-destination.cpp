class Solution {
public:
    #define ll long long
    #define pp pair<ll,int>
    int mod = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pp>> graph(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            int w = roads[i][2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        vector<ll> dist(n,1e18) , ways(n,0);
        priority_queue<pp,vector<pp> , greater<pp>> pq;
        pq.push({0,0});
        dist[0] = 0;
        ways[0] = 1;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ll d =curr.first;
            int node = curr.second;
            if(d>dist[node]) continue;
            for(auto x:graph[node]){
                ll y = x.second + d;
                if(y==dist[x.first]) ways[x.first] = (ways[x.first]+ways[node])%mod;
                else if(y<dist[x.first]){
                    dist[x.first] = y;
                    ways[x.first] = ways[node];
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        return ways[n-1]%mod;
    }
};