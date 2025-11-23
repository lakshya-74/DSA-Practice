class Solution {
public:
    vector<int> visited;
    void dfs(int i , vector<vector<int>>&adj){
        visited[i] = 1;
        for(auto x:adj[i]){
            if(visited[x]==0){
                dfs(x,adj);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        visited.resize(n,0);
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j]==1 && i!=j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(visited[i]==0){
                count++;
                dfs(i,adj);
            }
        }
        return count;
    }
};