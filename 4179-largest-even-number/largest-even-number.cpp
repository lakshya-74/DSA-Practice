class Solution {
public:
    string largestEven(string s) {
        int i = s.size()-1;
        while(i>0 && s[i]=='1'){
            s.erase(s.begin()+i);
            i--;
        }
        if(s=="1") return "";
        return s;
    }
};