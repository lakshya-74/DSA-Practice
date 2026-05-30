class Solution {
public:
    #define pp pair<int,pair<int,int>>
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> graph(n);
        for(int i=0;i<flights.size();i++){
            int u = flights[i][0];
            int v = flights[i][1];
            int w = flights[i][2];
            graph[u].push_back({v,w});
        } 
        vector<int> dist(n,1e8);
        queue<pp> q;
        q.push({0,{src,0}});
        dist[src] = 0;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int stops = curr.first;
            int node = curr.second.first;
            int d = curr.second.second;
            if(stops>k) continue;
            for(auto x:graph[node]){
                if(d+x.second <dist[x.first]){
                    dist[x.first] = d+x.second;
                    q.push({stops+1,{x.first,d+x.second}});
                }
            }
        }
        return dist[dst]==1e8?-1:dist[dst];
    }
};