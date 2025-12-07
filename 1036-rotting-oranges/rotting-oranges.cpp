class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    int orangesRotting(vector<vector<int>>& grid) {
        int initialrotten =0;
        int freshcount =0;
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    initialrotten++;
                    q.push({i,j});
                }
                if(grid[i][j]==1) freshcount++;
            }
        }
        q.push({-1,-1});
        int time=0;
        bfs(q,freshcount,grid,time);
        if(freshcount>0) return -1;
        return time;
    }
    void bfs(queue<pair<int,int>> &q , int &freshcount , vector<vector<int>>& grid,int &time){
        while(q.size()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i==-1 && j==-1){
                if(q.size()==0){
                    break;
                }
                time++;
                q.push({-1,-1});
                continue;
            }
            for(int d=0;d<4;d++){
                int newrow = i + dir[d][0];
                int newcol = j + dir[d][1];
                if(newrow<0 || newrow>=grid.size() || newcol<0 || newcol>=grid[0].size() || grid[newrow][newcol]==0 || grid[newrow][newcol]==2) continue;
                q.push({newrow,newcol});
                grid[newrow][newcol] = 2;
                freshcount--;
            }
        }
    }
};