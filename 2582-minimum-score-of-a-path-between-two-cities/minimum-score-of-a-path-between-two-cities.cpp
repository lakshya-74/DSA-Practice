class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0]-1;
            int v = roads[i][1]-1;
            int dist = roads[i][2];
            adj[u].push_back({v,dist}); 
            adj[v].push_back({u,dist}); 
        }
        queue<int> q;
        q.push(0);
        vector<int> visited(n,0);
        visited[0] = 1;
        int ans = INT_MAX;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            for(auto x:adj[curr]){
                ans = min(ans,x.second);
                if(!visited[x.first]){
                    visited[x.first] = 1;
                    q.push(x.first);
                }
            }
        }
        return ans;
    }
};