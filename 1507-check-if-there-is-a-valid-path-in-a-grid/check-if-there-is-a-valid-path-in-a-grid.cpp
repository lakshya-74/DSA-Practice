class Solution {
public:
    bool hasValidPath(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> change = {{0,-1,0,1},{-1,0,1,0},{0,-1,1,0},{0,1,1,0},{0,-1,-1,0},{0,1,-1,0}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        queue<pair<int,int>> q;
        q.push({0,0});
        visited[0][0] = 1;
        while(!q.empty()){
            auto curr = q.front();
            q.pop();
            int i = curr.first;
            int j = curr.second;
            if(i==n-1 && j==m-1) return true;
            vector<int> dir = change[grid[i][j]-1];
            for(int k=0;k<4;k+=2){
                int ni = i + dir[k];
                int nj = j + dir[k+1];
                if(ni>=0 && ni<n && nj>=0 && nj<m && !visited[ni][nj]){
                    vector<int> back = change[grid[ni][nj]-1];
                    bool flag = false;
                    for(int l=0;l<4;l+=2){
                        int li = ni + back[l];
                        int lj = nj + back[l+1];
                        if(li==i && lj==j){
                            flag = true;
                            break;
                        }
                    }
                    if(flag){
                        visited[ni][nj] = 1;
                        q.push({ni,nj});
                    }
                }
            }
        }
        return false;
    }
};