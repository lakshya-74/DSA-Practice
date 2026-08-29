class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a,int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(auto x:pairs){
            Union(x[0],x[1]);
        }
        map<int,vector<int>> mpp;
        for(int i=0;i<n;i++){
            mpp[find(i)].push_back(i);
        }
        for(auto x:mpp){
            string str = "";
            for(auto y:x.second){
                str += s[y];
            }
            sort(str.begin(),str.end());
            for(int i=0;i<x.second.size();i++){
                s[x.second[i]] = str[i];
            }
        }
        return s;
    }
};