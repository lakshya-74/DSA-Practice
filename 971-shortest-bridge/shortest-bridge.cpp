class Solution {
public:
    void change(vector<vector<int>>& grid , int i ,int j){
        if(i<0 || i>=grid.size() || j<0 || j>=grid[0].size() || grid[i][j]==0 || grid[i][j]==-200) return;
        grid[i][j] = -200;
        change(grid,i+1,j);
        change(grid,i-1,j);
        change(grid,i,j+1);
        change(grid,i,j-1); 
    }
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        bool flag = false;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(flag) break;
                if(grid[i][j]==1){
                    change(grid,i,j);
                    flag = true;
                }
            }
            if(flag) break;
        }
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==-200){
                    if(i>0 && i<n-1 && j>0 && j<m-1 && grid[i+1][j]==-200 && grid[i-1][j]==-200 && grid[i][j+1]==-200 && grid[i][j-1]==-200) continue;
                    q.push({i,j});
                }
            }
        }
        while(q.size()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            for(int d=0;d<4;d++){
                int nr = i + dir[d][0];
                int nc = j + dir[d][1];
                if(nr<0 || nr>=n || nc<0 || nc>=m) continue;
                if(grid[nr][nc]==1){
                    return grid[i][j] + 200;
                }
                if(grid[nr][nc]==0){
                    q.push({nr,nc});
                    grid[nr][nc] = grid[i][j] + 1;
                }
            }
        }
        return 0;
    }
};