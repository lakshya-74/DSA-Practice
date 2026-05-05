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
    int numSimilarGroups(vector<string>& strs) {
        int n = strs.size();
        parent.resize(n);
        for(int i=0;i<n;i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(find(i)!=find(j)){
                    int diff = 0;
                    for(int k=0;k<strs[i].size();k++){
                        if(strs[i][k]!=strs[j][k]) diff++;
                        if(diff>2) break;
                    }
                    if(diff==0 || diff==2){
                        Union(i,j);
                    }
                }
            }
        }
        int count =0;
        for(int i=0;i<n;i++){
            if(find(i)==i) count++;
        }
        return count;
    }
};