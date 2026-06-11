class Solution {
public:
    vector<int> size;
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a , int b){
        a = find(a);
        b = find(b);
        if(a==b) return;
        if(size[a]<size[b]){
            parent[a] = b;
            size[b] += size[a];
        }
        else{
            parent[b] = a;
            size[a] += size[b];
        }
    }
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        size.resize(n*n+1,1);
        parent.resize(n*n+1);
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,1,-1};
        for(int i=0;i<=n*n;i++) parent[i] = i;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==1){
                    int curr = i*n + j;
                    for(int k=0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1){
                            int next = ni*n + nj;
                            if(find(curr)!=find(next)){
                                Union(curr,next);
                            }
                        }
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j]==0){
                    int curr = i*n + j;
                    unordered_set<int> st;
                    for(int k=0;k<4;k++){
                        int ni = i + dx[k];
                        int nj = j + dy[k];
                        if(ni>=0 && ni<n && nj>=0 && nj<n && grid[ni][nj]==1){
                            int next = ni*n + nj;
                            int par = find(next);
                            st.insert(par);
                        }
                    }
                    int mx = 1;
                    for(auto x:st){
                        mx += size[x];
                    }
                    ans = max(ans,mx);
                }
            }
        }
        for(int i=0;i<=n*n;i++){
            if(parent[i]==i) ans = max(ans,size[i]);
        }
        return ans;
    }
};