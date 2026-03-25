class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<long long> hor(n,0) , ver(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                hor[i] += grid[i][j];
            }
        }
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                ver[j] += grid[i][j];
            }
        }
        long long sum = 0;
        for(int i=0;i<n;i++){
            sum += hor[i];
        }
        long long total = 0;
        for(int i=0;i<n-1;i++){
            total += hor[i];
            if(2*total == sum ) return true;
        }
        sum = 0;
        for(int i=0;i<m;i++){
            sum += ver[i];
        }
        total =0;
        for(int i=0;i<m;i++){
            total += ver[i];
            if(2*total == sum) return true;
        }
        return false;
    }
};