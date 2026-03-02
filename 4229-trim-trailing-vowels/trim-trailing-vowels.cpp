class Solution {
public:
    bool isvowel(char c){
        string s = "aeiou";
        return (s.find(c)!= string::npos);
    }
    string trimTrailingVowels(string s) {
        string st = "";
        for(int i=s.size()-1;i>=0;i--){
            if(isvowel(s[i])) continue;
            else{
                st = s.substr(0,i+1);
                break;
            }
        }
        return st;
    }
};