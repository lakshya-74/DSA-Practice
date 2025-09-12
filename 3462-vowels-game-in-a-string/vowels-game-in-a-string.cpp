class Solution {
public:
    bool isVowel(char c) {
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    }
    bool doesAliceWin(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if(isVowel(s[i])) st += s[i];
        }
        if(st.size()==0) return false;
        return true;
    }
};