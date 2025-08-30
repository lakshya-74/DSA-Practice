class Solution {
public:
    char findTheDifference(string s, string t) {
        map<char,int> mpp;
        
        for(int i=0;i<t.size();i++){
            mpp[t[i]]++;
        }
        for(int i=0;i<s.size();i++){
            mpp[s[i]]--;
        }
        for(auto x:mpp){
            if(x.second>0) return x.first;
        }
        return 'a';
    }
};