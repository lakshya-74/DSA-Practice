class Solution {
public:
    void rec(int i,string& st,string s,vector<string>& ans,vector<string>& v){
        if(i==s.size()){
            ans.push_back(st);
            return;
        }
        int val = (s[i]-'0')-2;
        for(int j=0;j<v[val].size();j++){
            st += v[val][j];
            rec(i+1,st,s,ans,v);
            st.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> v = {"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> ans;
        string st = "";
        rec(0,st,digits,ans,v);
        return ans;
    }
};