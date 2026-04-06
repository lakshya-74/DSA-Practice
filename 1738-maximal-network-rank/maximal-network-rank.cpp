class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        vector<vector<int>> adj(n);
        vector<int> indegree(n,0);
        for(int i=0;i<roads.size();i++){
            int u = roads[i][0];
            int v = roads[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
            indegree[u]++;
            indegree[v]++;
        }
        int ans =0;
        for(int i=0;i<n-1;i++){
            for(int j=i+1;j<n;j++){
                int x = indegree[i] + indegree[j];
                for(int k=0;k<adj[i].size();k++){
                    if(adj[i][k]==j){
                        x -= 1;
                        break;
                    }
                }
                ans = max(ans,x);
            }
        }
        return ans;
    }
};