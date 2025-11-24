class Solution {
public:
    vector<vector<int>> visited;
    void dfs(vector<vector<char>> &grid , int i ,int j){
        if(i<0 || j<0 || i>=grid.size() || j >= grid[0].size() || grid[i][j]=='0' || visited[i][j]==1) return; 
        visited[i][j] = 1;
        dfs(grid,i+1,j);
        dfs(grid,i-1,j);
        dfs(grid,i,j+1);
        dfs(grid,i,j-1);

    }
    int numIslands(vector<vector<char>>& grid) {
        visited.resize(grid.size(),vector<int> (grid[0].size(),0));
        int count =0;
        for(int i=0;i<grid.size();i++){
            for(int j =0;j<grid[0].size();j++){
                if(grid[i][j]=='1' && visited[i][j]==0){
                    count++;
                    dfs(grid,i,j);
                }
            }
        }
        return count;
    }
};