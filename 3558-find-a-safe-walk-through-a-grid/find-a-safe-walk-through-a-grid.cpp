class Solution {
public:
    #define pp pair<int,pair<int,int>>
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        priority_queue<pp> pq;
        if(grid[0][0]==1) health--;
        if(health>0) pq.push({health,{0,0}});
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[0][0] = 1;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int val = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            if(i==n-1 && j==m-1) return val>0;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj]){
                    if(val>=1){ 
                        if(grid[ni][nj]==1) pq.push({val-1,{ni,nj}});
                        else pq.push({val,{ni,nj}});
                        visited[ni][nj] = 1;
                    }    
                }
            }
        }
        return false;
    }
};