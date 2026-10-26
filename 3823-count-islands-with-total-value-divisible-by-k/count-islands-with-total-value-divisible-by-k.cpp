class Solution {
public:
    #define pp pair<int,int>
    #define ll long long
    vector<pp> dir = {{1,0} , {-1,0} , {0,1} , {0,-1}};
    ll dfs(int i , int j , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        ll ans = grid[i][j];
        grid[i][j] = 0;
        for(auto x:dir){
            int ni = i + x.first;
            int nj = j + x.second;
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]>0){
                ans += dfs(ni,nj,grid);
            }
        }
        return ans;
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n  = grid.size();
        int m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]>0){
                    ll ans = dfs(i,j,grid);
                    if(ans%k==0) count++;
                }
            }
        }    
        return count;
    }
};