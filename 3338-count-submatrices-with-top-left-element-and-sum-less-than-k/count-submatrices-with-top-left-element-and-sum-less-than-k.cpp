class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> preSum(n,vector<int>(m,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                int curr = grid[i][j];
                int preRow = 0;
                if(i-1>=0){
                    preRow = preSum[i-1][j];
                }
                int preCol = 0;
                if(j-1>=0){
                    preCol = preSum[i][j-1];
                }
                int preDiag = 0;
                if(i-1>=0 && j-1>=0){
                    preDiag = preSum[i-1][j-1];
                }
                preSum[i][j] = curr + preRow + preCol - preDiag;
            }
        }
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(preSum[i][j]<=k) count++;
            }
        }
        return count;
    }
};