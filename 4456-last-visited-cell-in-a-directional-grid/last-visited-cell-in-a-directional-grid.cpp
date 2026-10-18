class Solution {
public:
    bool valid(vector<int>& ans, char c , vector<vector<bool>>& visited){
        int ni = ans[0] , nj = ans[1];
        if(c=='L') nj--;
        else if(c=='R') nj++;
        else if(c=='U') ni--;
        else ni++;
        int n = visited.size();
        int m = visited[0].size();
        if(ni<0 || ni>=n || nj<0 || nj>=m || visited[ni][nj]) return false;
        visited[ni][nj] = true;
        ans = {ni,nj};
        return true;
    }
    vector<int> lastVisitedCell(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        visited[0][0] = true;
        vector<int> ans = {0,0}; 
        while(1){
            char c = grid[ans[0]][ans[1]];
            if(!valid(ans,c,visited)){
                return ans;
            }    
        }            
        return ans;
    }
};