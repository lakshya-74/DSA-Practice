class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(x==parent[x]) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        unordered_map<string,int> mpp;
        for(int i=0;i<n;i++){
            for(int j=1;j<accounts[i].size();j++){
                string s = accounts[i][j];
                if(mpp.find(s)==mpp.end()){
                    mpp[s] = i;
                }
                else{
                    Union(mpp[s],i);
                }
            }
        }
        vector<vector<string>> v(n);
        for(auto x:mpp){
            int a = find(x.second);
            v[a].push_back(x.first);
        }
        for(int i=0;i<v.size();i++){
            sort(v[i].begin(),v[i].end());
        }
        vector<vector<string>> ans;
        for(int i=0;i<v.size();i++){
            if(!v[i].empty()){
                v[i].insert(v[i].begin(),accounts[i][0]);
                ans.push_back(v[i]);
            }
        }
        return ans;
    }
};