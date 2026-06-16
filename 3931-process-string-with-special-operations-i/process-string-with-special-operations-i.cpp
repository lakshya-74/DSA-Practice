class Solution {
public:
    string processStr(string s) {
        string result;
        for(int i=0;i<s.size();i++){
            if(s[i]>96 && s[i]<123) result.push_back(s[i]);
            else if(s[i]=='#'){
                result = result.append(result);
            }
            else if(s[i]=='%') reverse(result.begin(),result.end());
            else if(s[i]=='*' && result.size()>0){
                // string str = result.substr(0, result.size()-1);
                // result = str;
                result.pop_back();
            }
        }
        return result;
    }
};