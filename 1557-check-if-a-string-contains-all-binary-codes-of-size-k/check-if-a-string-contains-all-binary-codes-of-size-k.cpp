class Solution {
public:
    bool hasAllCodes(string s, int k) {
        set<string> st;
        int n = s.size();
        for(int i=0;i<n-k+1;i++){
            string str = s.substr(i,k);
            st.insert(str);
        }
        return st.size()==pow(2,k);
    }
};