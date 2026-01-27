class Solution {
public:
    typedef long long ll;
    #define pp pair<int,int>
    vector<vector<pp>> graph;
    map<int,int> djikstra(int src,int v){
        vector<int> visited(v,0);
        priority_queue<pp, vector<pp> , greater<pp> > pq;
        vector<int> via(v);
        map<int,int> mp;
        for(int i=0;i<v;i++){
            mp[i] = INT_MAX;
        }
        mp[src] = 0;
        pq.push({0,src});
        while(pq.size()){
            pp curr = pq.top();
            pq.pop();
            if(visited[curr.second]==1){
                continue;
            }
            visited[curr.second] = 1;
            for(auto x:graph[curr.second]){
                if(visited[x.first]==0 && mp[x.first] > mp[curr.second] + x.second){
                    mp[x.first] = mp[curr.second] + x.second;
                    pq.push({mp[curr.second] + x.second,x.first});
                    via[x.first] = curr.second;
                }
            }
        }
        return mp;
    }
    int minCost(int n, vector<vector<int>>& a) {
        graph.resize(n);
        for(int i=0;i<a.size();i++){
            int x = a[i][0];
            int y = a[i][1];
            int z = a[i][2];
            graph[x].push_back({y,z});
            graph[y].push_back({x,2*z});
        }
        map<int,int> sp = djikstra(0,n);
        return (sp[n-1]==INT_MAX?-1:sp[n-1]);
    }
};