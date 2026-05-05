class Solution {
public:
    int find(vector<int>& parent ,int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent,parent[x]);
    }
    void Union(vector<int>& parent, int a ,int b){
        a = find(parent,a);
        b = find(parent,b);
        if(a!=b){
            parent[b] = a;
        }
    }
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        vector<int> parent1(n) , parent2(n);
        for(int i=0;i<n;i++){
            parent1[i] = parent2[i] = i;
        }
        int count =0;
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==3){
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;
                bool flag1 = false, flag2 = false;
                if(find(parent1,u)!=find(parent1,v)){
                    Union(parent1,u,v);
                    flag1 = true;
                }
                if(find(parent2,u)!=find(parent2,v)){
                    Union(parent2,u,v);
                    flag2 = true;
                }
                if(!flag1 && !flag2) count++;
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==1){
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;
                if(find(parent1,u)!=find(parent1,v)){
                    Union(parent1,u,v);
                }
                else{
                    count++;
                }
            }
        }
        for(int i=0;i<edges.size();i++){
            if(edges[i][0]==2){
                int u = edges[i][1]-1;
                int v = edges[i][2]-1;
                if(find(parent2,u)!=find(parent2,v)){
                    Union(parent2,u,v);
                }
                else{
                    count++;
                }
            }
        }
        int c1 = 0;
        int c2 = 0;
        for(int i=0;i<n;i++){
            if(find(parent1,i)==i) c1++;
            if(find(parent2,i)==i) c2++;
        }
        if(c1>1 || c2>1) return -1;
        return count;
    }
};