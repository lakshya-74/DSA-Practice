class Solution {
public:
    int check(char s){
        if(s>='a' && s<='z') return 1;
        if(s>='A' && s<='Z') return 2;
        if(s>='0' && s<='9') return 3;
        return 5;
    }
    int passwordStrength(string s) {
        int n = s.size();
        set<char> st;
        for(int i=0;i<n;i++){
            st.insert(s[i]);
        }
        int ans = 0;
        for(auto x:st){
            ans += check(x);
        }
        return ans;
    }
};