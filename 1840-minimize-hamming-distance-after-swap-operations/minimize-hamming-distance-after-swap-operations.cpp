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
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& p) {
        int n = source.size();
        int m = p.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<m;i++){
            int u = p[i][0];
            int v = p[i][1];
            if(find(u)!=find(v)){
                Union(u,v);
            }
        }
        map<int,vector<int>> component;
        for(int i=0;i<n;i++){
            int x = find(i);
            component[x].push_back(i);
        }
        int ans = 0;
        for(auto x:component){
            vector<int> idx = x.second;
            map<int,int> mpp;
            for(int i=0;i<idx.size();i++){
                mpp[source[idx[i]]]++;
            }
            for(int i=0;i<idx.size();i++){
                if(mpp[target[idx[i]]]>0){
                    mpp[target[idx[i]]]--;
                }
                else ans++;
            }
        }
        return ans;
    }
};