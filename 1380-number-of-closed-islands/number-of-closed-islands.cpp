class Solution {
public:
    vector<pair<int,int>> dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};
    bool dfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& visited){
        int n = grid.size();
        int m  = grid[0].size();
        visited[i][j] = 1;
        bool check = true;
        if(i==0 || j==0 || i==n-1 || j==m-1) check = false;
        for(auto p:dir){
            int ni  = i + p.first;
            int nj = j + p.second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==0 && !visited[ni][nj]){
                if(!dfs(ni,nj,grid,visited)) check = false;
            }
        }
        return check;
    }
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans = 0;
        vector<vector<int>> visited(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==0 && !visited[i][j]){
                    if(dfs(i,j,grid,visited)) ans++;
                }
            }
        }
        return ans;
    }
};