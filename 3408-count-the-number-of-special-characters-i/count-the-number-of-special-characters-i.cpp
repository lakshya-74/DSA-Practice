class Solution {
public:
    int numberOfSpecialChars(string s) {
        int n = s.size();
        unordered_set<char> st;
        for(int i=0;i<n;i++){
            if(s[i]>=65 && s[i]<=90) st.insert(s[i]);
        }
        int ans =0;
        for(int i=0;i<n;i++){
            if(s[i]>=97 && s[i]<=122){
                if(st.count(toupper(s[i]))){
                    ans++;
                    st.erase(toupper(s[i]));
                }
            }
        }
        return ans;
    }
};