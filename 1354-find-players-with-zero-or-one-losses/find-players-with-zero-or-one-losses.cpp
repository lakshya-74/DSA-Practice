class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& mat) {
        int mx = -1;
        unordered_set<int> st;
        for(int i=0;i<mat.size();i++){
            mx = max({mx,mat[i][0],mat[i][1]});
            st.insert(mat[i][0]);
            st.insert(mat[i][1]);
        }
        vector<int> outdegree(mx+1,0);
        for(int i=0;i<mat.size();i++){
            int y = mat[i][1];
            outdegree[y]++;
        }
        vector<vector<int>> ans(2);
        for(int i=1;i<outdegree.size();i++){
            if(outdegree[i]==0 && st.count(i)) ans[0].push_back(i);
            else if(outdegree[i]==1 && st.count(i)) ans[1].push_back(i);
        }
        return ans;
    }
};