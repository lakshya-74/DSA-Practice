class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a= find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        for(int i=0;i<n;i++) parent[i] = i;
        for(int i=0;i<edges.size();i++){
            int u = edges[i][0];
            int v = edges[i][1];
            if(find(u)!=find(v)){
                Union(u,v);
            }
        }
        unordered_map<int,int> nodes , edgc;
        for(int i=0;i<n;i++){
            nodes[find(i)]++;
        }
        for(int i=0;i<edges.size();i++){
            edgc[find(edges[i][0])]++;
        }
        int ans = 0;
        for(auto x:nodes){
            long long sz = x.second;
            long long c = sz*(sz-1)/2;
            if(c==edgc[x.first]) ans++;
        }
        return ans;
    }
};