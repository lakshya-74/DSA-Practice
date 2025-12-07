class Solution {
public:
    int rows , cols;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        rows = heights.size();
        cols = heights[0].size();
        queue<pair<int,int>> q1,q2;
        for(int i=0;i<rows;i++){
            q1.push({i,0});
            q2.push({i,cols-1});
        }
        for(int i=1;i<cols;i++){
            q1.push({0,i});
        }
        for(int i=0;i<cols-1;i++){
            q2.push({rows-1,i});
        }
        vector<vector<bool>> x = bfs(q1,heights);
        vector<vector<bool>> y = bfs(q2,heights);
        vector<vector<int>> ans;
        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                if(x[i][j] && y[i][j]) ans.push_back({i,j});
            }
        }
        return ans;
    }
    vector<vector<bool>> bfs(queue<pair<int,int>> &q, vector<vector<int>>& heights){
        vector<vector<bool>> visited(rows,vector<bool>(cols,false));
        while(q.size()){
            auto curr = q.front();
            q.pop();
            int a = curr.first;
            int b = curr.second;
            visited[a][b] = true;
            for(int i=0;i<4;i++){
                int newrow = a + dir[i][0];
                int newcol = b + dir[i][1];
                if(newrow<0 || newrow>=rows || newcol<0 || newcol>=cols || visited[newrow][newcol] || heights[newrow][newcol]<heights[a][b]) continue;
                q.push({newrow,newcol});
            }
        }
        return visited;
    }
};