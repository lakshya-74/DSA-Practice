class Solution {
public:
    vector<vector<int>> visited;
    vector<vector<pair<int,int>>> parent;
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    bool bfs(int i , int j , vector<vector<char>>& grid){
        visited[i][j] = 1;
        queue<pair<int,int>> q;
        q.push({i,j});
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int x = curr.first;
            int y = curr.second;
            for(int k=0;k<4;k++){
                int ni = x + dx[k];
                int nj = y + dy[k];
                if(ni>=0 && ni<grid.size() && nj>=0 && nj<grid[0].size() && grid[ni][nj]==grid[x][y]){
                    if(!visited[ni][nj]){
                        visited[ni][nj] = 1;
                        q.push({ni,nj});
                        parent[ni][nj] = {x,y};
                    }    
                    else{
                        if(parent[x][y].first != ni || parent[x][y].second != nj) return true;
                    }
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        visited.resize(n,vector<int>(m,0));
        parent.resize(n,vector<pair<int,int>>(m));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                parent[i][j] = {i,j};
            }
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]){
                    if(bfs(i,j,grid)) return true;
                }
            }
        }
        return false;
    }
};