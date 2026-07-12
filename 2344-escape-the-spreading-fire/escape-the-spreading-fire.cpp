class Solution {
public:
    #define pp pair<int,int>
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    vector<vector<int>> time;
    void func(vector<vector<int>>& grid){
        queue<pp> q;
        int n = grid.size();
        int m = grid[0].size();
        time.resize(n,vector<int>(m,INT_MAX));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    time[i][j] = 0;
                }    
            }
        }
        while(!q.empty()){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(int k=0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m &&grid[ni][nj]!=2){
                        if(time[ni][nj]>=time[i][j]+1){
                            time[ni][nj] = time[i][j] +1;
                            q.push({ni,nj});
                        }
                    }
                }
        }
    }
    bool check(int t , vector<vector<int>>& grid){
        int n = grid.size();
        int m = grid[0].size();
        if(t>=time[0][0]) return false;
        queue<pp> q;
        q.push({0,0});
        vector<vector<int>> vis(n,vector<int>(m,0));
        vis[0][0] = 1;
        int ct= t;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(int k=0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<m && !vis[ni][nj] && grid[ni][nj]!=2){
                        if(ni==n-1 && nj==m-1){
                            if(time[ni][nj]>=ct+1) return true;
                        }
                        else{
                            if(time[ni][nj]>ct+1){
                                vis[ni][nj] = 1;
                                q.push({ni,nj});
                            }
                        }
                    }
                }
            }
            ct++;
        }
        return false;
    }
    int maximumMinutes(vector<vector<int>>& grid) {
        func(grid);
        int lo = 0;
        int hi = 1e9;
        int ans= -1;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,grid)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
};