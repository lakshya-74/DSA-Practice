class Solution {
public:
    vector<vector<int>> reverseSubmatrix(vector<vector<int>>& grid, int x, int y, int k) {
        int n = grid.size();
        int m = grid[0].size();
        int i = x , j = x+k-1;
        while(i<j){
            for(int x=y;x<y+k;x++){
                int temp = grid[i][x];
                grid[i][x] = grid[j][x];
                grid[j][x] = temp;
            }
            i++;
            j--;
        }
        return grid;
    }
};