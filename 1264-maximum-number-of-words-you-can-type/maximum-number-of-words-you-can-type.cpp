class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        int count =0;
        int m = brokenLetters.size();
        int n = text.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(text[i]==brokenLetters[j]){
                    text[i] = '0';
                } 
            }
        }
        vector<string> word;
        string s;
        for(int i=0;i<n;i++){
            if(text[i]!=' ') s += text[i];
            else{
                word.push_back(s);
                s = "";
            }
        }
        if(s.size()) word.push_back(s);
        for(int i=0;i<word.size();i++){
            bool flag = true;
            for(int j=0;j<word[i].size();j++){
                if(word[i][j]=='0'){
                    flag = false;
                    break;
                } 
            }
            if(flag) count++;
        }
        return count;
    }
};