class Solution {
public:
    #define pp pair<int,int> 
    int nearestExit(vector<vector<char>>& maze, vector<int>& ent) {
        int n = maze.size();
        int m = maze[0].size();
        queue<pp> q;
        q.push({ent[0],ent[1]});
        int count =0;
        vector<pp> dir = {{1,0},{-1,0},{0,1},{0,-1}};
        vector<vector<int>> visited(n,vector<int>(m,0));
        visited[ent[0]][ent[1]] = 1;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int x = curr.first;
                int y = curr.second;
                if((x==0 || x==n-1 || y==0 || y==m-1) && (x!=ent[0] || y!=ent[1])) return count;
                for(auto k:dir){
                    int ni = x + k.first;
                    int nj = y + k.second;
                    if(ni>=0 && ni<n && nj>=0 && nj<m && maze[ni][nj]!='+' && !visited[ni][nj]){
                        q.push({ni,nj});
                        visited[ni][nj] = 1;
                    }
                }
            }
            count++;
        }
        return -1;
    }
};