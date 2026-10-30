class Solution {
public:
    #define ll long long
    #define pp pair<ll,pair<ll,ll>>    
    int shortestPath(int n, vector<vector<int>>& edges, string labels, int k) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            adj[u].push_back({v,w});
        }
        vector<vector<ll>> dist(n,vector<ll>(k+1,1e18));
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        pq.push({0,{0,1}});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            ll d = curr.first;
            ll node = curr.second.first;
            ll a = curr.second.second;
            if(d>dist[node][a]) continue;
            if(node==n-1) return d;
            for(auto x:adj[node]){
                ll next = x.first;
                ll d1 = x.second;
                ll nk = 0;
                if(labels[node]==labels[next]) nk = a+1;
                else nk = 1;
                if(nk>k) continue;
                ll nd = d + d1;
                if(nd<dist[next][nk]){
                    dist[next][nk] = nd;
                    pq.push({nd,{next,nk}});
                }
            }
        }
        return -1;
    }
};