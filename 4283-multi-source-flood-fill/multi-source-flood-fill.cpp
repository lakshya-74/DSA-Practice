class Solution {
public:
    vector<vector<int>> colorGrid(int n, int m, vector<vector<int>>& sources) {
        vector<vector<int>> grid(n,vector<int>(m,0));
        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));
        queue<pair<int,pair<int,int>>> q;
        for(int i=0;i<sources.size();i++){
            q.push({sources[i][0],{sources[i][1],sources[i][2]}});
            grid[sources[i][0]][sources[i][1]] = sources[i][2];
            dist[sources[i][0]][sources[i][1]] = 0;
        }
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second.first;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m){
                    if(dist[ni][nj]>dist[i][j]+1){
                        dist[ni][nj] = dist[i][j] + 1;
                        grid[ni][nj] = curr.second.second;
                        q.push({ni,{nj,curr.second.second}});
                    }
                    else if(dist[ni][nj]==dist[i][j]+1){
                        if(grid[ni][nj]<curr.second.second){
                            grid[ni][nj] = curr.second.second;
                            q.push({ni,{nj,curr.second.second}});
                        }
                    }
                }
            }
        }
        return grid;
    }
};