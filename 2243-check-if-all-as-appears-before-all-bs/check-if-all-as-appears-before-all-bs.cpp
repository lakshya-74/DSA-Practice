class Solution {
public:
    bool checkString(string s) {
        bool b = false;
        for(int i=0;i<s.size();i++){
            if(s[i]=='a' && b) return false;
            if(s[i]=='b') b= true;
        }
        return true;
    }
};