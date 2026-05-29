class Solution {
public:
    #define pp pair<int,pair<int,int>> 
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1) return -1;
        vector<pair<int,int>> move = {{0,1},{0,-1},{1,0},{-1,0},{1,1},{1,-1},{-1,1},{-1,-1}};
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        priority_queue<pp, vector<pp> , greater<pp>> pq;
        pq.push({0,{0,0}});
        dist[0][0] = 0;
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int d = curr.first;
            if(d==1e8) continue;
            int i = curr.second.first;
            int j = curr.second.second;
            for(auto x:move){
                int ni = i + x.first;
                int nj = j + x.second;
                if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==0){
                    if(d + 1 < dist[ni][nj]){
                        dist[ni][nj] = d+1;
                        pq.push({d+1,{ni,nj}});
                    }
                }
            }
        }
        int ans = dist[n-1][n-1];
        return ans==1e8?-1:ans+1;
    }
};