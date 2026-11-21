class Solution {
public:
    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> child(n);
        for (int i = 1; i < n; i++) {
            child[parent[i]].push_back(i);
        }

        vector<int> last(26, -1);
        vector<int> v(n, -1);
        vector<int> sz(n, 1);

        stack<int> st;
        st.push(0);

        while (!st.empty()) {
            int x = st.top();
            st.pop();

            if(x>=0){
                int c = s[x] - 'a';
                v[x] = last[c];
                last[c] = x;
                st.push(-1*x -1);
                for (int ch : child[x]) {
                    st.push(ch);
                }
            }else{
                x = -1*x -1;
                int c = s[x] - 'a';
                last[c] = v[x];
                if(x!=0){
                    int newp = (v[x]!=-1)?v[x] : parent[x];
                    sz[newp] += sz[x];
                }
            }
        }
        return sz;
    }
};