class Solution {
public:
    bool isvowel(char c){
        return (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string sortVowels(string s) {
        string st;
        for(int i=0;i<s.size();i++){
            if(isvowel(s[i])){
                st+= s[i];
                s[i] = '0';
            }
        }
        sort(st.begin(),st.end());
        int t=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='0') s[i] = st[t++];
        }
        return s;
    }
};