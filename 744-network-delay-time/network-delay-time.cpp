class Solution {
public:
    #define pp pair<int,int>
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pp>> graph(n+1);
        for(int i=0;i<times.size();i++){
            int u = times[i][0];
            int v = times[i][1];
            int w = times[i][2];
            graph[u].push_back({v,w});
        }
        priority_queue<pp,vector<pp> , greater<pp>> pq;
        pq.push({0,k});
        vector<int> dist(n+1,1e8);
        dist[k] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            if(curr.first==1e8) continue;
            for(auto x:graph[curr.second]){
                if(curr.first + x.second < dist[x.first]){
                    dist[x.first] = curr.first + x.second;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
        int mx = 0;
        for(int i=1;i<=n;i++){
            if(dist[i]==1e8) return -1;
            mx = max(mx,dist[i]);
        }
        return mx;
    }
};