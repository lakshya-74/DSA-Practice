class Solution {
public:
    #define pp pair<int,int>
    vector<int> mv = {0,1,0,-1,0};
    bool check(int idx , int r, int c , vector<vector<int>>& cells){
        vector<vector<int>> grid(r,vector<int>(c,0));
        for(int i=0;i<=idx;i++){
            grid[cells[i][0]-1][cells[i][1]-1] = 1;
        }
        queue<pp> q;
        for(int i=0;i<c;i++){
            if(grid[0][i]==0){
                q.push({0,i});
                grid[0][i] = 1; 
            }
        }
        while(!q.empty()){
            auto [i,j] = q.front();
            q.pop();
            if(i==r-1) return true;
            for(int k=0;k<4;k++){
                int ni = i + mv[k];
                int nj = j + mv[k+1];
                if(ni>=0 && ni<r && nj>=0 && nj<c && !grid[ni][nj]){
                    q.push({ni,nj});
                    grid[ni][nj] = 1;
                }
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        int sz = cells.size();
        int lo = 0;
        int hi = sz-1;
        int ans;
        while(lo<=hi){
            int mid = lo + (hi-lo)/2;
            if(check(mid,row,col,cells)){
                ans = mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans+1;
    }
};