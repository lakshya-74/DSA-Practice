class Solution {
public:
    vector<int> parent;
    int find(int x){
        if(parent[x]==x) return x;
        return parent[x] = find(parent[x]);
    }
    void Union(int a, int b){
        a = find(a);
        b = find(b);
        if(a!=b){
            parent[b] = a;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int mxr = 0 , mxc = 0;
        for(int i=0;i<n;i++){
            mxr = max(mxr,stones[i][0]);
            mxc = max(mxc,stones[i][1]);
        }
        set<int> st;
        parent.resize(mxr+mxc+2);
        for(int i=0;i<parent.size();i++){
            parent[i] = i;
        }
        for(int i=0;i<n;i++){
            int a= stones[i][0];
            int b = stones[i][1] + mxr + 1;
            Union(a,b);
            st.insert(a);
            st.insert(b);
        } 
        int count =0;
        for(auto x:st){
            if(find(x)==x) count++;
        }
        return n-count;
    }
};