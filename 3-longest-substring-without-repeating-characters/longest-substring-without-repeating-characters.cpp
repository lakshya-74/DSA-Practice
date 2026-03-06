class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans = 0;
        int n = s.size();
        if(n==1) return 1;
        unordered_set<char> st;
        int l = 0 , r = 0;
        while(r<n){
            while(st.count(s[r])){
                st.erase(s[l]);
                l++;
            }
            st.insert(s[r]);
            ans = max(ans,r-l+1);
            r++;
        }
        return ans;
    }
};