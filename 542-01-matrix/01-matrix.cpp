class Solution {
public:
    vector<vector<int>> dir = {{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));
        vector<vector<int>> ans(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j]==0){
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        q.push({-1,-1});
        int dist = 1;
        while(q.size()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i==-1 && j==-1){
                if(q.size()==0) break;
                dist++;
                q.push({-1,-1});
                continue;
            }
            for(int d=0;d<4;d++){
                int newrow = i + dir[d][0];
                int newcol = j + dir[d][1];
                if(newrow<0 || newrow>=n || newcol<0 || newcol>=m || visited[newrow][newcol]==1) continue;
                visited[newrow][newcol] = 1;
                ans[newrow][newcol] = dist;
                q.push({newrow,newcol});
            }
        }
        return ans;
    }
};