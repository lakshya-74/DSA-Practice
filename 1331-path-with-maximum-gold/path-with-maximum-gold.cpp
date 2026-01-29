class Solution {
public:
    vector<vector<int>> visited;
    int rec(int i ,int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(i<0 || j<0 ||i>=n || j>=m || grid[i][j]==0) return 0;
        if(visited[i][j]) return 0;
        visited[i][j] = 1;
        int a = grid[i][j] + rec(i+1,j,grid);
        int b = grid[i][j] + rec(i-1,j,grid);
        int c = grid[i][j] + rec(i,j+1,grid);
        int d = grid[i][j] + rec(i,j-1,grid);
        visited[i][j] = 0;
        return max(a,max(b,max(c,d)));
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int ans = 0;
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n,vector<int>(m,0));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==0) continue;
                ans = max(ans,rec(i,j,grid));
            }
        }
        return ans;
    }
};