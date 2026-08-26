class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.size();
        vector<pair<int,string>> v;
        for(int i=0;i<s.size();i++){
            string str = "";
            int count = 0;
            for(int j=i;j<n;j++){
                if(s[j]=='1') count++;
                str += s[j];
                if(count==k){
                    v.push_back({j-i+1,str});
                    break;
                }
            }
        }
        sort(v.begin(),v.end());
        if(!v.size()) return "";
        return v[0].second;
    }
};