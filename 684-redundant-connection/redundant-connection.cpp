class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        int x = find(a);
        int y = find(b);
        if(x!=y){
            parent[y] = x; 
        }
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        parent.resize(n+1);
        for(int i=1;i<n+1;i++){
            parent[i] = i;
        }
        int x,y;
        for(int i=0;i<n;i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u)!=find(v)){
                Union(u,v);
            }
            else{
                x = u;
                y = v;
            }
        }
        return {x,y};
    }
};