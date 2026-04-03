class Solution {
public:
    vector<vector<int>> graph;
    void bfs(int src , vector<int>& visited){
        queue<int> q;
        visited[src] = 1;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            visited[curr] = 1;
            q.pop();
            for(auto x:graph[curr]){
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            if(visited[i]) continue;
            bfs(i,visited);
            if(visited[source]==1 && visited[destination]==0) return false;
            if(visited[source]==0 && visited[destination]==1) return false;
        }
        return true;
    }
};