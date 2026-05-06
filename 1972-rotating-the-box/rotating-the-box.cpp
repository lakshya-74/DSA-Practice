class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<char>> ans(m,vector<char>(n,'.'));
        for(int i=0;i<n;i++){
            vector<pair<int,int>> pos;
            int count =0;
            for(int j=0;j<m;j++){
                if(grid[i][j]=='#') count++;
                else if(grid[i][j]=='*'){
                    pos.push_back({count,j});
                    count =0;
                }
            }
            pos.push_back({count,m});
            vector<char> v(m,'.');
            for(int k=0;k<pos.size();k++){
                int c = pos[k].first;
                int idx = pos[k].second;
                if(idx!=m) v[idx] = '*';
                idx--;
                while(c--){
                    v[idx--] = '#';
                }
            }
            for(int j=0;j<m;j++){
                ans[j][n-1-i] = v[j];
            }
        }
        return ans;
    }
};