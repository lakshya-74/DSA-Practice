class Solution {
public:
    bool rec(int i,string& st){
        int n = st.size();
        if(i>=n/2) return true;
        if(st[i]!=st[n-i-1]) return false;
        return rec(i+1,st);
    }
    bool isPalindrome(string s) {
        string st ="";
        for(int i=0;i<s.size();i++){
            if(isalnum(s[i])){
                st += tolower(s[i]);
            }
        }
        return rec(0,st);
    }
};