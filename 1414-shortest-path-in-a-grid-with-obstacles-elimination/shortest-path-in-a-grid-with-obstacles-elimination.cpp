class Solution {
public:
    #define pp pair<int,pair<int,int>>
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        queue<vector<int>> q;
        dp[0][0]=  k;
        // {i,j,k,dist}
        q.push({0,0,k,0});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr[0];
            int j = curr[1];
            int ck = curr[2];
            int d = curr[3];
            if(i==n-1 && j==m-1) return d;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    int rem = ck - grid[ni][nj];
                    if(dp[ni][nj]<rem){
                        dp[ni][nj] = rem;
                        q.push({ni,nj,rem,d+1});
                    }
                }
            }
        }
        return -1;
    }
};
        