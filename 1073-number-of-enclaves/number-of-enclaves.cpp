class Solution {
public:
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    void bfs(int i , int j , vector<vector<int>>& grid , vector<vector<int>>& visited){
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j]= 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int k=0;k<4;k++){
                int ni = x + dx[k];
                int nj = y + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]==1 && !visited[ni][nj]){
                    visited[ni][nj] = 1;
                    q.push({ni,nj});
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        int count =0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(i==0 || j==0 || i==n-1 || j==m-1){
                    if(grid[i][j]==1 && !visited[i][j]){
                        bfs(i,j,grid,visited);
                    }
                }
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && !visited[i][j]) count++;
            }
        }
        return count;
    }
};