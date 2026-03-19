class Solution {
public:
    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        vector<vector<int>> xsum(n,vector<int>(m,0));
        vector<vector<int>> ysum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                xsum[i][j] = (grid[i][j]=='X');
                ysum[i][j] = (grid[i][j]=='Y');

                if(i-1>=0){
                    xsum[i][j] += xsum[i-1][j];
                    ysum[i][j] += ysum[i-1][j];
                }
                if(j-1>=0){
                    xsum[i][j] += xsum[i][j-1];
                    ysum[i][j] += ysum[i][j-1];
                }
                if(i-1>=0 && j-1>=0){
                    xsum[i][j] -= xsum[i-1][j-1];
                    ysum[i][j] -= ysum[i-1][j-1];
                }
                if(xsum[i][j]==ysum[i][j] && xsum[i][j]>0) count++;
            }
        }
        return count;
    }
};