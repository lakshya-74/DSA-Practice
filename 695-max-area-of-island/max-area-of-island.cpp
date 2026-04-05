class Solution {
public:
    vector<vector<int>> visited;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    void bfs(int i , int j , int& count,vector<vector<int>>& grid){
        int n = visited.size();
        int m = visited[0].size();
        queue<pair<int,int>> q;
        q.push({i,j});
        visited[i][j] = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int k=0;k<4;k++){
                int ni = x + dx[k];
                int ny = y + dy[k];
                if(ni>=0 && ni<n && ny>=0 && ny<m && visited[ni][ny]==0 && grid[ni][ny]==1){
                    q.push({ni,ny});
                    count++;
                    visited[ni][ny] = 1;
                }
            }
        }
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n,vector<int>(m,0));
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1 && visited[i][j]==0){
                    int count =1;
                    bfs(i,j,count,grid);
                    ans = max(ans,count);
                }
            }
        }
        return ans;
    }
};