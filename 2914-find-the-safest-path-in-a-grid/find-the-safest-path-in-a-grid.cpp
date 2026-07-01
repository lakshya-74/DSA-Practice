class Solution {
public: 
    #define pp pair<int,int>
    #define ppp pair<int,pair<int,int>>
    vector<int> dx = {1,-1,0,0};
    vector<int> dy = {0,0,1,-1};
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0]==1 || grid[n-1][n-1]==1) return 0;
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        queue<pp> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    dist[i][j] = 0;
                }    
            }
        }
        int len = 0;
        while(!q.empty()){
            int sz = q.size();
            while(sz--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(int k=0;k<4;k++){
                    int ni = i + dx[k];
                    int nj = j + dy[k];
                    if(ni>=0 && ni<n && nj>=0 && nj<n && dist[ni][nj]==1e8){
                        dist[ni][nj] = len+1;
                        q.push({ni,nj});
                    }
                }
            }
            len++;
        }
        vector<vector<int>> v(n,vector<int>(n,-1));
        priority_queue<ppp> pq;
        v[0][0] = dist[0][0];
        pq.push({v[0][0],{0,0}});
        while(!pq.empty()){
            auto curr = pq.top();
            pq.pop();
            int x = curr.first;
            int i = curr.second.first;
            int j = curr.second.second;
            if(i==n-1 && j==n-1) return x;
            for(int k=0;k<4;k++){
                int ni = i + dx[k];
                int nj = j + dy[k];
                if(ni>=0 && ni<n && nj>=0 && nj<n){
                    int y = min(x,dist[ni][nj]);
                    if(y>v[ni][nj]){
                        v[ni][nj] = y;
                        pq.push({y,{ni,nj}});
                    }
                }
            }
        }
        return 0;
    }

};