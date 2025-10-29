class Solution {
public:
    vector<vector<int>> result;
    vector<int> visited;
    void dfs(int src ,int dest ,vector<int>&v,vector<vector<int>> graph){
        if(src==dest){
            v.push_back(src);
            result.push_back(v);
            v.pop_back();
            return;
        }
        visited[src] = 1;
        v.push_back(src);
        for(auto x:graph[src]){
            if(visited[x]==0){
                dfs(x,dest,v,graph);
            }
        }
        v.pop_back();
        visited[src] = 0;
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<int> v;
        int n = graph.size();
        visited.assign(n,0);
        dfs(0,n-1,v,graph);
        return result;
    }
};