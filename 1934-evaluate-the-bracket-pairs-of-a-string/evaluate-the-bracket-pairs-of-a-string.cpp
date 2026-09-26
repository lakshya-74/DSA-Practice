class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        map<string,string> mpp;
        for(auto x:knowledge){
            mpp[x[0]] = x[1];
        }
        string ans = "";
        int n = s.size();
        int i =0;
        while(i<n){
            if(s[i]=='('){
                int j = i+1;
                string str = "";
                while(j<n && s[j]!=')'){
                    str += s[j++];
                }
                if(mpp.find(str)!=mpp.end()){
                    ans += mpp[str];
                }
                else ans += '?';
                i = j+1;
            }
            else if(i<n){
                ans += s[i++];
            }
        }
        return ans;
    }
};