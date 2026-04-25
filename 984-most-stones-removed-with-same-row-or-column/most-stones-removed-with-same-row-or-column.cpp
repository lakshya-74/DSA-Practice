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
            int b = stones[i][1] + mxr + 1; // for row and col i uses different nodes
            Union(a,b);
            st.insert(a);
            st.insert(b);
        } 
        int count =0; 
        // this count is used for efficient counting of no. of components
        for(auto x:st){
            if(find(x)==x) count++;
        }
        // ans = n- no. of componenets
        // logic -> from each there is one node that is not reachable so from each comp. our ans
        // is com. size -1 , and sum of all the comp. elemens is nothing but n and sub. occur no. of comp. times 
        return n-count;
    }
};