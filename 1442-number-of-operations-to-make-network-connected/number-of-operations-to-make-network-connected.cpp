class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a ,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        int sz = connections.size();
        if(sz<n-1) return -1;
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<sz;i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(find(u)!=find(v)) Union(u,v);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(parent[i]==i) ans++;
        }
        return ans-1;
    }
};