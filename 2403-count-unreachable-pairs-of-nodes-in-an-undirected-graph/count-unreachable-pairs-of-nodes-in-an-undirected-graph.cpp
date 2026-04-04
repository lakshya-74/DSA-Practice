class Solution {
public:
    #define ll long long 
    vector<vector<int>> graph; 
    void bfs(int src , vector<int>& visited , int& count){
        queue<int> q;
        q.push(src);
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            if(!visited[curr]) count++;
            visited[curr] = 1;
            for(auto x:graph[curr]){
                if(!visited[x]){
                    q.push(x);
                }
            }
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        graph.resize(n);
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> visited(n,0);
        vector<int> v;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                int count = 0;
                bfs(i,visited,count);
                v.push_back(count);
            }
        }
        ll ans = 0;
        ll presum = 0;
        for(int i=0;i<v.size();i++){
            ans += presum*(ll)(v[i]);
            presum += v[i];
        }
        return ans;
    }
};