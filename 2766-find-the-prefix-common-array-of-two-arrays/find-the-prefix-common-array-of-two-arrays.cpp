class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        set<int> st;
        int count =0;
        vector<int> ans(n);
        for(int i=0;i<n;i++){
            if(st.find(A[i])!=st.end()) count++;
            if(st.find(B[i])!=st.end()) count++;
            if(A[i]==B[i]) count++;
            ans[i] = count;
            st.insert(A[i]);
            st.insert(B[i]);
        }
        return ans;
    }
};