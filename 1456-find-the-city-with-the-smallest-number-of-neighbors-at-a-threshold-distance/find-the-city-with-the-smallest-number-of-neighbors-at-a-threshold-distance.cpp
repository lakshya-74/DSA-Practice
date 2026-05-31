class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> dist(n,vector<int>(n,1e8));
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int w = edges[i][2];
            dist[u][v] = w;
            dist[v][u] = w;
        }
        for(int i=0;i<n;i++){
            dist[i][i] = 0;
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(dist[i][k]<1e8 && dist[k][j]<1e8){
                        dist[i][j] = min(dist[i][j],dist[i][k]+dist[k][j]);
                    }    
                }
            }
        }
        int mn = n+1;
        int city = -1;
        for(int i=0;i<n;i++){
            int count =0;
            for(int j=0;j<n;j++){
                if(dist[i][j]<=distanceThreshold) count++;
            }
            if(count<=mn){
                mn = count;
                city = i;
            }
        }
        return city;
    }
};